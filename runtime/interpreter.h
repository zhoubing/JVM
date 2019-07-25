//
// Created by zhoubing on 2017/6/22.
//

#ifndef UNTITLED2_INTERPRETER_H
#define UNTITLED2_INTERPRETER_H

#include "../class.h"

typedef struct _VMThread VMThread;

struct _Interpreter {
    Klass *class;
    VMThread *thread;
    void (*run)(struct _Interpreter *, Method *);
};

typedef struct _Interpreter Interpreter;

Interpreter *new_interpreter(Klass *class);

#endif //UNTITLED2_INTERPRETER_H
