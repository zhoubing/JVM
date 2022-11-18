//
// Created by zhoubing on 2022/11/18.
//

#ifndef UNTITLED2_COMPARISIONS_H
#define UNTITLED2_COMPARISIONS_H
#include "../runtime/frame.h"

int Run_lcmp(Frame *frame);

void Read_lcmp(Frame *frame);

int Run_fcmpl(Frame *frame);

void Read_fcmpl(Frame *frame);

int Run_fcmpg(Frame *frame);

void Read_fcmpg(Frame *frame);

int Run_dcmpl(Frame *frame);

void Read_dcmpl(Frame *frame);

int Run_dcmpg(Frame *frame);

void Read_dcmpg(Frame *frame);

int Run_ifeq(Frame *frame);

void Read_ifeq(Frame *frame);

int Run_ifne(Frame *frame);

void Read_ifne(Frame *frame);

int Run_iflt(Frame *frame);

void Read_iflt(Frame *frame);

int Run_ifge(Frame *frame);

void Read_ifge(Frame *frame);

int Run_ifgt(Frame *frame);

void Read_ifgt(Frame *frame);

int Run_ifle(Frame *frame);

void Read_ifle(Frame *frame);

int Run_if_icmpeq(Frame *frame);

void Read_if_icmpeq(Frame *frame);

int Run_if_icmpne(Frame *frame);

void Read_if_icmpne(Frame *frame);

int Run_if_icmplt(Frame *frame);

void Read_if_icmplt(Frame *frame);

int Run_if_icmpge(Frame *frame);

void Read_if_icmpge(Frame *frame);

int Run_if_icmpgt(Frame *frame);

void Read_if_icmpgt(Frame *frame);

int Run_if_icmple(Frame *frame);

void Read_if_icmple(Frame *frame);

int Run_if_acmpeq(Frame *frame);

void Read_if_acmpeq(Frame *frame);

int Run_if_acmpne(Frame *frame);

void Read_if_acmpne(Frame *frame);

#endif //UNTITLED2_COMPARISIONS_H
