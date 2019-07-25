//
// Created by zhoubing on 2017/6/15.
//

#ifndef UNTITLED2_INSTRUCTIONS_H
#define UNTITLED2_INSTRUCTIONS_H

#include "../bytecode_reader.h"
#include "frame.h"

typedef struct _Instruction Instruction;

struct _Instruction {

    void (*read_operands)(Instruction *, Frame *);

    int (*run)(Instruction *, Frame *);
};

extern Instruction
        instruction_table[];

#endif //UNTITLED2_INSTRUCTIONS_H
