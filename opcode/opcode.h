//
// Created by zhoubing on 2022/11/17.
//

#ifndef UNTITLED2_OPCODE_H
#define UNTITLED2_OPCODE_H

#include "../runtime/frame.h"

typedef struct {
    void (*ReadOpCode)(Frame *);

    int (*Run)(Frame *);
} OpCode;

extern OpCode opcode_sets[];

#endif //UNTITLED2_OPCODE_H
