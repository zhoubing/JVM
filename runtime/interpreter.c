//
// Created by zhoubing on 2017/6/22.
//

#include <stdlib.h>
#include "interpreter.h"
#include "frame.h"
#include "thread.h"

void Interpreter_Run(Interpreter *interpreter, struct vm_method *method) {
    Frame *frame = Frame_New(method, interpreter->class);
    Interpreter_Push(interpreter->thread->vmStack, frame);
    Thread_Run(interpreter->thread);
}

Interpreter *Interpreter_New(struct vm_class *class) {
    Interpreter *ip = malloc_x(sizeof(Interpreter));
    ip->class = class;
    ip->thread = Thread_New();
    return ip;
}

void Interpreter_Push(VM_Stack *vmStack, Frame *frame) {
    VMStack_Push(vmStack, frame);
}