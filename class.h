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
#include "stdint.h"

extern struct vm_class *gClass;

typedef struct interface Interface;
typedef struct attribute_base AttributeBase;

struct vm_class *vm_class_new ();

struct compiler_version {
    uint16_t major_version;
    uint16_t minor_version;
};

struct vm_class {
    struct vm_bytecode_reader *bytecode_reader;
    struct compiler_version version;
    struct constant_pool *constant_pool;

    uint16_t class_access_flag;
    uint16_t this_class_index;
    uint16_t super_class_index;

    uint16_t interface_count;
    Interface *interfaces;

    uint16_t field_count;
    struct vm_field *fields;

    uint16_t method_count;
    struct vm_method *methods;

    struct vm_method *(*get_main) (struct vm_class *);
};

struct interface {
    uint16_t tag;

//    ConstantUtf8 *(*get_name)(Klass *class);
};

struct vm_field {
    uint16_t access_flag;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeBase **attributes;
};

struct vm_method {
    uint16_t access_flag;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeBase **attributes;
    int (*is_main) (struct vm_method *, struct vm_class *);
};

int vm_class_load_bytecode (struct vm_class *, char *, long);

#endif //UNTITLED2_CLASS_H
