//
// Created by zhoubing on 2017/6/14.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "thread.h"
#include "instructions.h"
#include "../utility.h"
#include "../opcode/opcode.h"

void Thread_Run(Thread *this) {
    for (;;) {
        Frame *current_frame = VMStack_Peek(this->vmStack);
        printf("%d\n", current_frame);
        current_frame->pc = current_frame->bytecode_reader->index;
        uint8_t op_code = Frame_GetOpCode(current_frame);
        printf("op_code is %x\n", op_code);

        Instruction instruction = instruction_sets[op_code];
        instruction.read_operands(&instruction, current_frame);
        if (instruction.run(&instruction, current_frame) != 0) {
            for (int i = 0; i < current_frame->localvars_num; i++) {
                for (int j = 0; j < current_frame->localvars[i].max_size; j++) {
                    printf("LocalVars: %d\n", current_frame->localvars[i].slots[j].num);
                }
            }
            for (int i = 0; i < current_frame->operandstack_num; i++) {
                for (int j = 0; j < current_frame->operand_stack[i].max_size; j++) {
                    printf("OperandStack: %d\n", current_frame->operand_stack[i].slots[j].num);
                }
            }
            exit(-1);
        }
    }
}

Thread *Thread_New() {
    Thread *vmThread = malloc_x(sizeof(Thread));
    vmThread->vmStack = VMStack_New(1024);
    return vmThread;
}