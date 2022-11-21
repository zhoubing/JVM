//
// Created by zhoubing on 2017/6/22.
//

#ifndef UNTITLED2_INTERPRETER_H
#define UNTITLED2_INTERPRETER_H

#include "../class.h"
#include "thread.h"

typedef struct {
    VM_Class *class;
    Thread *thread;
} Interpreter;

void Interpreter_Run(Interpreter *, VM_Method *);

Interpreter *Interpreter_New(VM_Class *class);

void Interpreter_Push(VM_Stack *, Frame *);

#endif //UNTITLED2_INTERPRETER_H
