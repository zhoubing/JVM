//
// Created by zhoubing on 2017/6/14.
//

#ifndef UNTITLED2_THREAD_H
#define UNTITLED2_THREAD_H

#include "vmstack.h"

typedef struct _VMThread {
    uint32_t pc;
    VMStack *vmStack;
    void (*run)(struct _VMThread *stack);
} VMThread;

VMThread *new_vmthread();

#endif //UNTITLED2_THREAD_H
