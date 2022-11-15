//
// Created by zhoubing on 2017/6/22.
//

#include <stdlib.h>
#include "interpreter.h"
#include "frame.h"
#include "vmthread.h"

void interpreter_run(struct interpreter *interpreter, struct vm_method *method) {
    Frame *frame = new_frame(method, interpreter->class);
    interpreter->thread->vmStack->push(interpreter->thread->vmStack, frame);
    interpreter->thread->run(interpreter->thread);
}

struct interpreter *new_interpreter(struct vm_class *class) {
    struct interpreter *inter = malloc_x(sizeof(struct interpreter));
    inter->class = class;
    inter->run = interpreter_run;
    inter->thread = new_vmthread();
    return inter;
}