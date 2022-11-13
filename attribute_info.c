//
// Created by zhoubing on 2017/6/10.
//

#include <stdlib.h>
#include <memory.h>
#include "utility.h"
#include "attribute_info.h"

AttributeBase *new_attribute(struct vm_class *klass) {
    log_file_function_line();
    AttributeBase *attributeBase = (AttributeBase *) malloc_x (sizeof(AttributeBase));
    attributeBase->attribute_name_index = vm_read_16bit(klass->bytecode_reader);;
    attributeBase->attribute_length = vm_read_32bit(klass->bytecode_reader);
    ConstantUtf8 *attribute_name = (ConstantUtf8 *) klass->constant_pool->constant_info_arr[attributeBase->attribute_name_index];
    if (strcmp(attribute_name->str, "SourceFile") == 0) {
        SourceFile *sourceFile = (SourceFile *) malloc_x (sizeof(SourceFile));
        log("code 1");
        memcpy(&sourceFile->base, attributeBase, sizeof(AttributeBase));
        log("code 2");
        sourceFile->sourcefile_index = vm_read_16bit(klass->bytecode_reader);
        log("code 3");
        return (AttributeBase *) sourceFile;
    } else if (strcmp(attribute_name->str, "Signature") == 0) {
        Signature *signature = (Signature *) malloc_x (sizeof(Signature));
        memcpy(&signature->base, attributeBase, sizeof(AttributeBase));
        signature->signature_index = vm_read_16bit(klass->bytecode_reader);
        return (AttributeBase *) signature;
    } else if (strcmp(attribute_name->str, "Code") == 0) {
        Code *code = (Code *) malloc_x (sizeof(Code));
        memcpy(&code->base, attributeBase, sizeof(AttributeBase));
        code->max_stack = vm_read_16bit(klass->bytecode_reader);
        code->max_locals = vm_read_16bit(klass->bytecode_reader);
        code->code_length = vm_read_32bit(klass->bytecode_reader);
        code->code = vm_read_bytes(klass->bytecode_reader, code->code_length);

        code->exception_table_length = vm_read_16bit(klass);
        code->exception_table = malloc_x (sizeof(Exception) * code->exception_table_length);
        for (int i = 0; i < code->exception_table_length; i++) {
            memcpy(&code->exception_table[i], vm_read_bytes(klass->bytecode_reader, sizeof(Exception)),
                   sizeof(Exception));
        }
        uint16_t attributes_count = vm_read_16bit(klass);
        code->attributes = malloc_x (sizeof(AttributeBase *) * attributes_count);
        for (int i = 0; i < attributes_count; i++) {
            code->attributes[i] = new_attribute(klass);
        }
        return (AttributeBase *) code;
    } else if (strcmp(attribute_name->str, "StackMapTable") == 0) {
        StackMapTable *stack_map_table = (StackMapTable *) malloc_x (sizeof(StackMapTable));
        memcpy(&stack_map_table->base, attributeBase, sizeof(AttributeBase));
        for (int i = 0; i < attributeBase->attribute_length; i++) {
            uint8_t number_of_entries = vm_read_16bit(klass->bytecode_reader);
            int numberofentries = number_of_entries;
            for (int j = 0; j < number_of_entries; j++) {
                uint8_t stack_map_frame = vm_read_8bit(klass);
                int stackmapframe = stack_map_frame;
                stackmapframe = stack_map_frame;
            }
        }
    } else {
        for (int i = 0; i < attributeBase->attribute_length; i++) {
            vm_read_8bit(klass->bytecode_reader);
        }
    }
    printf("attribute end\n");
    return attributeBase;
}