//
// Created by zhoubing on 2022/11/18.
//

#ifndef UNTITLED2_EXTENDED_H
#define UNTITLED2_EXTENDED_H

#include "../runtime/frame.h"

void Read_wide(Frame *frame);

int Run_wide(Frame *frame);

void Read_multianewarray(Frame *frame);

int Run_multianewarray(Frame *frame);

void Read_ifnull(Frame *frame);

int Run_ifnull(Frame *frame);

void Read_ifnonnull(Frame *frame);

int Run_ifnonnull(Frame *frame);

void Read_goto_w(Frame *frame);

int Run_goto_w(Frame *frame);

void Read_jsr_w(Frame *frame);

int Run_jsr_w(Frame *frame);

#endif //UNTITLED2_EXTENDED_H
