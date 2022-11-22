//
// Created by zhoubing on 2017/6/12.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "class.h"
#include "access_flag.h"
#include "attribute_info.h"
#include "constant_pool.h"

VM_Class *gClass;

const char *java_ver[] = {
        "1.1",
        "1.2",
        "1.3",
        "1.4",
        "5.0",
        "6",
        "7",
        "8",
        "9",
        "10",
        "11",
};

int verify_magic_number(VM_Class *class) {
    uint8_t ca = vm_read_8bit(class->bytecode_reader);
    uint8_t fe = vm_read_8bit(class->bytecode_reader);
    uint8_t ba = vm_read_8bit(class->bytecode_reader);
    uint8_t be = vm_read_8bit(class->bytecode_reader);
    return ca == 0xca && fe == 0xfe && ba == 0xba && be == 0xbe ? 0 : -1;
}

int verify_class_version(VM_Class *class) {
    uint16_t minor_ver = vm_read_16bit(class->bytecode_reader);
    uint16_t major_ver = vm_read_16bit(class->bytecode_reader);
    class->version.major_version = major_ver;
    class->version.minor_version = minor_ver;
    int ver = major_ver - 45;
    printf("minor version: %d\n", minor_ver);
    printf("major version: %d\n", major_ver);
    if (ver < 0 || ver > sizeof(java_ver) / sizeof(char *)) {
        return -1;
    }
    return 0;
}

void log_access_flag(uint16_t class_access_flag) {
    if ((class_access_flag & ACC_PUBLIC) == ACC_PUBLIC) {
        log ("ACC_PUBLIC");
    }

    if ((class_access_flag & ACC_FINAL) == ACC_FINAL) {
        log ("ACC_FINAL");
    }

    if ((class_access_flag & ACC_SUPER) == ACC_SUPER) {
        log ("ACC_SUPER");
    }

    if ((class_access_flag & ACC_INTERFACE) == ACC_INTERFACE) {
        log ("ACC_INTERFACE");
    }

    if ((class_access_flag & ACC_ABSTRACT) == ACC_ABSTRACT) {
        log ("ACC_ABSTRACT");
    }

    if ((class_access_flag & ACC_SYNTHETIC) == ACC_SYNTHETIC) {
        log ("ACC_SYNTHETIC");
    }

    if ((class_access_flag & ACC_ANNOTATION) == ACC_ANNOTATION) {
        log ("ACC_ANNOTATION");
    }

    if ((class_access_flag & ACC_ENUM) == ACC_ENUM) {
        log ("ACC_ENUM");
    }
}

int VmClass_IsMain(VM_Method *method, VM_Class *class) {
    uint16_t method_index = method->name_index;
    uint16_t param_index = method->descriptor_index;
    ConstantUtf8 *main_str = (ConstantUtf8 *) class->constant_pool->constant_info_arr[method_index];
    ConstantUtf8 *param_str = (ConstantUtf8 *) class->constant_pool->constant_info_arr[param_index];
    int size = strlen("([Ljava/lang/String;)V");
    return strncmp(main_str->str, "main", 4) == 0 && strncmp(param_str->str, "([Ljava/lang/String;)V", size) == 0 ? 0
                                                                                                                  : -1;
}

int VmClass_LoadByteCode(VM_Class *class, char *buffer, long buffer_size) {
    class->bytecode_reader = new_bytecode_reader(buffer, buffer_size);

    if (verify_magic_number(class) != 0) {
        log ("verify magic number failed!");
        exit(-1);
    }
    if (verify_class_version(class) != 0) {
        log ("verify class version failed!");
        exit(-1);
    }
    uint16_t constant_pool_item_count = vm_read_16bit(class->bytecode_reader);
    printf("constant pool count: %d\n", constant_pool_item_count);
    struct constant_pool *pool = new_constant_pool(class, constant_pool_item_count);
    class->constant_pool = pool;

    /*类访问标志*/
    class->class_access_flag = vm_read_16bit(class->bytecode_reader);
    log_access_flag(class->class_access_flag);

    class->this_class_index = vm_read_16bit(class->bytecode_reader);
    class->super_class_index = vm_read_16bit(class->bytecode_reader);
    printf("this_class: %d\n", class->this_class_index);
    printf("super_class: %d\n", class->super_class_index);

    class->interface_count = vm_read_16bit(class->bytecode_reader);
    class->interfaces = malloc_x (sizeof(Interface) * class->interface_count);
    for (int i = 0; i < class->interface_count; i++) {
        class->interfaces[i].tag = vm_read_16bit(class->bytecode_reader);
    }
    printf("interfaces: %d\n", class->interface_count);
    class->field_count = vm_read_16bit(class->bytecode_reader);
    class->fields = malloc_x (sizeof(Vm_Field) * class->field_count);
    log_file_function_line();
    for (int i = 0; i < class->field_count; i++) {
        class->fields[i].access_flag = vm_read_16bit(class->bytecode_reader);
        log_access_flag(class->fields[i].access_flag);
        class->fields[i].name_index = vm_read_16bit(class->bytecode_reader);
        ConstantUtf8 *constantUtf8 = (ConstantUtf8 *) class->constant_pool->constant_info_arr[class->fields[i].name_index];
        class->fields[i].descriptor_index = vm_read_16bit(class->bytecode_reader);

        class->fields[i].attributes_count = vm_read_16bit(class->bytecode_reader);
        class->fields[i].attributes = malloc_x (sizeof(AttributeBase *) * class->fields[i].attributes_count);
        log_file_function_line();
        for (int j = 0; j < class->fields[i].attributes_count; j++) {
            new_attribute(class);
        }
        log_file_function_line();
    }
    printf("fields: %d\n", class->field_count);
    class->method_count = vm_read_16bit(class->bytecode_reader);
    class->methods = malloc_x (sizeof(VM_Method) * class->method_count);
    printf("methods: %d\n", class->method_count);

    for (int i = 0; i < class->method_count; i++) {
        class->methods[i].access_flag = vm_read_16bit(class->bytecode_reader);
        log_access_flag(class->methods[i].access_flag);
        class->methods[i].name_index = vm_read_16bit(class->bytecode_reader);
        printf("method name index: %d\n", class->methods[i].name_index);

        ConstantUtf8 *constantUtf8 = (ConstantUtf8 *) (class->constant_pool->constant_info_arr[class->methods[i].name_index]);
        char *s = malloc(constantUtf8->length + 1);
        memset(s, 0x00, constantUtf8->length + 1);
        memcpy(s, constantUtf8->str, constantUtf8->length);
        printf("utf8 is %s\n", s);

        class->methods[i].descriptor_index = vm_read_16bit(class->bytecode_reader);
        printf("method descriptor_index: %d\n", class->methods[i].descriptor_index);

        ConstantUtf8 *descriptor = (ConstantUtf8 *) class->constant_pool->constant_info_arr[class->methods[i].descriptor_index];

        char *s1 = malloc(descriptor->length + 1);
        memset(s1, 0x00, descriptor->length + 1);
        memcpy(s1, descriptor->str, descriptor->length);
        printf("utf8 is %s\n", s1);

        class->methods[i].attributes_count = vm_read_16bit(class->bytecode_reader);
        class->methods[i].attributes = malloc_x (sizeof(AttributeBase *) * class->methods[i].attributes_count);
        for (int j = 0; j < class->methods[i].attributes_count; j++) {
            AttributeBase *attributeBase = new_attribute(class);
            class->methods[i].attributes[j] = attributeBase;
        }
    }
    uint16_t attributes_count = vm_read_16bit(class->bytecode_reader);
    for (int i = 0; i < attributes_count; i++) {
        new_attribute(class);
    }
    printf("interfaces: %d, fields: %d, methods: %d, attributes: %d\n", class->interface_count, class->field_count,
           class->method_count, attributes_count);

}

VM_Method *VmClass_GetMain(VM_Class *klass) {
    for (int i = 0; i < klass->method_count; i++) {
        VM_Method m = klass->methods[i];
        if (VmClass_IsMain(&m, klass) == 0) {
            return &klass->methods[i];
        }
    }
    return 0;
}

VM_Class *VmClass_New() {
    VM_Class *class = malloc_x (sizeof(VM_Class));
    memset(class, 0x00, sizeof(VM_Class));
    return class;
}