//
// Created by zhoubing on 2017/6/22.
//

#include <stdlib.h>
#include "interpreter.h"
#include "frame.h"
#include "thread.h"

void Interpreter_Run(Interpreter *interpreter, VM_Method *method) {
    Frame *frame = Frame_New(method, interpreter->class);
    Interpreter_Push(interpreter->thread->vmStack, frame);
    Thread_Run(interpreter->thread);
}

Interpreter *Interpreter_New(VM_Class *class) {
    Interpreter *ip = malloc_x(sizeof(Interpreter));
    ip->class = class;
    ip->thread = Thread_New();
    return ip;
}

void Interpreter_Push(VM_Stack *vmStack, Frame *frame) {
    VMStack_Push(vmStack, frame);
}