//
// Created by zhoubing on 2022/11/18.
//

#ifndef UNTITLED2_CONTROL_H
#define UNTITLED2_CONTROL_H

#include "../runtime/frame.h"

void Read_goto(Frame *frame);

int Run_goto(Frame *frame);

void Read_jsr(Frame *frame);

int Run_jsr(Frame *frame);

void Read_ret(Frame *frame);

int Run_ret(Frame *frame);

void Read_tableswitch(Frame *frame);

int Run_tableswitch(Frame *frame);

void Read_lookupswitch(Frame *frame);

int Run_lookupswitch(Frame *frame);

void Read_ireturn(Frame *frame);

int Run_ireturn(Frame *frame);

void Read_lreturn(Frame *frame);

int Run_lreturn(Frame *frame);

void Read_freturn(Frame *frame);

int Run_freturn(Frame *frame);

void Read_dreturn(Frame *frame);

int Run_dreturn(Frame *frame);

void Read_areturn(Frame *frame);

int Run_areturn(Frame *frame);

void Read_return(Frame *frame);

int Run_return(Frame *frame);

#endif //UNTITLED2_CONTROL_H
