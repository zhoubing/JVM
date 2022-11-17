//
// Created by zhoubing on 2022/11/17.
//

#ifndef UNTITLED2_STACK_H
#define UNTITLED2_STACK_H

#include "../runtime/frame.h"

void Read_pop(Frame *frame);

int Run_pop(Frame *frame);

void Read_pop2(Frame *frame);

int Run_pop2(Frame *frame);

void Read_dup(Frame *frame);

int Run_dup(Frame *frame);

void Read_dup_x1(Frame *frame);

int Run_dup_x1(Frame *frame);

void Read_dup_x2(Frame *frame);

int Run_dup_x2(Frame *frame);

void Read_dup2(Frame *frame);

int Run_dup2(Frame *frame);

void Read_dup2_x1(Frame *frame);

int Run_dup2_x1(Frame *frame);

void Read_dup2_x2(Frame *frame);

int Run_dup2_x2(Frame *frame);

void Read_swap(Frame *frame);

int Run_swap(Frame *frame);

#endif //UNTITLED2_STACK_H
