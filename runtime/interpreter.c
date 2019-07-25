//
// Created by zhoubing on 2017/6/22.
//

#include <stdlib.h>
#include "interpreter.h"
#include "frame.h"
#include "vmthread.h"

void interpreter_run(Interpreter *interpreter, Method *method) {
    Frame *frame = new_frame(method, interpreter->class);
    interpreter->thread->vmStack->push(interpreter->thread->vmStack, frame);
    interpreter->thread->run(interpreter->thread);
}

Interpreter *new_interpreter(Klass *class) {
    struct _Interpreter *inter = malloc(sizeof(struct _Interpreter));
    inter->class = class;
    inter->run = interpreter_run;
    inter->thread = new_vmthread();
    return inter;
}