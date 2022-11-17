//
// Created by zhoubing on 2017/6/14.
//

#include "frame.h"

#ifndef UNTITLED2_STACK_H
#define UNTITLED2_STACK_H

typedef struct {
    uint32_t max_size;
    uint32_t size;
    Frame *top_frame;
} VM_Stack;

VM_Stack *VMStack_New(uint32_t stack_size);

void VMStack_Push(VM_Stack *stack, Frame *newframe);

Frame *VMStack_Pop(VM_Stack *stack);

Frame *VMStack_Peek(VM_Stack *stack);

#endif //UNTITLED2_STACK_H
