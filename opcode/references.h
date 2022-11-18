//
// Created by zhoubing on 2022/11/18.
//

#ifndef UNTITLED2_REFERENCES_H
#define UNTITLED2_REFERENCES_H

#include "../runtime/frame.h"

void Read_getstatic(Frame *frame);

int Run_getstatic(Frame *frame);

void Read_putstatic(Frame *frame);

int Run_putstatic(Frame *frame);

void Read_getfield(Frame *frame);

int Run_getfield(Frame *frame);

void Read_putfield(Frame *frame);

int Run_putfield(Frame *frame);

void Read_invokevirtual(Frame *frame);

int Run_invokevirtual(Frame *frame);

void Read_invokespecial(Frame *frame);

int Run_invokespecial(Frame *frame);

void Read_invokestatic(Frame *frame);

int Run_invokestatic(Frame *frame);

void Read_invokeinterface(Frame *frame);

int Run_invokeinterface(Frame *frame);

void Read_invokedynamic(Frame *frame);

int Run_invokedynamic(Frame *frame);

void Read_new(Frame *frame);

int Run_new(Frame *frame);

void Read_newarray(Frame *frame);

int Run_newarray(Frame *frame);

void Read_anewarray(Frame *frame);

int Run_anewarray(Frame *frame);

void Read_arraylength(Frame *frame);

int Run_arraylength(Frame *frame);

void Read_athrow(Frame *frame);

int Run_athrow(Frame *frame);

void Read_checkcast(Frame *frame);

int Run_checkcast(Frame *frame);

void Read_instanceof(Frame *frame);

int Run_instanceof(Frame *frame);

void Read_monitorenter(Frame *frame);

int Run_monitorenter(Frame *frame);

void Read_monitorexit(Frame *frame);

int Run_monitorexit(Frame *frame);

#endif //UNTITLED2_REFERENCES_H
