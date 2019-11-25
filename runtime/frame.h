//
// Created by zhoubing on 2017/6/14.
//

#ifndef UNTITLED2_FRAME_H
#define UNTITLED2_FRAME_H

#include <stdint.h>

typedef struct object Object;

typedef union slot Slot;
typedef struct operand_stack OperandStack;
typedef struct local_vars LocalVars;

typedef struct bytecode_reader ByteCodeReader;

union slot {
    int32_t num;
    Object *object_ref;
};

typedef union {
    uint16_t index;
    int16_t _offset;
    int8_t _int8;
} Index;

typedef struct {
    Index _index;
    int32_t _const;
} Operand;

struct local_vars {
    Operand _operand;

    Slot *slots;

    uint32_t max_size;

    void (*set_int)(LocalVars *vars, int, int);

    int (*get_int)(LocalVars *vars, int);

    void (*set_float)(LocalVars *vars, int, float);

    float (*get_float)(LocalVars *vars, int);

    void (*set_long)(LocalVars *vars, int, long);

    long (*get_long)(LocalVars *vars, int);

    void (*set_double)(LocalVars *vars, int, double);

    double (*get_double)(LocalVars *vars, int);

    void (*set_ref)(LocalVars *vars, int, Object *);

    Object (*get_ref)(LocalVars *vars, int);
};

struct operand_stack {
    uint32_t size;
    uint32_t max_size;
    Slot *slots;

    void (*push_int)(OperandStack *, int);

    int (*pop_int)(OperandStack *);

    void (*push_float)(OperandStack *, float);

    float (*pop_float)(OperandStack *);

    void (*push_long)(OperandStack *, long);

    long (*pop_long)(OperandStack *);

    void (*push_double)(OperandStack *, double);

    double (*pop_double)(OperandStack *);

    void (*push_ref)(OperandStack *, Object *ref);

    Object *(*pop_ref)(OperandStack *);
};

typedef struct frame {
    int pc;
    struct frame *prev;
    int localvars_num;
    LocalVars *localvars;
    int operandstack_num;
    OperandStack *operand_stack;
    struct vm_bytecode_reader *bytecode_reader;
    uint8_t (*get_opcode)(struct frame *frame);
} Frame;

Frame *new_frame(struct vm_method *method, struct vm_class *class);

LocalVars *new_local_vars(uint32_t);

OperandStack *new_operand_stack(uint32_t);

#endif //UNTITLED2_FRAME_H
