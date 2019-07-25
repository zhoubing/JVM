//
// Created by zhoubing on 2017/6/12.
//
#include <stdlib.h>
#include "class.h"
#include "access_flag.h"
#include "attribute_info.h"

const char *java_ver[] = {
        "1.1",
        "1.2",
        "1.3",
        "1.4",
        "5.0",
        "6",
        "7",
        "8",
        "9"
};

int verify_magic_number(Klass *class) {
    uint8_t ca = class->bytecode_reader->read_8bit(class->bytecode_reader);
    uint8_t fe = class->bytecode_reader->read_8bit(class->bytecode_reader);
    uint8_t ba = class->bytecode_reader->read_8bit(class->bytecode_reader);
    uint8_t be = class->bytecode_reader->read_8bit(class->bytecode_reader);
    return ca == 0xca && fe == 0xfe && ba == 0xba && be == 0xbe ? 0 : -1;
}

int verify_class_version(Klass *class) {
    uint16_t minor_ver = class->bytecode_reader->read_16bit(class->bytecode_reader);
    uint16_t major_ver = class->bytecode_reader->read_16bit(class->bytecode_reader);
    class->version.major_version = major_ver;
    class->version.minor_version = minor_ver;
    int ver = major_ver - 45;
    if (ver < 0 || ver > sizeof(java_ver) / sizeof(char *)) {
        return -1;
    }
    return 0;
}

void log_access_flag(uint16_t class_access_flag) {
    if ((class_access_flag & ACC_PUBLIC) == ACC_PUBLIC) {
        log("public");
    }

    if ((class_access_flag & ACC_FINAL) == ACC_FINAL) {
        log("final");
    }

    if ((class_access_flag & ACC_SUPER) == ACC_SUPER) {
        log("super");
    }

    if ((class_access_flag & ACC_INTERFACE) == ACC_INTERFACE) {
        log("interface");
    }

    if ((class_access_flag & ACC_ABSTRACT) == ACC_ABSTRACT) {
        log("abstract");
    }

    if ((class_access_flag & ACC_SYNTHETIC) == ACC_SYNTHETIC) {
        log("synthetic");
    }

    if ((class_access_flag & ACC_ANNOTATION) == ACC_ANNOTATION) {
        log("annotation");
    }

    if ((class_access_flag & ACC_ENUM) == ACC_ENUM) {
        log("enum");
    }
}

int is_main(Method *method, Klass *class) {
    uint16_t method_index = method->name_index;
    uint16_t param_index = method->descriptor_index;
    ConstantUtf8 *main_str = (ConstantUtf8 *) class->constant_pool->constant_info_arr[method_index];
    ConstantUtf8 *param_str = (ConstantUtf8 *) class->constant_pool->constant_info_arr[param_index];
    return strcmp(main_str->str, "main") == 0 && strcmp(param_str->str, "([Ljava/lang/String;)V") == 0 ? 0 : -1;
}

int load_bytecode(Klass *class, char *buffer, int buffer_size) {
    class->bytecode_reader = new_bytecode_reader(buffer, buffer_size);

    if (verify_magic_number(class) != 0) {
        printf("verify magic number failed!");
        exit(-1);
    }

    if (verify_class_version(class) != 0) {
        printf("verify class version failed!");
        exit(-1);
    }

    uint16_t constant_pool_item_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
    ConstantPool *pool = new_constant_pool(class, constant_pool_item_count);
    class->constant_pool = pool;

    /*类访问标志*/
    class->class_access_flag = class->bytecode_reader->read_16bit(class->bytecode_reader);
    log_access_flag(class->class_access_flag);

    class->this_class_index = class->bytecode_reader->read_16bit(class->bytecode_reader);
    class->super_class_index = class->bytecode_reader->read_16bit(class->bytecode_reader);

    class->interface_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
    class->interfaces = malloc(sizeof(Interface) * class->interface_count);
    for (int i = 0; i < class->interface_count; i++) {
        class->interfaces[i].tag = class->bytecode_reader->read_16bit(class->bytecode_reader);
    }

    class->field_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
    class->fields = malloc(sizeof(Field) * class->field_count);
    for (int i = 0; i < class->field_count; i++) {
        class->fields[i].access_flag = class->bytecode_reader->read_16bit(class->bytecode_reader);
        log_access_flag(class->fields[i].access_flag);
        class->fields[i].name_index = class->bytecode_reader->read_16bit(class->bytecode_reader);
        ConstantUtf8 *constantUtf8 = (ConstantUtf8 *) class->constant_pool->constant_info_arr[class->fields[i].name_index];
        class->fields[i].descriptor_index = class->bytecode_reader->read_16bit(class->bytecode_reader);
        class->fields[i].attributes_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
        class->fields[i].attributes = malloc(sizeof(AttributeBase *) * class->fields[i].attributes_count);
        for (int j = 0; j < class->fields[i].attributes_count; j++) {
            new_attribute(class);
        }
    }

    printf("---------AAA---------");


    class->method_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
    class->methods = malloc(sizeof(Method) * class->method_count);
    for (int i = 0; i < class->method_count; i++) {
        class->methods[i].access_flag = class->bytecode_reader->read_16bit(class->bytecode_reader);
        log_access_flag(class->methods[i].access_flag);
        class->methods[i].name_index = class->bytecode_reader->read_16bit(class->bytecode_reader);
        ConstantUtf8 *constantUtf8 = (ConstantUtf8 *) class->constant_pool->constant_info_arr[class->methods[i].name_index];
        class->methods[i].descriptor_index = class->bytecode_reader->read_16bit(class->bytecode_reader);
        class->methods[i].attributes_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
        class->methods[i].attributes = malloc(sizeof(AttributeBase *) * class->methods[i].attributes_count);
        class->methods[i].is_main = is_main;
        for (int j = 0; j < class->methods[i].attributes_count; j++) {
            AttributeBase *attributeBase = new_attribute(class);
            class->methods[i].attributes[j] = attributeBase;
        }
    }
    uint16_t attributes_count = class->bytecode_reader->read_16bit(class->bytecode_reader);
    for (int i = 0; i < attributes_count; i++) {
        new_attribute(class);
    }
}

Method *get_main(Klass *klass) {
    for (int i = 0; i < klass->method_count; i++) {
        Method m = klass->methods[i];
        if (m.is_main(&m, klass) == 0) {
            return &klass->methods[i];
        }
    }
    return 0;
}

Klass *new_instance() {
    Klass *class = malloc(sizeof(Klass));
    class->load_bytecode = load_bytecode;
    class->get_main = get_main;
    return class;
}