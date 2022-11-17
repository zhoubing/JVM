//
// Created by zhoubing on 2022/11/17.
//

#ifndef UNTITLED2_CONSTANTS_H
#define UNTITLED2_CONSTANTS_H

#include "../runtime/frame.h"

void Read_noop(Frame *frame);

int Run_noop(Frame *frame);

void Read_aconst_null(Frame *frame);

int Run_aconst_null(Frame *frame);

void Read_iconst_m1(Frame *frame);

int Run_iconst_m1(Frame *frame);

void Read_iconst_0(Frame *frame);

int Run_iconst_0(Frame *frame);

void Read_iconst_1(Frame *frame);

int Run_iconst_1(Frame *frame);

void Read_iconst_2(Frame *frame);

int Run_iconst_2(Frame *frame);

void Read_iconst_3(Frame *frame);

int Run_iconst_3(Frame *frame);

void Read_iconst_4(Frame *frame);

int Run_iconst_4(Frame *frame);

void Read_iconst_5(Frame *frame);

int Run_iconst_5(Frame *frame);

void Read_lconst_0(Frame *frame);

int Run_lconst_0(Frame *frame);

void Read_lconst_1(Frame *frame);

int Run_lconst_1(Frame *frame);

void Read_fconst_0(Frame *frame);

int Run_fconst_0(Frame *frame);

void Read_fconst_1(Frame *frame);

int Run_fconst_1(Frame *frame);

void Read_fconst_2(Frame *frame);

int Run_fconst_2(Frame *frame);

void Read_dconst_0(Frame *frame);

int Run_dconst_0(Frame *frame);

void Read_dconst_1(Frame *frame);

int Run_dconst_1(Frame *frame);

void Read_bipush(Frame *frame);

int Run_bipush(Frame *frame);

void Read_sipush(Frame *frame);

int Run_sipush(Frame *frame);

void Read_ldc(Frame *frame);

int Run_ldc(Frame *frame);

void Read_ldc_w(Frame *frame);

int Run_ldc_w(Frame *frame);

void Read_ldc2_w(Frame *frame);

int Run_ldc2_w(Frame *frame);

#endif //UNTITLED2_CONSTANTS_H
