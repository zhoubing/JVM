//
// Created by zhoubing on 2017/6/14.
//

#ifndef UNTITLED2_FRAME_H
#define UNTITLED2_FRAME_H

#include <stdint.h>
#include "localvars.h"
#include "../class.h"

typedef struct Frame {
    int pc;
    struct frame *prev;
    int localvars_num;
    LocalVars *localvars;
    int operandstack_num;
    OperandStack *operand_stack;
    struct vm_bytecode_reader *bytecode_reader;
    uint8_t (*get_opcode)(struct frame *frame);

    VM_Class *klass; //temp?????
} Frame;

Frame *Frame_New(VM_Method *method, VM_Class *class);

uint8_t Frame_GetOpCode(Frame *);

#endif //UNTITLED2_FRAME_H
