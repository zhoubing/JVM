//
// Created by zhoubing on 2022/11/18.
//

#include <assert.h>
#include "references.h"
#include "stdbool.h"
#include "../constant_pool.h"

void Read_getstatic(Frame *frame) {
    //assert(0);
}

int Run_getstatic(Frame *frame) {
    uint16_t index = vm_read_16bit(frame->bytecode_reader);
    printf("Run_getstatic: %d\n", index);
    struct constant_field_ref_info *fieldRefInfo = frame->klass->constant_pool->constant_info_arr[index];
    struct constant_class_info *classInfo = frame->klass->constant_pool->constant_info_arr[fieldRefInfo->class_index];
    struct constant_utf8 *constantUtf8 = frame->klass->constant_pool->constant_info_arr[classInfo->name_index];
    printf("Run_getstatic: %s\n", constantUtf8->str);

    struct constant_name_and_type *nameAndType = frame->klass->constant_pool->constant_info_arr[fieldRefInfo->name_and_type_index];
    struct constant_utf8 *constantUtf81 = frame->klass->constant_pool->constant_info_arr[nameAndType->nameIndex];
    struct constant_utf8 *constantUtf82 = frame->klass->constant_pool->constant_info_arr[nameAndType->descIndex];
    printf("Run_getstatic: %s\n", constantUtf81->str);
    printf("Run_getstatic: %s\n", constantUtf82->str);

    assert(false);
}

void Read_putstatic(Frame *frame) {
    assert(false);
}

int Run_putstatic(Frame *frame) {
    assert(false);
}

void Read_getfield(Frame *frame) {
    assert(false);
}

int Run_getfield(Frame *frame) {
    assert(false);
}

void Read_putfield(Frame *frame) {
    assert(false);
}

int Run_putfield(Frame *frame) {
    assert(false);
}

void Read_invokevirtual(Frame *frame) {
    assert(false);
}

int Run_invokevirtual(Frame *frame) {
    assert(false);
}

void Read_invokespecial(Frame *frame) {
    assert(false);
}

int Run_invokespecial(Frame *frame) {
    assert(false);
}

void Read_invokestatic(Frame *frame) {
    assert(false);
}

int Run_invokestatic(Frame *frame) {
    assert(false);
}

void Read_invokeinterface(Frame *frame) {
    assert(false);
}

int Run_invokeinterface(Frame *frame) {
    assert(false);
}

void Read_invokedynamic(Frame *frame) {
    assert(false);
}

int Run_invokedynamic(Frame *frame) {
    assert(false);
}

void Read_new(Frame *frame) {
    assert(false);
}

int Run_new(Frame *frame) {
    assert(false);
}

void Read_newarray(Frame *frame) {
    assert(false);
}

int Run_newarray(Frame *frame) {
    assert(false);
}

void Read_anewarray(Frame *frame) {
    assert(false);
}

int Run_anewarray(Frame *frame) {
    assert(false);
}

void Read_arraylength(Frame *frame) {
    assert(false);
}

int Run_arraylength(Frame *frame) {
    assert(false);
}

void Read_athrow(Frame *frame) {
    assert(false);
}

int Run_athrow(Frame *frame) {
    assert(false);
}

void Read_checkcast(Frame *frame) {
    assert(false);
}

int Run_checkcast(Frame *frame) {
    assert(false);
}

void Read_instanceof(Frame *frame) {
    assert(false);
}

int Run_instanceof(Frame *frame) {
    assert(false);
}

void Read_monitorenter(Frame *frame) {
    assert(false);
}

int Run_monitorenter(Frame *frame) {
    assert(false);
}

void Read_monitorexit(Frame *frame) {
    assert(false);
}

int Run_monitorexit(Frame *frame) {
    assert(false);
}
