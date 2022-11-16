//
// Created by zhoubing on 2017/6/15.
//

#ifndef UNTITLED2_INSTRUCTIONS_H
#define UNTITLED2_INSTRUCTIONS_H

#include "../bytecode_reader.h"
#include "frame.h"

typedef struct _Inst {

    void (*read_operands)(struct _Inst *, Frame *);

    int (*run)(struct _Inst *, Frame *);
} Instruction;

extern Instruction
        instruction_table[];

#endif //UNTITLED2_INSTRUCTIONS_H
