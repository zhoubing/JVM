//
// Created by zhoubing on 2017/6/9.
//

#include <memory.h>
#include <stdlib.h>
#include "constant_pool.h"
#include "utility.h"

const ConstantInfo *handle_noop(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_utf8(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_integer(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_float(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_long(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_double(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_class(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_string(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_field_ref(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_method_ref(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_interface_method_ref(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_name_and_type(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_method_handle(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_method_type(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *handle_invoke_dynamic(ByteCodeReader *reader, uint8_t tag);

const ConstantInfo *(*constant_info_handler[])(ByteCodeReader *reader, uint8_t tag) = {
        handle_noop,
        handle_utf8,
        handle_noop,
        handle_integer,
        handle_float,
        handle_long,
        handle_double,
        handle_class,
        handle_string,
        handle_field_ref,
        handle_method_ref,
        handle_interface_method_ref,
        handle_name_and_type,
        handle_noop,
        handle_noop,
        handle_method_handle,
        handle_method_type,
        handle_noop,
        handle_invoke_dynamic,
};

const ConstantInfo *handle_invoke_dynamic(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    InvokeDynamicInfo *info = (InvokeDynamicInfo *) malloc(sizeof(InvokeDynamicInfo));
    info->bootstrap_method_attr_index = reader->read_16bit(reader);
    info->name_and_type_index = reader->read_16bit(reader);
    return (const ConstantInfo *) info;
}

const ConstantInfo *handle_method_type(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantMethodType *info = (ConstantMethodType *) malloc(sizeof(ConstantMethodType));
    info->desc_type = reader->read_16bit(reader);
    return (const ConstantInfo *) info;
}

const ConstantInfo *handle_method_handle(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantMethodHandle *info = (ConstantMethodHandle *) malloc(sizeof(ConstantMethodHandle));
    info->reference_kind = reader->read_8bit(reader);
    info->reference_index = reader->read_16bit(reader);
    return (const ConstantInfo *) info;
}

const ConstantInfo *handle_name_and_type(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantNameAndType *info = (ConstantNameAndType *) malloc(sizeof(ConstantNameAndType));
    info->nameIndex = reader->read_16bit(reader);
    info->descIndex = reader->read_16bit(reader);
    return (const ConstantInfo *) info;
}

const ConstantInfo *handle_noop(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
}

uint8_t *decode_modified_utf8(const uint8_t *str, uint16_t len) {
    uint8_t *decoded_utf8 = (uint8_t *) malloc(sizeof(uint8_t) * len);
    memset(decoded_utf8, 0x00, len);
    int i = 0;
    for (i = 0; i < len; i++) {
        uint8_t c = *(str + i);
        int type = (c & 0xff) >> 5;
        if (type < 4) { /*普通字节*/
            decoded_utf8[i] = (uint8_t) (c & 0xff);
        } else if (type == 6) { /*二字节*/
            uint8_t c1 = *(str + i + 1);
            uint16_t val = 0;
            val |= (c & 0x1f << 6);
            val |= (c1 & 0x3f);
            memcpy(decoded_utf8, &val, sizeof(uint16_t));
            i += 1;
        } else if (type == 7) {/*三字节*/
            uint32_t val = 0;
            val |= c & 0x0f << 12;
            val |= c & 0x3f << 6;
            val |= c & 0x0f << 12;
            memcpy(decoded_utf8, &val, sizeof(uint8_t) * 3);
            i += 2;
        } else {
            /*处理补充字符*/
        }
    }
    return decoded_utf8;
}

const ConstantInfo *handle_utf8(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    uint16_t len = reader->read_16bit(reader);
    ConstantUtf8 *integer_info = (ConstantUtf8 *) malloc(sizeof(ConstantUtf8));
    const uint8_t *str = reader->read_bytes(reader, len);
    integer_info->info.tag = tag;
    integer_info->length = len;
    integer_info->str = decode_modified_utf8(str, len);
    log(integer_info->str);
    return (const ConstantInfo *) integer_info;
}

const ConstantInfo *handle_integer(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantIntegerInfo *integer_info = (ConstantIntegerInfo *) malloc(sizeof(ConstantIntegerInfo));
    integer_info->info.tag = tag;
    integer_info->value = reader->read_32bit(reader);
    return (const ConstantInfo *) integer_info;
}

const ConstantInfo *handle_float(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantFloatInfo *float_info = (ConstantFloatInfo *) malloc(sizeof(ConstantFloatInfo));
    float_info->info.tag = tag;
    float_info->value = reader->read_32bit(reader);
    return (const ConstantInfo *) float_info;
}

const ConstantInfo *handle_long(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantLongInfo *long_info = (ConstantLongInfo *) malloc(sizeof(ConstantLongInfo));
    long_info->info.tag = tag;
    long_info->high_value = reader->read_32bit(reader);
    long_info->low_value = reader->read_32bit(reader);
    return (const ConstantInfo *) long_info;
}

const ConstantInfo *handle_double(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantDoubleInfo *double_info = (ConstantDoubleInfo *) malloc(sizeof(ConstantDoubleInfo));
    double_info->info.tag = tag;
    double_info->high_value = reader->read_32bit(reader);
    double_info->low_value = reader->read_32bit(reader);
    return (const ConstantInfo *) double_info;
}

const ConstantInfo *handle_class(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantClassInfo *class_info = (ConstantClassInfo *) malloc(sizeof(ConstantClassInfo));
    class_info->info.tag = tag;
    class_info->name_index = reader->read_16bit(reader);
    return (const ConstantInfo *) class_info;
}

const ConstantInfo *handle_string(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantString *string_info = (ConstantString *) malloc(sizeof(ConstantString));
    string_info->info.tag = tag;
    string_info->name_index = reader->read_16bit(reader);
    return (const ConstantInfo *) string_info;
}

const ConstantInfo *handle_field_ref(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantMethodRefInfo *ref_info = (ConstantMethodRefInfo *) malloc(sizeof(ConstantMethodRefInfo));
    ref_info->info.tag = tag;
    ref_info->class_index = reader->read_16bit(reader);
    ref_info->name_and_type_index = reader->read_16bit(reader);
    printf("class_index: %d\n", ref_info->class_index);
    printf("name_and_type_index: %d\n", ref_info->name_and_type_index);
    return (const ConstantInfo *) ref_info;
}

const ConstantInfo *handle_method_ref(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantMethodRefInfo *ref_info = (ConstantMethodRefInfo *) malloc(sizeof(ConstantMethodRefInfo));
    ref_info->info.tag = tag;
    ref_info->class_index = reader->read_16bit(reader);
    ref_info->name_and_type_index = reader->read_16bit(reader);
    printf("class_index: %d\n", ref_info->class_index);
    printf("name_and_type_index: %d\n", ref_info->name_and_type_index);
    return (const ConstantInfo *) ref_info;
}

const ConstantInfo *handle_interface_method_ref(ByteCodeReader *reader, uint8_t tag) {
    log_file_function_line();
    ConstantMethodRefInfo *ref_info = (ConstantMethodRefInfo *) malloc(sizeof(ConstantMethodRefInfo));
    ref_info->info.tag = tag;
    ref_info->class_index = reader->read_16bit(reader);
    ref_info->name_and_type_index = reader->read_16bit(reader);
    printf("class_index: %d", ref_info->class_index);
    printf("name_and_type_index: %d", ref_info->name_and_type_index);
    return (const ConstantInfo *) ref_info;
}

ConstantPool *new_constant_pool(Klass *class, uint16_t pool_size) {
    ConstantPool *pool = malloc(sizeof(ConstantPool));
    pool->pool_size = pool_size;
    pool->constant_info_arr = malloc(sizeof(struct constant_info) * pool_size);
    for (int i = 1; i < pool_size; i++) {
        uint8_t tag = class->bytecode_reader->read_8bit(class->bytecode_reader);
        if (tag < 0 || tag > ARRAY_SIZE(constant_info_handler)) {
            continue;
        }
        pool->constant_info_arr[i] = constant_info_handler[tag](class->bytecode_reader, tag);
    }
    return pool;
}
