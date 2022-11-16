//
// Created by zhoubing on 2022/11/16.
//

#include <stdlib.h>
#include <assert.h>
#include "operandstack.h"

OperandStack *OperandStack_New(uint32_t max_size) {
    OperandStack *operand_stack = malloc(sizeof(OperandStack));
    operand_stack->max_size = max_size;
    operand_stack->size = 0;
    operand_stack->slots = malloc(sizeof(Slot) * max_size);
    return operand_stack;
}

void OperandStack_PushInt(OperandStack *stack, int val) {
    stack->slots[stack->size++].num = val;
}

int OperandStack_PopInt(OperandStack *stack) {
    return stack->slots[--stack->size].num;
}

//todo
void OperandStack_PushFloat(OperandStack *stack, float val) {
    assert(0);
}

//todo
//http://blog.csdn.net/alan00000/article/details/14498367
//http://blog.csdn.net/longshenlmj/article/details/47616481
float OperandStack_PopFloat(OperandStack *stack) {
    assert(0);
}

void OperandStack_PushLong(OperandStack *stack, long val) {
    stack->slots[stack->size++].num = (int32_t) (val & 0xffffffff);
    stack->slots[stack->size++].num = (int32_t) (val >> 32);
}

long OperandStack_PopLong(OperandStack *stack) {
    return (long) stack->slots[--stack->size].num << 32 | stack->slots[--stack->size].num & 0xffffffff;
}

//todo
void OperandStack_PushDouble(OperandStack *stack, double val) {
    assert(0);
}

//todo
double OperandStack_PopDouble(OperandStack *stack) {
    assert(0);
}

void OperandStack_PushRef(OperandStack *stack, VM_Object *ref) {
    stack->slots[stack->size++].object_ref = ref;
}

VM_Object *OperandStack_PopRef(OperandStack *stack) {
    return stack->slots[--stack->size].object_ref;
}
