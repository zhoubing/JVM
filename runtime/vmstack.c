//
// Created by zhoubing on 2017/6/14.
//

#include <stdlib.h>
#include "vmstack.h"
#include "../utility.h"

Frame *peek(VMStack *stack) {
    return stack->top_frame;
}

Frame *pop(VMStack *stack) {
    if (stack->size == 0) {
        return 0;
    }
    Frame *top_frame = stack->top_frame;
    stack->top_frame = top_frame->prev;
    top_frame->prev = 0;
    stack->size--;
    return top_frame;
}

void push(VMStack *stack, Frame *new_frame) {
    if (stack->size >= stack->max_size) {
        log("vmstack is overflow");
        exit(1);
    }
    if (stack->top_frame != 0) {
        new_frame->prev = stack->top_frame;
    }
    stack->size++;
    stack->top_frame = new_frame;
}

VMStack *new_vmstack(uint32_t stack_size) {
    VMStack *stack = malloc(sizeof(VMStack));
    stack->max_size = stack_size;
    stack->size = 0;
    stack->top_frame = 0;
    stack->pop = pop;
    stack->push = push;
    stack->peek = peek;
    return stack;
}