//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_CLASS_H
#define UNTITLED2_CLASS_H

#include <memory.h>
#include "bytecode_reader.h"
#include "constant_pool.h"
#include "utility.h"
#include "attribute_info.h"

typedef struct klass Klass;
typedef struct interface Interface;
typedef struct compiler_version CompilerVersion;
typedef struct field Field;
typedef struct method Method;
typedef struct constant_pool ConstantPool;
typedef struct attribute_base AttributeBase;

Klass *new_instance();

struct compiler_version {
    uint16_t major_version;
    uint16_t minor_version;
};

struct klass {
    ByteCodeReader *bytecode_reader;
    CompilerVersion version;
    ConstantPool *constant_pool;

    uint16_t class_access_flag;
    uint16_t this_class_index;
    uint16_t super_class_index;

    uint16_t interface_count;
    Interface *interfaces;

    uint16_t field_count;
    Field *fields;

    uint16_t method_count;
    Method *methods;

    int (*load_bytecode)(Klass *, char *, int);

    Method *(*get_main)(Klass *);
};

struct interface {
    uint16_t tag;

//    ConstantUtf8 *(*get_name)(Klass *class);
};

struct field {
    uint16_t access_flag;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeBase **attributes;
};

struct method {
    uint16_t access_flag;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeBase **attributes;
    int (*is_main)(Method *, Klass *);
};

#endif //UNTITLED2_CLASS_H
