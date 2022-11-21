//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_CLASS_H
#define UNTITLED2_CLASS_H

#include <memory.h>
#include "bytecode_reader.h"
#include "utility.h"
#include "stdint.h"
#include "attribute_info.h"

typedef struct interface Interface;

struct constant_pool;

struct compiler_version {
    uint16_t major_version;
    uint16_t minor_version;
};

typedef struct {
    uint16_t access_flag;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeBase **attributes;
    struct _VM_Class *klass;
} VM_Method;

typedef struct {
    uint16_t access_flag;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    AttributeBase **attributes;
    struct _VM_Class *klass;
} Vm_Field;

typedef struct _VM_Class {
    struct vm_bytecode_reader *bytecode_reader;
    struct compiler_version version;
    struct constant_pool *constant_pool;

    uint16_t class_access_flag;
    uint16_t this_class_index;
    uint16_t super_class_index;

    uint16_t interface_count;
    Interface *interfaces;

    uint16_t field_count;
    Vm_Field *fields;

    uint16_t method_count;
    VM_Method *methods;
} VM_Class;


VM_Class *VmClass_New();

int VmClass_LoadByteCode(VM_Class *, char *, long);

int VmClass_IsMain(VM_Method *, VM_Class *);

VM_Method *VmClass_GetMain(VM_Class *);

struct interface {
    uint16_t tag;

//    ConstantUtf8 *(*get_name)(Klass *class);
};

#endif //UNTITLED2_CLASS_H
