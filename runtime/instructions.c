//
// Created by zhoubing on 2017/6/15.
//

#include <stdlib.h>
#include "instructions.h"
#include "../utility.h"

#define READ_OPERANDS_FUNCTION_NAME(operand) read_operand_##operand

#define RUN_FUNCTION_NAME(instruction_name) instruction_name##_run

#define INSTRUCTION_NOP(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(nop),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_INT8(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(int8),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_INDEX8(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(uint8),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_INDEX16(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(uint16),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_INT16(instruction_name) {\
       READ_OPERANDS_FUNCTION_NAME(int16),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_LOOKSWITCH(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(switch),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_TABLESWITCH(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(tableswitch),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_INT32(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(int32),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_WIDE(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(wide),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_IINC(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(iinc),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_UNSUPPORTED(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(unsupported),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_INVOKE_INTERFACE(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(instruction_name),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_NEWARRAY(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(instruction_name),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_MULTIANEWARRAY(instruction_name) {\
        READ_OPERANDS_FUNCTION_NAME(instruction_name),  RUN_FUNCTION_NAME(instruction_name)\
}

#define INSTRUCTION_EXEC(instruction_name) int RUN_FUNCTION_NAME(instruction_name)(Instruction *instruction, Frame *frame)

#define ISTORE(index)  int val = frame->operand_stack->pop_int(frame->operand_stack); \
                        frame->localvars->set_int(frame->localvars, index, val);

#define ILOAD(index)  int val = frame->localvars->get_int(frame->localvars, index);\
                        frame->operand_stack->push_int(frame->operand_stack, val);

void read_operand_switch (Instruction *instruction, Frame *bytecode_reader)
{
}

void read_operand_tableswitch (Instruction *instruction, Frame *bytecode_reader)
{
}

void read_operand_nop (Instruction *instruction, Frame *bytecode_reader)
{
}

void read_operand_uint16 (Instruction *instruction, Frame *frame)
{
  frame->localvars->_operand._index.index = (uint16_t) vm_read_16bit (frame);
}

void read_operand_int16 (Instruction *instruction, Frame *frame)
{
  frame->localvars->_operand._index._offset = vm_read_16bit (frame);
}

void read_operand_uint8 (Instruction *instruction, Frame *frame)
{
  frame->localvars->_operand._index.index = (uint16_t) vm_read_8bit (frame);
}

void read_operand_int8 (Instruction *instruction, Frame *frame)
{
  frame->localvars->_operand._index._int8 = (int8_t) vm_read_8bit (frame);
}

void read_operand_int32 (Instruction *instruction, Frame *frame)
{
  frame->localvars->_operand._const = (int32_t) vm_read_32bit (frame);
}

void read_operand_wide (Instruction *instruction, Frame *bytecode_reader)
{
}

void read_operand_iinc (Instruction *instruction, Frame *frame)
{
  frame->localvars->_operand._index.index = vm_read_8bit (frame);
  frame->localvars->_operand._const = vm_read_8bit (frame);
}

void read_operand_unsupported (Instruction *instruction, Frame *bytecode_reader)
{
  log ("unsupported instruction");
  exit (-1);
}

void read_operand_invokeinterface (Instruction *instruction, Frame *bytecode_reader)
{

}

void read_operand_newarray (Instruction *instruction, Frame *bytecode_reader)
{

}

void read_operand_multianewarray (Instruction *instruction, Frame *bytecode_reader)
{

}

void pop2 (Frame *frame, int *val1, int *val2)
{
  *val2 = frame->operand_stack->pop_int (frame->operand_stack);
  *val1 = frame->operand_stack->pop_int (frame->operand_stack);
}

void branch (Frame *frame, int offset)
{
  frame->pc += offset;
  frame->bytecode_reader->index = frame->pc;
}

INSTRUCTION_EXEC(nop)
{
  log_file_function_line ();
  return 0;
}

INSTRUCTION_EXEC(aconst_null)
{
  frame->operand_stack->push_ref (frame->operand_stack, 0);
  return 0;
}

INSTRUCTION_EXEC(iconst_m1)
{

}

INSTRUCTION_EXEC(iconst_0)
{
  frame->operand_stack->push_int (frame->operand_stack, 0);
  return 0;
}

INSTRUCTION_EXEC(iconst_1)
{

}

INSTRUCTION_EXEC(iconst_2)
{

}

INSTRUCTION_EXEC(iconst_3)
{

}

INSTRUCTION_EXEC(iconst_4)
{

}

INSTRUCTION_EXEC(iconst_5)
{

}

INSTRUCTION_EXEC(lconst_0)
{

}

INSTRUCTION_EXEC(lconst_1)
{

}

INSTRUCTION_EXEC(fconst_0)
{

}

INSTRUCTION_EXEC(fconst_1)
{

}

INSTRUCTION_EXEC(fconst_2)
{

}

INSTRUCTION_EXEC(dconst_0)
{

}

INSTRUCTION_EXEC(dconst_1)
{

}

INSTRUCTION_EXEC(bipush)
{
  int val = frame->localvars->_operand._index._int8;
  frame->operand_stack->push_int (frame->operand_stack, val);
  return 0;
}

INSTRUCTION_EXEC(sipush)
{

}

INSTRUCTION_EXEC(ldc)
{

}

INSTRUCTION_EXEC(ldc_w)
{

}

INSTRUCTION_EXEC(ldc2_w)
{

}

INSTRUCTION_EXEC(iload)
{

}

INSTRUCTION_EXEC(lload)
{

}

INSTRUCTION_EXEC(fload)
{

}

INSTRUCTION_EXEC(dload)
{

}

INSTRUCTION_EXEC(aload)
{

}

INSTRUCTION_EXEC(iload_0)
{
  ILOAD(0)
  return 0;
}

INSTRUCTION_EXEC(iload_1)
{
  ILOAD(1)
  return 0;
}

INSTRUCTION_EXEC(iload_2)
{
  ILOAD(2)
  return 0;
}

INSTRUCTION_EXEC(iload_3)
{
  ILOAD(3)
  return 0;
}

INSTRUCTION_EXEC(lload_0)
{

}

INSTRUCTION_EXEC(lload_1)
{

}

INSTRUCTION_EXEC(lload_2)
{

}

INSTRUCTION_EXEC(lload_3)
{

}

INSTRUCTION_EXEC(fload_0)
{

}

INSTRUCTION_EXEC(fload_1)
{

}

INSTRUCTION_EXEC(fload_2)
{

}

INSTRUCTION_EXEC(fload_3)
{

}

INSTRUCTION_EXEC(dload_0)
{

}

INSTRUCTION_EXEC(dload_1)
{

}

INSTRUCTION_EXEC(dload_2)
{

}

INSTRUCTION_EXEC(dload_3)
{

}

INSTRUCTION_EXEC(aload_0)
{

}

INSTRUCTION_EXEC(aload_1)
{

}

INSTRUCTION_EXEC(aload_2)
{

}

INSTRUCTION_EXEC(aload_3)
{

}

INSTRUCTION_EXEC(iaload)
{

}

INSTRUCTION_EXEC(laload)
{

}

INSTRUCTION_EXEC(faload)
{

}

INSTRUCTION_EXEC(daload)
{

}

INSTRUCTION_EXEC(aaload)
{

}

INSTRUCTION_EXEC(baload)
{

}

INSTRUCTION_EXEC(caload)
{

}

INSTRUCTION_EXEC(saload)
{

}

INSTRUCTION_EXEC(istore)
{

}

INSTRUCTION_EXEC(lstore)
{

}

INSTRUCTION_EXEC(fstore)
{

}

INSTRUCTION_EXEC(dstore)
{

}

INSTRUCTION_EXEC(astore)
{

}

INSTRUCTION_EXEC(istore_0)
{
  ISTORE(0)
  return 0;
}

INSTRUCTION_EXEC(istore_1)
{
  //ISTORE(1)
  int val = frame->operand_stack->pop_int (frame->operand_stack);
  frame->localvars->set_int (frame->localvars, 1, val);
  return 0;
}

INSTRUCTION_EXEC(istore_2)
{
  ISTORE(2)
  return 0;
}

INSTRUCTION_EXEC(istore_3)
{
  ISTORE(3)
  return 0;
}

INSTRUCTION_EXEC(lstore_0)
{

}

INSTRUCTION_EXEC(lstore_1)
{

}

INSTRUCTION_EXEC(lstore_2)
{

}

INSTRUCTION_EXEC(lstore_3)
{

}

INSTRUCTION_EXEC(fstore_0)
{

}

INSTRUCTION_EXEC(fstore_1)
{

}

INSTRUCTION_EXEC(fstore_2)
{

}

INSTRUCTION_EXEC(fstore_3)
{

}

INSTRUCTION_EXEC(dstore_0)
{

}

INSTRUCTION_EXEC(dstore_1)
{

}

INSTRUCTION_EXEC(dstore_2)
{

}

INSTRUCTION_EXEC(dstore_3)
{

}

INSTRUCTION_EXEC(astore_0)
{

}

INSTRUCTION_EXEC(astore_1)
{

}

INSTRUCTION_EXEC(astore_2)
{

}

INSTRUCTION_EXEC(astore_3)
{

}

INSTRUCTION_EXEC(iastore)
{

}

INSTRUCTION_EXEC(lastore)
{

}

INSTRUCTION_EXEC(fastore)
{

}

INSTRUCTION_EXEC(dastore)
{

}

INSTRUCTION_EXEC(aastore)
{

}

INSTRUCTION_EXEC(bastore)
{

}

INSTRUCTION_EXEC(castore)
{

}

INSTRUCTION_EXEC(sastore)
{

}

INSTRUCTION_EXEC(pop)
{

}

INSTRUCTION_EXEC(pop2)
{

}

INSTRUCTION_EXEC(dup)
{

}

INSTRUCTION_EXEC(dup_x1)
{

}

INSTRUCTION_EXEC(dup_x2)
{

}

INSTRUCTION_EXEC(dup2)
{

}

INSTRUCTION_EXEC(dup2_x1)
{

}

INSTRUCTION_EXEC(dup2_x2)
{

}

INSTRUCTION_EXEC(swap)
{

}

INSTRUCTION_EXEC(iadd)
{
  int val1, val2;
  pop2 (frame, &val1, &val2);
  frame->operand_stack->push_int (frame->operand_stack, val1 + val2);
  return 0;
}

INSTRUCTION_EXEC(ladd)
{

}

INSTRUCTION_EXEC(fadd)
{

}

INSTRUCTION_EXEC(dadd)
{

}

INSTRUCTION_EXEC(isub)
{

}

INSTRUCTION_EXEC(lsub)
{

}

INSTRUCTION_EXEC(fsub)
{

}

INSTRUCTION_EXEC(dsub)
{

}

INSTRUCTION_EXEC(imul)
{

}

INSTRUCTION_EXEC(lmul)
{

}

INSTRUCTION_EXEC(fmul)
{

}

INSTRUCTION_EXEC(dmul)
{

}

INSTRUCTION_EXEC(idiv)
{

}

INSTRUCTION_EXEC(ldiv)
{

}

INSTRUCTION_EXEC(fdiv)
{

}

INSTRUCTION_EXEC(ddiv)
{

}

INSTRUCTION_EXEC(irem)
{

}

INSTRUCTION_EXEC(lrem)
{

}

INSTRUCTION_EXEC(frem)
{

}

INSTRUCTION_EXEC(drem)
{

}

INSTRUCTION_EXEC(ineg)
{

}

INSTRUCTION_EXEC(lneg)
{

}

INSTRUCTION_EXEC(fneg)
{

}

INSTRUCTION_EXEC(dneg)
{

}

INSTRUCTION_EXEC(ishl)
{

}

INSTRUCTION_EXEC(lshl)
{

}

INSTRUCTION_EXEC(ishr)
{

}

INSTRUCTION_EXEC(lshr)
{

}

INSTRUCTION_EXEC(iushr)
{

}

INSTRUCTION_EXEC(lushr)
{

}

INSTRUCTION_EXEC(iand)
{

}

INSTRUCTION_EXEC(land)
{

}

INSTRUCTION_EXEC(ior)
{

}

INSTRUCTION_EXEC(lor)
{

}

INSTRUCTION_EXEC(ixor)
{

}

INSTRUCTION_EXEC(lxor)
{

}

INSTRUCTION_EXEC(iinc)
{
  int val = frame->localvars->get_int (frame->localvars, frame->localvars->_operand._index.index);
  val += frame->localvars->_operand._const;
  frame->localvars->set_int (frame->localvars, frame->localvars->_operand._index.index, val);
  return 0;
}

INSTRUCTION_EXEC(i2l)
{

}

INSTRUCTION_EXEC(i2f)
{

}

INSTRUCTION_EXEC(i2d)
{

}

INSTRUCTION_EXEC(l2i)
{

}

INSTRUCTION_EXEC(l2f)
{

}

INSTRUCTION_EXEC(l2d)
{

}

INSTRUCTION_EXEC(f2i)
{

}

INSTRUCTION_EXEC(f2l)
{

}

INSTRUCTION_EXEC(f2d)
{

}

INSTRUCTION_EXEC(d2i)
{

}

INSTRUCTION_EXEC(d2l)
{

}

INSTRUCTION_EXEC(d2f)
{

}

INSTRUCTION_EXEC(i2b)
{

}

INSTRUCTION_EXEC(i2c)
{

}

INSTRUCTION_EXEC(i2s)
{

}

INSTRUCTION_EXEC(lcmp)
{

}

INSTRUCTION_EXEC(fcmpl)
{

}

INSTRUCTION_EXEC(fcmpg)
{

}

INSTRUCTION_EXEC(dcmpl)
{

}

INSTRUCTION_EXEC(dcmpg)
{

}

INSTRUCTION_EXEC(ifeq)
{

}

INSTRUCTION_EXEC(ifne)
{

}

INSTRUCTION_EXEC(iflt)
{

}

INSTRUCTION_EXEC(ifge)
{

}

INSTRUCTION_EXEC(ifgt)
{

}

INSTRUCTION_EXEC(ifle)
{

}

INSTRUCTION_EXEC(if_icmpeq)
{

}

INSTRUCTION_EXEC(if_icmpne)
{

}

INSTRUCTION_EXEC(if_icmplt)
{

}

INSTRUCTION_EXEC(if_icmpge)
{
  int16_t offset = frame->localvars->_operand._index._offset;
  int val1, val2;
  pop2 (frame, &val1, &val2);
  if (val1 >= val2) {
    branch (frame, offset);
  }
  return 0;
}

INSTRUCTION_EXEC(if_icmpgt)
{

}

INSTRUCTION_EXEC(if_icmple)
{

}

INSTRUCTION_EXEC(if_acmpeq)
{

}

INSTRUCTION_EXEC(if_acmpne)
{

}

INSTRUCTION_EXEC(goto)
{
  branch (frame, frame->localvars->_operand._index._offset);
  return 0;
}

//decprecated
INSTRUCTION_EXEC(jsr)
{

}

//decprecated
INSTRUCTION_EXEC(ret)
{

}

INSTRUCTION_EXEC(tableswitch)
{

}

INSTRUCTION_EXEC(lookupswitch)
{

}

INSTRUCTION_EXEC(ireturn)
{

}

INSTRUCTION_EXEC(lreturn)
{

}

INSTRUCTION_EXEC(freturn)
{

}

INSTRUCTION_EXEC(dreturn)
{

}

INSTRUCTION_EXEC(areturn)
{

}

INSTRUCTION_EXEC(return)
{
  return -1;
}

INSTRUCTION_EXEC(getstatic)
{

}

INSTRUCTION_EXEC(putstatic)
{

}

INSTRUCTION_EXEC(getfield)
{

}

INSTRUCTION_EXEC(putfield)
{

}

INSTRUCTION_EXEC(invokevirtual)
{

}

INSTRUCTION_EXEC(invokespecial)
{

}

INSTRUCTION_EXEC(invokestatic)
{

}

INSTRUCTION_EXEC(invokeinterface)
{

}

INSTRUCTION_EXEC(invokedynamic)
{

}

INSTRUCTION_EXEC(new)
{

}

INSTRUCTION_EXEC(newarray)
{

}

INSTRUCTION_EXEC(anewarray)
{

}

INSTRUCTION_EXEC(arraylength)
{

}

INSTRUCTION_EXEC(athrow)
{

}

INSTRUCTION_EXEC(checkcast)
{

}

INSTRUCTION_EXEC(instanceof)
{

}

INSTRUCTION_EXEC(monitorenter)
{

}

INSTRUCTION_EXEC(monitorexit)
{

}

INSTRUCTION_EXEC(wide)
{

}

INSTRUCTION_EXEC(multianewarray)
{

}

INSTRUCTION_EXEC(ifnull)
{

}

INSTRUCTION_EXEC(ifnonnull)
{

}

INSTRUCTION_EXEC(goto_w)
{

}

INSTRUCTION_EXEC(jsr_w)
{

}

INSTRUCTION_EXEC(breakpoint)
{

}

INSTRUCTION_EXEC(impdepl)
{

}

Instruction instruction_table[] = {
    INSTRUCTION_NOP(nop),               //0x00
    INSTRUCTION_NOP(aconst_null),       //0x01
    INSTRUCTION_NOP(iconst_m1),         //0x02
    INSTRUCTION_NOP(iconst_0),          //0x03
    INSTRUCTION_NOP(iconst_1),          //0x04
    INSTRUCTION_NOP(iconst_2),          //0x05
    INSTRUCTION_NOP(iconst_3),          //0x06
    INSTRUCTION_NOP(iconst_4),          //0x07
    INSTRUCTION_NOP(iconst_5),          //0x08
    INSTRUCTION_NOP(lconst_0),          //0x09
    INSTRUCTION_NOP(lconst_1),          //0x0a
    INSTRUCTION_NOP(fconst_0),          //0x0b
    INSTRUCTION_NOP(fconst_1),          //0x0c
    INSTRUCTION_NOP(fconst_2),          //0x0d
    INSTRUCTION_NOP(dconst_0),          //0x0e
    INSTRUCTION_NOP(dconst_1),          //0x0f
    INSTRUCTION_INT8(bipush),           //0x10
    INSTRUCTION_INT16(sipush),          //0x11
    INSTRUCTION_INDEX8(ldc),            //0x12
    INSTRUCTION_INDEX16(ldc_w),         //0x13
    INSTRUCTION_INDEX16(ldc2_w),        //0x14
    INSTRUCTION_INDEX8(iload),          //0x15
    INSTRUCTION_INDEX8(lload),          //0x16
    INSTRUCTION_INDEX8(fload),          //0x17
    INSTRUCTION_INDEX8(dload),          //0x18
    INSTRUCTION_INDEX8(aload),          //0x19
    INSTRUCTION_NOP(iload_0),           //0x1a
    INSTRUCTION_NOP(iload_1),           //0x1b
    INSTRUCTION_NOP(iload_2),           //0x1c
    INSTRUCTION_NOP(iload_3),           //0x1d
    INSTRUCTION_NOP(lload_0),           //0x1e
    INSTRUCTION_NOP(lload_1),           //0x1f
    INSTRUCTION_NOP(lload_2),           //0x20
    INSTRUCTION_NOP(lload_3),           //0x21
    INSTRUCTION_NOP(fload_0),           //0x22
    INSTRUCTION_NOP(fload_1),           //0x23
    INSTRUCTION_NOP(fload_2),           //0x24
    INSTRUCTION_NOP(fload_3),           //0x25
    INSTRUCTION_NOP(dload_0),           //0x26
    INSTRUCTION_NOP(dload_1),           //0x27
    INSTRUCTION_NOP(dload_2),           //0x28
    INSTRUCTION_NOP(dload_3),           //0x29
    INSTRUCTION_NOP(aload_0),           //0x2a
    INSTRUCTION_NOP(aload_1),           //0x2b
    INSTRUCTION_NOP(aload_2),           //0x2c
    INSTRUCTION_NOP(aload_3),           //0x2d
    INSTRUCTION_NOP(iaload),            //0x2e
    INSTRUCTION_NOP(laload),            //0x2f
    INSTRUCTION_NOP(faload),            //0x30
    INSTRUCTION_NOP(daload),            //0x31
    INSTRUCTION_NOP(aaload),            //0x32
    INSTRUCTION_NOP(baload),            //0x33
    INSTRUCTION_NOP(caload),            //0x34
    INSTRUCTION_NOP(saload),            //0x35
    INSTRUCTION_INDEX8(istore),         //0x36
    INSTRUCTION_INDEX8(lstore),         //0x37
    INSTRUCTION_INDEX8(fstore),         //0x38
    INSTRUCTION_INDEX8(dstore),         //0x39
    INSTRUCTION_INDEX8(astore),         //0x3a
    INSTRUCTION_NOP(istore_0),          //0x3b
    INSTRUCTION_NOP(istore_1),          //0x3c
    INSTRUCTION_NOP(istore_2),          //0x3d
    INSTRUCTION_NOP(istore_3),          //0x3e
    INSTRUCTION_NOP(lstore_0),          //0x3f
    INSTRUCTION_NOP(lstore_1),          //0x40
    INSTRUCTION_NOP(lstore_2),          //0x41
    INSTRUCTION_NOP(lstore_3),          //0x42
    INSTRUCTION_NOP(fstore_0),          //0x43
    INSTRUCTION_NOP(fstore_1),          //0x44
    INSTRUCTION_NOP(fstore_2),          //0x45
    INSTRUCTION_NOP(fstore_3),          //0x46
    INSTRUCTION_NOP(dstore_0),          //0x47
    INSTRUCTION_NOP(dstore_1),          //0x48
    INSTRUCTION_NOP(dstore_2),          //0x49
    INSTRUCTION_NOP(dstore_3),          //0x4a
    INSTRUCTION_NOP(astore_0),          //0x4b
    INSTRUCTION_NOP(astore_1),          //0x4c
    INSTRUCTION_NOP(astore_2),          //0x4d
    INSTRUCTION_NOP(astore_3),          //0x4e
    INSTRUCTION_NOP(iastore),           //0x4f
    INSTRUCTION_NOP(lastore),           //0x50
    INSTRUCTION_NOP(fastore),           //0x51
    INSTRUCTION_NOP(dastore),           //0x52
    INSTRUCTION_NOP(aastore),           //0x53
    INSTRUCTION_NOP(bastore),           //0x54
    INSTRUCTION_NOP(castore),           //0x55
    INSTRUCTION_NOP(sastore),           //0x56
    INSTRUCTION_NOP(pop),               //0x57
    INSTRUCTION_NOP(pop2),              //0x58
    INSTRUCTION_NOP(dup),               //0x59
    INSTRUCTION_NOP(dup_x1),            //0x5a
    INSTRUCTION_NOP(dup_x2),            //0x5b
    INSTRUCTION_NOP(dup2),              //0x5c
    INSTRUCTION_NOP(dup2_x1),           //0x5d
    INSTRUCTION_NOP(dup2_x2),           //0x5e
    INSTRUCTION_NOP(swap),              //0x5f
    INSTRUCTION_NOP(iadd),              //0x60
    INSTRUCTION_NOP(ladd),              //0x61
    INSTRUCTION_NOP(fadd),              //0x62
    INSTRUCTION_NOP(dadd),              //0x63
    INSTRUCTION_NOP(isub),              //0x64
    INSTRUCTION_NOP(lsub),              //0x65
    INSTRUCTION_NOP(fsub),              //0x66
    INSTRUCTION_NOP(dsub),              //0x67

    INSTRUCTION_NOP(imul),              //0x68
    INSTRUCTION_NOP(lmul),              //0x69
    INSTRUCTION_NOP(fmul),              //0x6a
    INSTRUCTION_NOP(dmul),              //0x6b

    INSTRUCTION_NOP(idiv),              //0x6c
    INSTRUCTION_NOP(ldiv),              //0x6d
    INSTRUCTION_NOP(fdiv),              //0x6e
    INSTRUCTION_NOP(ddiv),              //0x6f

    INSTRUCTION_NOP(irem),              //0x70
    INSTRUCTION_NOP(lrem),              //0x71
    INSTRUCTION_NOP(frem),              //0x72
    INSTRUCTION_NOP(drem),              //0x73

    INSTRUCTION_NOP(ineg),              //0x74
    INSTRUCTION_NOP(lneg),              //0x75
    INSTRUCTION_NOP(fneg),              //0x76
    INSTRUCTION_NOP(dneg),              //0x77

    INSTRUCTION_NOP(ishl),              //0x78
    INSTRUCTION_NOP(lshl),              //0x79

    INSTRUCTION_NOP(ishr),              //0x7a
    INSTRUCTION_NOP(lshr),              //0x7b

    INSTRUCTION_NOP(iushr),             //0x7c
    INSTRUCTION_NOP(lushr),             //0x7d

    INSTRUCTION_NOP(iand),              //0x7e
    INSTRUCTION_NOP(land),              //0x7f

    INSTRUCTION_NOP(ior),               //0x80
    INSTRUCTION_NOP(lor),               //0x81
    INSTRUCTION_NOP(ixor),              //0x82
    INSTRUCTION_NOP(lxor),              //0x83

    INSTRUCTION_IINC(iinc),             //0x84

    INSTRUCTION_NOP(i2l),               //0x85
    INSTRUCTION_NOP(i2f),               //0x86
    INSTRUCTION_NOP(i2d),               //0x87

    INSTRUCTION_NOP(l2i),               //0x88
    INSTRUCTION_NOP(l2f),               //0x89
    INSTRUCTION_NOP(l2d),               //0x8a

    INSTRUCTION_NOP(f2i),               //0x8b
    INSTRUCTION_NOP(f2l),               //0x8c
    INSTRUCTION_NOP(f2d),               //0x8d

    INSTRUCTION_NOP(d2i),               //0x8e
    INSTRUCTION_NOP(d2l),               //0x8f
    INSTRUCTION_NOP(d2f),               //0x90

    INSTRUCTION_NOP(i2b),               //0x91
    INSTRUCTION_NOP(i2c),               //0x92
    INSTRUCTION_NOP(i2s),               //0x93

    INSTRUCTION_NOP(lcmp),              //0x94
    INSTRUCTION_NOP(fcmpl),             //0x95
    INSTRUCTION_NOP(fcmpg),             //0x96
    INSTRUCTION_NOP(dcmpl),             //0x97
    INSTRUCTION_NOP(dcmpg),             //0x98

    INSTRUCTION_INT16(ifeq),            //0x99
    INSTRUCTION_INT16(ifne),            //0x9a
    INSTRUCTION_INT16(iflt),            //0x9b
    INSTRUCTION_INT16(ifge),            //0x9c
    INSTRUCTION_INT16(ifgt),            //0x9d
    INSTRUCTION_INT16(ifle),            //0x9e

    INSTRUCTION_INT16(if_icmpeq),       //0x9f
    INSTRUCTION_INT16(if_icmpne),       //0xa0
    INSTRUCTION_INT16(if_icmplt),       //0xa1
    INSTRUCTION_INT16(if_icmpge),       //0xa2
    INSTRUCTION_INT16(if_icmpgt),       //0xa3
    INSTRUCTION_INT16(if_icmple),       //0xa4
    INSTRUCTION_INT16(if_acmpeq),       //0xa5
    INSTRUCTION_INT16(if_acmpne),       //0xa6

    INSTRUCTION_INT16(goto),            //0xa7
    INSTRUCTION_UNSUPPORTED(jsr),       //0xa8
    INSTRUCTION_UNSUPPORTED(ret),       //0xa9
    INSTRUCTION_TABLESWITCH(tableswitch),//0xaa
    INSTRUCTION_LOOKSWITCH(lookupswitch),//0xab

    INSTRUCTION_NOP(ireturn),           //0xac
    INSTRUCTION_NOP(lreturn),           //0xad
    INSTRUCTION_NOP(freturn),           //0xae
    INSTRUCTION_NOP(dreturn),           //0xaf
    INSTRUCTION_NOP(areturn),           //0xb0
    INSTRUCTION_NOP(return),            //0xb1

    INSTRUCTION_INDEX16(getstatic),     //0xb2
    INSTRUCTION_INDEX16(putstatic),     //0xb3
    INSTRUCTION_INDEX16(getfield),      //0xb4
    INSTRUCTION_INDEX16(putfield),      //0xb5

    INSTRUCTION_INDEX16(invokevirtual), //0xb6
    INSTRUCTION_INDEX16(invokespecial), //0xb7
    INSTRUCTION_INDEX16(invokestatic),  //0xb8
    INSTRUCTION_INVOKE_INTERFACE(invokeinterface),//0xb9
    INSTRUCTION_UNSUPPORTED(invokedynamic),        //0xba

    INSTRUCTION_INDEX16(new),            //0xbb
    INSTRUCTION_NEWARRAY(newarray),     //0xbc
    INSTRUCTION_INDEX16(anewarray),     //0xbd

    INSTRUCTION_NOP(arraylength),       //0xbe
    INSTRUCTION_NOP(athrow),            //0xbf
    INSTRUCTION_INDEX16(checkcast),    //0xc0
    INSTRUCTION_INDEX16(instanceof),   //0xc1
    INSTRUCTION_NOP(monitorenter),      //0xc2
    INSTRUCTION_NOP(monitorexit),       //0xc3
    INSTRUCTION_WIDE(wide),         //0xc4
    INSTRUCTION_MULTIANEWARRAY(multianewarray),//0xc5
    INSTRUCTION_INT16(ifnull),       //0xc6
    INSTRUCTION_INT16(ifnonnull),    //0xc7
    INSTRUCTION_INT32(goto_w),       //0xc8
    INSTRUCTION_UNSUPPORTED(jsr_w),        //0xc9
    INSTRUCTION_UNSUPPORTED(breakpoint),   //0xca

    //......

    INSTRUCTION_UNSUPPORTED(impdepl),      //0xfe
    INSTRUCTION_UNSUPPORTED(impdepl),      //0xff
};
