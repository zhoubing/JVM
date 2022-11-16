//
// Created by zhoubing on 2022/11/16.
//

#include <stdlib.h>
#include <assert.h>
#include "localvars.h"
#include "../utility.h"

LocalVars *LocalVars_New(uint32_t maxsize) {
    LocalVars *local_vars = malloc_x(sizeof(LocalVars))
    local_vars->slots = malloc_x(sizeof(Slot) * maxsize)
    local_vars->max_size = maxsize;
    return local_vars;
}

void LocalVars_SetInt(LocalVars *vars, int index, int val) {
    vars->slots[index].num = val;
}

int LocalVars_GetInt(LocalVars *vars, int index) {
    return vars->slots[index].num;
}

//todo
void LocalVars_SetFloat(LocalVars *vars, int index, float val) {
    assert(0);
}

float LocalVars_GetFloat(LocalVars *vars, int index) {
    assert(0);
}

void LocalVars_SetLong(LocalVars *vars, int index, long val) {
    vars->slots[index].num = (int32_t) (val & 0xffffffff);
    vars->slots[++index].num = (int32_t) (val >> 32);
}

long LocalVars_getLong(LocalVars *vars, int index) {
    return (long) vars->slots[index].num & 0xffffffff | (long) vars->slots[++index].num << 32;
}

//void LocalVars_SetDouble(LocalVars *vars, int index, double val) {
//    assert(0);
//}

double LocalVars_GetDouble(LocalVars *vars, int index) {
    assert(0);
    return 0;
}

void LocalVars_SetRef(LocalVars *vars, int index, VM_Object *ref) {
    vars->slots[index].object_ref = ref;
}

VM_Object *LocalVars_GetRef(LocalVars *vars, int index) {
    return vars->slots[index].object_ref;
}