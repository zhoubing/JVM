//
// Created by zhoubing on 2017/6/14.
//

#include <stdlib.h>
#include <assert.h>
#include "vmstack.h"
#include "../utility.h"

Frame *VMStack_Peek(VM_Stack *stack) {
    return stack->top_frame;
}

Frame *VMStack_Pop(VM_Stack *stack) {
    if (stack->size == 0) {
        return 0;
    }
    Frame *top_frame = stack->top_frame;
    stack->top_frame = top_frame->prev;
    top_frame->prev = 0;
    stack->size--;
    return top_frame;
}

void VMStack_Push(VM_Stack *stack, Frame *new_frame) {
    log_file_function_line();
    assert(stack->size < stack->max_size);
    printf("Frame_New: %d\n", new_frame);
    if (stack->top_frame != 0) {
        new_frame->prev = stack->top_frame;
    }
    stack->size++;
    stack->top_frame = new_frame;
    printf("stack->top_frame: %d\n", stack->size);
    printf("stack->top_frame: %d\n", stack->top_frame);
}

VM_Stack *VMStack_New(uint32_t stack_size) {
    VM_Stack *stack = malloc_x(sizeof(VM_Stack));
    stack->max_size = stack_size;
    stack->size = 0;
    stack->top_frame = 0;
    return stack;
}