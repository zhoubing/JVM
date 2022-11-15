//
// Created by zhoubing on 2017/6/10.
//

#ifndef UNTITLED2_ATTRIBUTES_INFO_H
#define UNTITLED2_ATTRIBUTES_INFO_H

#include "bytecode_reader.h"
#include "class.h"

typedef struct attribute_base AttributeBase;
typedef struct source_file SourceFile;
typedef struct signature Signature;
typedef struct constant_value ConstantValue;
typedef struct code Code;
typedef struct stack_map_table StackMapTable;
typedef struct exceptions Exceptions;
typedef struct inner_classes InnerClasses;
typedef struct inclosing_method EnclosingMethod;
typedef struct synthetic Synthetic;
typedef struct source_debug_extension SourceDebugExtension;
typedef struct line_number_table LineNumberTable;
typedef struct local_variable_table LocalVariableTable;
typedef struct local_variable_type_table LocalVariableTypeTable;
typedef struct deprecated Deprecated;
typedef struct runtime_visible_annotations RuntimeVisibleAnnotations;
typedef struct runtime_invisible_annotations RuntimeInvisibleAnnotations;
typedef struct runtime_visible_parameter_annotations RuntimeVisibleParameterAnnotations;
typedef struct runtime_invisible_parameter_annotations RuntimeInvisibleParameterAnnotations;
typedef struct annotations_default AnnotationDefault;
typedef struct bootstrap_methods BootstrapMethods;
typedef struct exception Exception;

/*属性*/
struct attribute_base {
    uint16_t attribute_name_index;
    uint32_t attribute_length;
//    void (*read_info)(AttributeBase *attribute);
};

struct source_file {
    AttributeBase base;
    uint16_t sourcefile_index;
};

struct signature {
    AttributeBase base;
    uint16_t signature_index;
};

struct constant_value {
    AttributeBase base;

};

struct code {
    AttributeBase base;
    uint16_t max_stack;
    uint16_t max_locals;
    uint32_t code_length;
    uint8_t *code;
    uint16_t exception_table_length;
    Exception *exception_table;
    uint16_t attributes_count;
    AttributeBase **attributes;
};

struct stack_map_table {
    AttributeBase base;
    uint16_t number_of_entries;

};

struct exceptions {
    AttributeBase base;

};

struct inner_classes {
    AttributeBase base;

};

struct enclosing_method {
    AttributeBase base;

};

struct synthetic {
    AttributeBase base;

};

struct source_debug_extensions {
    AttributeBase base;

};

struct line_number_table_item {
    uint16_t start_pc;
    uint16_t line_number;
};

struct line_number_table {
    AttributeBase base;
    uint16_t line_number_table_length;
    struct line_number_table_item *table_item;
};

struct local_variable_table_item {
    uint16_t start_pc;
    uint16_t length;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t index;
};

struct local_variable_table {
    AttributeBase base;
    uint16_t local_variable_table_length;
    struct local_variable_table_item *table_item
};

struct local_variable_type_table {
    AttributeBase base;

};

struct deprecated {
    AttributeBase base;

};

struct runtime_visible_annotaions {
    AttributeBase base;

};

struct runtime_invisible_annotations {
    AttributeBase base;

};

struct runtime_visible_parameter_annotations {
    AttributeBase base;

};

struct runtime_invisible_parameter_annotations {
    AttributeBase base;

};

struct annotation_default {
    AttributeBase base;

};

struct bootstrap_methods {
    AttributeBase base;

};

struct exception {
    uint16_t start_pc;
    uint16_t end_pc;
    uint16_t handler_pc;
    uint16_t catch_type;
};

AttributeBase *new_attribute(struct vm_class *klass);

#endif //UNTITLED2_ATTRIBUTES_INFO_H
