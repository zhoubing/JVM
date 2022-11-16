//
// Created by zhoubing on 2022/11/16.
//

#ifndef UNTITLED2_OPERANDSTACK_H
#define UNTITLED2_OPERANDSTACK_H

#include <stdint.h>
#include "../type_system/object.h"

typedef union Slot {
    int32_t num;
    VM_Object *object_ref;
} Slot;

typedef union Index {
    uint16_t index;
    int16_t _offset;
    int8_t _int8;
} Index;

typedef struct Operand {
    Index _index;
    int32_t _const;
} Operand;

typedef struct {
    uint32_t size;
    uint32_t max_size;
    Slot *slots;
} OperandStack;

void OperandStack_PushInt(OperandStack *, int);

int OperandStack_PopInt(OperandStack *);

void OperandStack_PushFloat(OperandStack *, float);

float OperandStack_PopFloat(OperandStack *);

void OperandStack_PushLong(OperandStack *, long);

long OperandStack_PopLong(OperandStack *);

void OperandStack_PushDouble(OperandStack *, double);

double OperandStack_PopDouble(OperandStack *);

void OperandStack_PushRef(OperandStack *, VM_Object *ref);

VM_Object *OperandStack_PopRef(OperandStack *);

OperandStack *OperandStack_New(uint32_t size);
#endif //UNTITLED2_OPERANDSTACK_H
