//
// Created by zhoubing on 2022/11/17.
//

#include <assert.h>
#include "constants.h"
#include "../bytecode_reader.h"

void Read_noop(Frame *frame) {
    assert(0);
}

int Run_noop(Frame *frame) {
    assert(0);
}

void Read_aconst_null(Frame *frame) {
    assert(0);
}

int Run_aconst_null(Frame *frame) {
    assert(0);
}

void Read_iconst_m1(Frame *frame) {
    assert(0);
}

int Run_iconst_m1(Frame *frame) {
    assert(0);
}

void Read_iconst_0(Frame *frame) {
    assert(0);
}

int Run_iconst_0(Frame *frame) {
    assert(0);
}

void Read_iconst_1(Frame *frame) {
    assert(0);
}

int Run_iconst_1(Frame *frame) {
    assert(0);
}

void Read_iconst_2(Frame *frame) {
    assert(0);
}

int Run_iconst_2(Frame *frame) {
    assert(0);
}

void Read_iconst_3(Frame *frame) {
    assert(0);
}

int Run_iconst_3(Frame *frame) {
    assert(0);
}

void Read_iconst_4(Frame *frame) {
    assert(0);
}

int Run_iconst_4(Frame *frame) {
    assert(0);
}

void Read_iconst_5(Frame *frame) {
    assert(0);
}

int Run_iconst_5(Frame *frame) {
    assert(0);
}

void Read_lconst_0(Frame *frame) {
    assert(0);
}

int Run_lconst_0(Frame *frame) {
    assert(0);
}

void Read_lconst_1(Frame *frame) {
    assert(0);
}

int Run_lconst_1(Frame *frame) {
    assert(0);
}

void Read_fconst_0(Frame *frame) {
    assert(0);
}

int Run_fconst_0(Frame *frame) {
    assert(0);
}

void Read_fconst_1(Frame *frame) {
    assert(0);
}

int Run_fconst_1(Frame *frame) {
    assert(0);
}

void Read_fconst_2(Frame *frame) {
    assert(0);
}

int Run_fconst_2(Frame *frame) {
    assert(0);
}

void Read_dconst_0(Frame *frame) {
    assert(0);
}

int Run_dconst_0(Frame *frame) {
    assert(0);
}

void Read_dconst_1(Frame *frame) {
    assert(0);
}

int Run_dconst_1(Frame *frame) {
    assert(0);
}

void Read_bipush(Frame *frame) {
    frame->localvars->_operand._index.index = (uint16_t) vm_read_8bit(frame->bytecode_reader);
}

int Run_bipush(Frame *frame) {
    int val = frame->localvars->_operand._index._int8;
    OperandStack_PushInt(frame->operand_stack, val);
    return 0;
}

void Read_sipush(Frame *frame) {
    assert(0);
}

int Run_sipush(Frame *frame) {
    assert(0);
}

void Read_ldc(Frame *frame) {
    assert(0);
}

int Run_ldc(Frame *frame) {
    assert(0);
}

void Read_ldc_w(Frame *frame) {
    assert(0);
}

int Run_ldc_w(Frame *frame) {
    assert(0);
}

void Read_ldc2_w(Frame *frame) {
    assert(0);
}

int Run_ldc2_w(Frame *frame) {
    assert(0);
}