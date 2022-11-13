//
// Created by zhoubing on 2017/6/9.
//

#ifndef UNTITLED2_CONSTANT_POOL_H
#define UNTITLED2_CONSTANT_POOL_H

#include "bytecode_reader.h"
#include "class.h"

typedef struct constant_info ConstantInfo;

typedef struct constant_method_ref_info ConstantMethodRefInfo;

typedef struct constant_double_info ConstantDoubleInfo;

typedef struct constant_long_info ConstantLongInfo;

typedef struct constant_float_info ConstantFloatInfo;

typedef struct constant_integer_info ConstantIntegerInfo;

typedef struct constant_class_info ConstantClassInfo;

typedef struct invoke_dynamic_info InvokeDynamicInfo;

typedef struct constant_string ConstantString;

typedef struct constant_name_and_type ConstantNameAndType;

typedef struct constant_method_handle ConstantMethodHandle;

typedef struct constant_method_type ConstantMethodType;

typedef struct constant_utf8 ConstantUtf8;

struct constant_pool {
    uint16_t pool_size;
    ConstantInfo **constant_info_arr;
    ConstantInfo *(*create_constant_info)(struct vm_bytecode_reader *byte_code_reader, uint8_t tag);
};

struct constant_pool *new_constant_pool(struct vm_class *class, uint16_t pool_size);

struct constant_info {
    uint8_t tag;
};

struct constant_method_ref_info {
    ConstantInfo info;
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct constant_double_info {
    ConstantInfo info;
    uint32_t high_value;
    uint32_t low_value;
};

struct constant_long_info {
    ConstantInfo info;
    uint32_t high_value;
    uint32_t low_value;
};

struct constant_float_info {
    ConstantInfo info;
    uint32_t value;
};

struct constant_integer_info {
    ConstantInfo info;
    uint32_t value;
};

struct constant_class_info {
    ConstantInfo info;
    uint16_t name_index;
};

struct invoke_dynamic_info {
    ConstantInfo info;
    uint16_t bootstrap_method_attr_index;
    uint16_t name_and_type_index;
};

struct constant_string {
    ConstantInfo info;
    uint16_t name_index;
};

struct constant_name_and_type {
    ConstantInfo info;
    uint16_t nameIndex;
    uint16_t descIndex;
};

struct constant_method_handle {
    ConstantInfo info;
    uint8_t reference_kind;
    uint16_t reference_index;
};

struct constant_method_type {
    ConstantInfo info;
    uint16_t desc_type;
};

struct constant_utf8 {
    ConstantInfo info;
    uint16_t length;
    uint8_t *str;
    uint16_t str_len;
};

//enum {
//    Utf8 = 1,
//    Integer = 3,
//    Float = 4,
//    Long = 5,
//    Double = 6,
//    Class = 7,
//    String = 8,
//    FieldRef = 9,
//    MethodRef = 10,
//    InterfaceMethodRef = 11,
//    NameAndType = 12,
//    MethodHandle = 15,
//    MethodType = 16,
//    InvokeDynamic = 18
//} constant;

#endif //UNTITLED2_CONSTANT_POOL_H
