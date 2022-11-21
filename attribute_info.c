//
// Created by zhoubing on 2017/6/10.
//

#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include <string.h>
#include "utility.h"
#include "attribute_info.h"
#include "constant_pool.h"

AttributeBase *new_attribute(VM_Class *klass) {
    log_file_function_line();
    //https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.7
//    AttributeBase *attributeBase = (AttributeBase *) malloc_x (sizeof(AttributeBase));
    uint16_t attribute_name_index = vm_read_16bit(klass->bytecode_reader);
    uint32_t attribute_length = vm_read_32bit(klass->bytecode_reader);
    ConstantUtf8 *attribute_name = (ConstantUtf8 *) klass->constant_pool->constant_info_arr[attribute_name_index];
    if (strncmp(attribute_name->str, "SourceFile", 10) == 0) {
        SourceFile *sourceFile = (SourceFile *) malloc_x (sizeof(SourceFile))
        sourceFile->base.attribute_length = attribute_length;
        sourceFile->base.attribute_name_index = attribute_name_index;
        sourceFile->sourcefile_index = vm_read_16bit(klass->bytecode_reader);
        return (AttributeBase *) sourceFile;
    } else if (strncmp(attribute_name->str, "Signature", 9) == 0) {
        Signature *signature = (Signature *) malloc_x (sizeof(Signature))
        signature->base.attribute_length = attribute_length;
        signature->base.attribute_name_index = attribute_name_index;
        signature->signature_index = vm_read_16bit(klass->bytecode_reader);
        return (AttributeBase *) signature;
    } else if (strncmp(attribute_name->str, "Code", 4) == 0) {
        Code *code = (Code *) malloc_x (sizeof(Code))
        code->base.attribute_length = attribute_length;
        code->base.attribute_name_index = attribute_name_index;

        code->max_stack = vm_read_16bit(klass->bytecode_reader);
        code->max_locals = vm_read_16bit(klass->bytecode_reader);
        code->code_length = vm_read_32bit(klass->bytecode_reader);
        code->code = malloc_x(code->code_length)
        memcpy(code->code, vm_read_bytes(klass->bytecode_reader, code->code_length), code->code_length);

        code->exception_table_length = vm_read_16bit(klass->bytecode_reader);
        code->exception_table = malloc_x (sizeof(Exception) * code->exception_table_length);
        for (int i = 0; i < code->exception_table_length; i++) {
            memcpy(&code->exception_table[i], vm_read_bytes(klass->bytecode_reader, sizeof(Exception)),
                   sizeof(Exception));
        }
        uint16_t attributes_count = vm_read_16bit(klass->bytecode_reader);
        code->attributes = malloc_x (sizeof(AttributeBase *) * attributes_count);
        for (int i = 0; i < attributes_count; i++) {
            code->attributes[i] = new_attribute(klass);
        }
        return (AttributeBase *) code;
    } else if (strncmp(attribute_name->str, "StackMapTable", 13) == 0) {
        StackMapTable *stack_map_table = (StackMapTable *) malloc_x (sizeof(StackMapTable));
        stack_map_table->base.attribute_length = attribute_length;
        stack_map_table->base.attribute_name_index = attribute_name_index;
        for (int i = 0; i < attribute_length; i++) {
            uint8_t number_of_entries = vm_read_16bit(klass->bytecode_reader);
            int numberofentries = number_of_entries;
            for (int j = 0; j < number_of_entries; j++) {
                uint8_t stack_map_frame = vm_read_8bit(klass);
                int stackmapframe = stack_map_frame;
                stackmapframe = stack_map_frame;
            }
        }
        return (AttributeBase *) stack_map_table;
    } else if (strncmp(attribute_name->str, "LineNumberTable", 15) == 0) {
        LineNumberTable *line_number_table = (LineNumberTable *) malloc_x (sizeof(LineNumberTable));
        line_number_table->base.attribute_length = attribute_length;
        line_number_table->base.attribute_name_index = attribute_name_index;
        line_number_table->line_number_table_length = vm_read_16bit(klass->bytecode_reader);
        int len = sizeof(struct line_number_table_item) * line_number_table->line_number_table_length;
        line_number_table->table_item = malloc_x(len)
        memcpy(line_number_table->table_item,
               vm_read_bytes(klass->bytecode_reader, len),
               len);
        return (AttributeBase *) line_number_table;
    } else if (strncmp(attribute_name->str, "LocalVariableTable", attribute_name->length) == 0) {
        LocalVariableTable *ptr = (LocalVariableTable *) malloc_x (sizeof(LocalVariableTable));
        ptr->base.attribute_length = attribute_length;
        ptr->base.attribute_name_index = attribute_name_index;
        ptr->local_variable_table_length = vm_read_16bit(klass->bytecode_reader);
        int len = sizeof(struct local_variable_table_item) * ptr->local_variable_table_length;
        ptr->table_item = malloc_x(len)
        memcpy(ptr->table_item,
               vm_read_bytes(klass->bytecode_reader, len),
               len);
        return (AttributeBase *) ptr;
    } else {
        assert(0);
        //        for (int i = 0; i < attributeBase->attribute_length; i++) {
        //            vm_read_8bit(klass->bytecode_reader);
        //        }
    }
    printf("attribute end\n");
    return 0;
}