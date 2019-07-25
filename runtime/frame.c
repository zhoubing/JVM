//
// Created by zhoubing on 2017/6/14.
//

#include <stdlib.h>
#include <memory.h>
#include "../attribute_info.h"
#include "frame.h"

uint8_t get_opcode(Frame *frame) {
    return frame->bytecode_reader->read_8bit(frame->bytecode_reader);
}

Frame *new_frame(Method *method, Klass *class) {
    AttributeBase **attrs = method->attributes;
    for (int i = 0; i < method->attributes_count; i++) {
        AttributeBase *attr = attrs[i];
        if (attr == 0) {
            continue;
        }
        if (IS_ATTRIBUTE_CODE(attr, class)) {
            Code *code_attr = (Code *) attr;
            Frame *frame = malloc(sizeof(Frame));
            frame->prev = 0;
            frame->bytecode_reader = new_bytecode_reader(code_attr->code, code_attr->code_length);
            frame->localvars = new_local_vars(code_attr->max_locals);
            frame->localvars_num = code_attr->max_locals;
            frame->operand_stack = new_operand_stack(code_attr->max_stack);
            frame->operandstack_num = code_attr->max_stack;
            frame->get_opcode = get_opcode;
            return frame;
        }
    }
    return 0;
}

void push_int(OperandStack *stack, int val) {
    stack->slots[stack->size++].num = val;
}

int pop_int(OperandStack *stack) {
    return stack->slots[--stack->size].num;
}

//todo
void push_float(OperandStack *stack, float val) {

}

//todo
//http://blog.csdn.net/alan00000/article/details/14498367
//http://blog.csdn.net/longshenlmj/article/details/47616481
float pop_float(OperandStack *stack) {

}

void push_long(OperandStack *stack, long val) {
    stack->slots[stack->size++].num = (int32_t) (val & 0xffffffff);
    stack->slots[stack->size++].num = (int32_t) (val >> 32);
}

long pop_long(OperandStack *stack) {
    return (long) stack->slots[--stack->size].num << 32 | stack->slots[--stack->size].num & 0xffffffff;
}

//todo
void push_double(OperandStack *stack, double val) {

}

//todo
double pop_double(OperandStack *stack) {

}

void push_ref(OperandStack *stack, Object *ref) {
    stack->slots[stack->size++].object_ref = ref;
}

Object *pop_ref(OperandStack *stack) {
    return stack->slots[--stack->size].object_ref;
}

OperandStack *new_operand_stack(uint32_t max_size) {
    OperandStack *operand_stack = malloc(sizeof(OperandStack));
    operand_stack->max_size = max_size;
    operand_stack->size = 0;
    operand_stack->slots = malloc(sizeof(Slot) * max_size);
    operand_stack->push_int = push_int;
    operand_stack->pop_int = pop_int;
    operand_stack->push_float = push_float;
    operand_stack->pop_float = pop_float;
    operand_stack->push_double = push_double;
    operand_stack->pop_double = pop_double;
    operand_stack->push_long = push_long;
    operand_stack->pop_long = pop_long;
    operand_stack->push_ref = push_ref;
    operand_stack->pop_ref = pop_ref;

    return operand_stack;
}

void set_int(LocalVars *vars, int index, int val) {
    vars->slots[index].num = val;
}

int get_int(LocalVars *vars, int index) {
    return vars->slots[index].num;
}

//todo
void set_float(LocalVars *vars, int index, float val) {

}

float get_float(LocalVars *vars, int index) {

}

void set_long(LocalVars *vars, int index, long val) {
    vars->slots[index].num = (int32_t) (val & 0xffffffff);
    vars->slots[++index].num = (int32_t) (val >> 32);
}

long get_long(LocalVars *vars, int index) {
    return (long) vars->slots[index].num & 0xffffffff | (long) vars->slots[++index].num << 32;
}

void set_double(LocalVars *vars, int index, double val) {

}

double get_double(LocalVars *vars, int index) {

}

void set_ref(LocalVars *vars, int index, Object *ref) {
    vars->slots[index].object_ref = ref;
}

Object *get_ref(LocalVars *vars, int index) {
    return vars->slots[index].object_ref;
}


LocalVars *new_local_vars(uint32_t max_size) {
    LocalVars *local_vars = malloc(sizeof(LocalVars));
    local_vars->slots = malloc(sizeof(Slot) * max_size);
    local_vars->max_size = max_size;
    local_vars->set_int = set_int;
    local_vars->get_int = get_int;
    local_vars->set_long = set_long;
    local_vars->get_long = get_long;
    local_vars->set_float = set_float;
    local_vars->get_float = get_float;
    local_vars->set_double = set_double;
    local_vars->get_double = get_double;
    return local_vars;
}