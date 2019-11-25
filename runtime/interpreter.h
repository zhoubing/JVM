//
// Created by zhoubing on 2017/6/22.
//

#ifndef UNTITLED2_INTERPRETER_H
#define UNTITLED2_INTERPRETER_H

#include "../class.h"

typedef struct _VMThread VMThread;

struct interpreter {
    struct vm_class *class;
    VMThread *thread;
    void (*run)(struct interpreter *, struct vm_method *);
};

struct interpreter *new_interpreter(struct vm_class *class);

#endif //UNTITLED2_INTERPRETER_H
