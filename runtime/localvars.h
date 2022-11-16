//
// Created by zhoubing on 2022/11/16.
//

#ifndef UNTITLED2_LOCALVARS_H
#define UNTITLED2_LOCALVARS_H

#include <stdint.h>
#include "../type_system/object.h"
#include "operandstack.h"

typedef struct LocalVars {
    Operand _operand;

    Slot *slots;

    uint32_t max_size;

} LocalVars;

void LocalVars_SetInt(LocalVars *lvars, int, int);

int LocalVars_GetInt(LocalVars *lvars, int);

void LocalVars_SetFloat(LocalVars *lvars, int, float);

float LocalVars_GetFloat(LocalVars *lvars, int);

void LocalVars_SetLong(LocalVars *lvars, int, long);

long LocalVars_GetLong(LocalVars *lvars, int);

void LocalVars_SetDouble(LocalVars *lvars, int, long);

double LocalVars_GetDouble(LocalVars *lvars, int);

void LocalVars_SetRef(LocalVars *lvars, int, VM_Object *);

VM_Object *LocalVars_GetRef(LocalVars *lvars, int);

LocalVars *LocalVars_New(uint32_t size);

#endif //UNTITLED2_LOCALVARS_H
