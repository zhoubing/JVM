//
// Created by zhoubing on 2017/6/14.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <assert.h>
#include "../attribute_info.h"
#include "frame.h"
#include "../constant_pool.h"

uint8_t Frame_GetOpCode(Frame *frame) {
    return vm_read_8bit(frame->bytecode_reader);
}

Frame *Frame_New(VM_Method *method, VM_Class *class) {
    AttributeBase **attrs = method->attributes;
    printf("Frame_New is %d\n", method->attributes_count);
    printf("Frame_New is %d\n", VmClass_IsMain(method, class));
    ConstantUtf8 *attribute_name = (ConstantUtf8 *) class->constant_pool->constant_info_arr[method->name_index];
    printf("Frame_New is %s\n", attribute_name->str);

    for (int i = 0; i < method->attributes_count; i++) {
        AttributeBase *attr = attrs[i];
        assert(attr != 0);
        printf("attribute code is %s\n",
               ((ConstantUtf8 *) class->constant_pool->constant_info_arr[attr->attribute_name_index])->str);
        if (IS_ATTRIBUTE_CODE(attr, class)) {
            printf("is attribute code for\n");
            Code *code_attr = (Code *) attr;
            Frame *frame = malloc_x(sizeof(Frame));
            frame->prev = 0;
            frame->klass = class;
            frame->bytecode_reader = new_bytecode_reader(code_attr->code, code_attr->code_length);
            frame->localvars = LocalVars_New(code_attr->max_locals);
            frame->localvars_num = code_attr->max_locals;
            frame->operand_stack = OperandStack_New(code_attr->max_stack);
            frame->operandstack_num = code_attr->max_stack;
            return frame;
        }
    }
    return 0;
}