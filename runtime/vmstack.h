//
// Created by zhoubing on 2017/6/14.
//

#include "frame.h"

#ifndef UNTITLED2_STACK_H
#define UNTITLED2_STACK_H

typedef struct _VMStack {
    uint32_t max_size;
    uint32_t size;
    Frame *top_frame;

    void (*push)(struct _VMStack *stack, Frame *new_frame);

    Frame *(*pop)(struct _VMStack *stack);

    Frame *(*peek)(struct _VMStack *stack);
} VMStack;

VMStack *new_vmstack(uint32_t stack_size);

#endif //UNTITLED2_STACK_H
