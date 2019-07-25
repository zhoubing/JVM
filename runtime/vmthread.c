//
// Created by zhoubing on 2017/6/14.
//

#include <stdlib.h>
#include "vmthread.h"
#include "instructions.h"

void run(VMThread *this) {
    for (;;) {
        Frame *current_frame = this->vmStack->peek(this->vmStack);
        current_frame->pc = current_frame->bytecode_reader->index;
        uint8_t op_code = current_frame->get_opcode(current_frame);
        Instruction instruction = instruction_table[op_code];
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

VMThread *new_vmthread() {
    VMThread *vmThread = malloc(sizeof(VMThread));
    vmThread->vmStack = new_vmstack(1024);
    vmThread->run = run;
    return vmThread;
}