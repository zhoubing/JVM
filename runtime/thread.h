//
// Created by zhoubing on 2017/6/14.
//

#ifndef UNTITLED2_THREAD_H
#define UNTITLED2_THREAD_H

#include "vmstack.h"

typedef struct {
    uint32_t pc;    //program counter
    VMStack *vmStack; //jvm stack
} Thread;

void Thread_Run(Thread *thread);

Thread *Thread_New();

#endif //UNTITLED2_THREAD_H
