//
// Created by zhoubing on 2017/6/22.
//

#ifndef UNTITLED2_INTERPRETER_H
#define UNTITLED2_INTERPRETER_H

#include "../class.h"
#include "thread.h"

typedef struct {
    struct vm_class *class;
    Thread *thread;
} Interpreter;

void Interpreter_Run(Interpreter *, struct vm_method *);

Interpreter *Interpreter_New(struct vm_class *class);

void Interpreter_Push(VMStack *, Frame *);

#endif //UNTITLED2_INTERPRETER_H
