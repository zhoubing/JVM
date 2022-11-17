//
// Created by zhoubing on 2022/11/17.
//

#include "opcode.h"

#include "constants.h"
#include "loads.h"
#include "stores.h"

OpCode opcode_sets[] = {
        //0x00
        {Read_noop, Run_noop},
        //0x01
        {Read_aconst_null, Run_aconst_null},
        //0x02
        {Read_iconst_m1, Run_iconst_m1},
        //0x03
        {Read_iconst_0, Run_iconst_0},
        //0x04
        {Read_iconst_1, Run_iconst_1},
        //0x05
        {Read_iconst_2, Run_iconst_2},
        //0x06
        {Read_iconst_3, Run_iconst_3},
        //0x07
        {Read_iconst_4, Run_iconst_4},
        //0x08
        {Read_iconst_5, Run_iconst_5},
        //0x09
        {Read_lconst_0, Run_lconst_0},
        //0x0a
        {Read_lconst_1, Run_lconst_1},
        //0x0b
        {Read_fconst_0, Run_fconst_0},
        //0x0c
        {Read_fconst_1, Run_fconst_1},
        //0x0d
        {Read_fconst_2, Run_fconst_2},
        //0x0e
        {Read_dconst_0, Run_dconst_0},
        //0x0f
        {Read_dconst_1, Run_dconst_1},
        //0x10
        {Read_bipush, Run_bipush},
        //0x11
        {Read_sipush, Run_sipush},
        //0x12
        {Read_ldc, Run_ldc},
        //0x13
        {Read_ldc_w, Run_ldc_w},
        //0x14
        {Read_ldc2_w, Run_ldc2_w},
        //0x15
        {Read_iload, Run_iload},
        //0x16
        {Read_lload, Run_lload},
        //0x17
        {Read_fload, Run_fload},
        //0x18
        {Read_dload, Run_dload},
        //0x19
        {Read_aload, Run_aload},
        //0x1a
        {Read_iload_0, Run_iload_0},
        //0x1b
        {Read_iload_1, Run_iload_1},
        //0x1c
        {Read_iload_2, Run_iload_2},
        //0x1d
        {Read_iload_3, Run_iload_3},
        //0x1e
        {Read_lload_0, Run_lload_0},
        //0x1f
        {Read_lload_1, Run_lload_1},
        //0x20
        {Read_lload_2, Run_lload_2},
        //0x21
        {Read_lload_3, Run_lload_3},
        //0x22
        {Read_fload_0, Run_fload_0},
        //0x23
        {Read_fload_1, Run_fload_1},
        //0x24
        {Read_fload_2, Run_fload_2},
        //0x25
        {Read_fload_3, Run_fload_3},
        //0x26
        {Read_dload_0, Run_dload_0},
        //0x27
        {Read_dload_1, Run_dload_1},
        //0x28
        {Read_dload_2, Run_dload_2},
        //0x29
        {Read_dload_3, Run_dload_3},
        //0x2a
        {Read_aload_0, Run_aload_0},
        //0x2b
        {Read_aload_1, Run_aload_1},
        //0x2c
        {Read_aload_2, Run_aload_2},
        //0x2d
        {Read_aload_3, Run_aload_3},
        //0x2e
        {Read_iaload, Run_iaload},
        //0x2f
        {Read_laload, Run_laload},
        //0x30
        {Read_faload, Run_faload},
        //0x31
        {Read_daload, Run_daload},
        //0x32
        {Read_aaload, Run_aaload},
        //0x33
        {Read_baload, Run_baload},
        //0x34
        {Read_caload, Run_caload},
        //0x35
        {Read_saload, Run_saload},
        //0x36
        {Read_istore, Run_istore},
        //0x37
        {Read_lstore, Run_lstore},
        //0x38
        {Read_fstore, Run_fstore},
        //0x39
        {Read_dstore, Run_dstore},
        //0x3a
        {Read_astore, Run_astore},
        //0x3b
        {Read_istore_0, Run_istore_0},
        //0x3c
        {Read_istore_1, Run_istore_1},
        //0x3d
        {Read_istore_2, Run_istore_2},
        //0x3e
        {Read_istore_3, Run_istore_3},
        //0x3f
        {Read_lstore_0, Run_lstore_0},
        //0x40
        {Read_lstore_1, Run_lstore_1},
        //0x41
        {Read_lstore_2, Run_lstore_2},
        //0x42
        {Read_lstore_3, Run_lstore_3},
        //0x43
        {Read_fstore_0, Run_fstore_0},
        //0x44
        {Read_fstore_1, Run_fstore_1},
        //0x45
        {Read_fstore_2, Run_fstore_2},
        //0x46
        {Read_fstore_3, Run_fstore_3},
        //0x47
        {Read_dstore_0, Run_dstore_0},
        //0x48
        {Read_dstore_1, Run_dstore_1},
        //0x49
        {Read_dstore_2, Run_dstore_2},
        //0x4a
        {Read_dstore_3, Run_dstore_3},
        //0x4b
        {Read_astore_0, Run_astore_0},
        //0x4c
        {Read_astore_1, Run_astore_1},
        //0x4d
        {Read_astore_2, Run_astore_2},
        //0x4e
        {Read_astore_3, Run_astore_3},
        //0x4f
        {Read_iastore, Run_iastore},
        //0x50
        {Read_lastore, Run_lastore},
        //0x51
        {Read_fastore, Run_fastore},
        //0x52
        {Read_dastore, Run_dastore},
        //0x53
        {Read_aastore, Run_aastore},
        //0x54
        {Read_bastore, Run_bastore},
        //0x55
        {Read_castore, Run_castore},
        //0x55
        {Read_sastore, Run_sastore},

//        INSTRUCTION_NOP(pop),               //0x57
//        INSTRUCTION_NOP(pop2),              //0x58
//        INSTRUCTION_NOP(dup),               //0x59
//        INSTRUCTION_NOP(dup_x1),            //0x5a
//        INSTRUCTION_NOP(dup_x2),            //0x5b
//        INSTRUCTION_NOP(dup2),              //0x5c
//        INSTRUCTION_NOP(dup2_x1),           //0x5d
//        INSTRUCTION_NOP(dup2_x2),           //0x5e
//        INSTRUCTION_NOP(swap),              //0x5f
//        INSTRUCTION_NOP(iadd),              //0x60
//        INSTRUCTION_NOP(ladd),              //0x61
//        INSTRUCTION_NOP(fadd),              //0x62
//        INSTRUCTION_NOP(dadd),              //0x63
//        INSTRUCTION_NOP(isub),              //0x64
//        INSTRUCTION_NOP(lsub),              //0x65
//        INSTRUCTION_NOP(fsub),              //0x66
//        INSTRUCTION_NOP(dsub),              //0x67
//
//        INSTRUCTION_NOP(imul),              //0x68
//        INSTRUCTION_NOP(lmul),              //0x69
//        INSTRUCTION_NOP(fmul),              //0x6a
//        INSTRUCTION_NOP(dmul),              //0x6b
//
//        INSTRUCTION_NOP(idiv),              //0x6c
//        INSTRUCTION_NOP(ldiv),              //0x6d
//        INSTRUCTION_NOP(fdiv),              //0x6e
//        INSTRUCTION_NOP(ddiv),              //0x6f
//
//        INSTRUCTION_NOP(irem),              //0x70
//        INSTRUCTION_NOP(lrem),              //0x71
//        INSTRUCTION_NOP(frem),              //0x72
//        INSTRUCTION_NOP(drem),              //0x73
//
//        INSTRUCTION_NOP(ineg),              //0x74
//        INSTRUCTION_NOP(lneg),              //0x75
//        INSTRUCTION_NOP(fneg),              //0x76
//        INSTRUCTION_NOP(dneg),              //0x77
//
//        INSTRUCTION_NOP(ishl),              //0x78
//        INSTRUCTION_NOP(lshl),              //0x79
//
//        INSTRUCTION_NOP(ishr),              //0x7a
//        INSTRUCTION_NOP(lshr),              //0x7b
//
//        INSTRUCTION_NOP(iushr),             //0x7c
//        INSTRUCTION_NOP(lushr),             //0x7d
//
//        INSTRUCTION_NOP(iand),              //0x7e
//        INSTRUCTION_NOP(land),              //0x7f
//
//        INSTRUCTION_NOP(ior),               //0x80
//        INSTRUCTION_NOP(lor),               //0x81
//        INSTRUCTION_NOP(ixor),              //0x82
//        INSTRUCTION_NOP(lxor),              //0x83
//
//        INSTRUCTION_IINC(iinc),             //0x84
//
//        INSTRUCTION_NOP(i2l),               //0x85
//        INSTRUCTION_NOP(i2f),               //0x86
//        INSTRUCTION_NOP(i2d),               //0x87
//
//        INSTRUCTION_NOP(l2i),               //0x88
//        INSTRUCTION_NOP(l2f),               //0x89
//        INSTRUCTION_NOP(l2d),               //0x8a
//
//        INSTRUCTION_NOP(f2i),               //0x8b
//        INSTRUCTION_NOP(f2l),               //0x8c
//        INSTRUCTION_NOP(f2d),               //0x8d
//
//        INSTRUCTION_NOP(d2i),               //0x8e
//        INSTRUCTION_NOP(d2l),               //0x8f
//        INSTRUCTION_NOP(d2f),               //0x90
//
//        INSTRUCTION_NOP(i2b),               //0x91
//        INSTRUCTION_NOP(i2c),               //0x92
//        INSTRUCTION_NOP(i2s),               //0x93
//
//        INSTRUCTION_NOP(lcmp),              //0x94
//        INSTRUCTION_NOP(fcmpl),             //0x95
//        INSTRUCTION_NOP(fcmpg),             //0x96
//        INSTRUCTION_NOP(dcmpl),             //0x97
//        INSTRUCTION_NOP(dcmpg),             //0x98
//
//        INSTRUCTION_INT16(ifeq),            //0x99
//        INSTRUCTION_INT16(ifne),            //0x9a
//        INSTRUCTION_INT16(iflt),            //0x9b
//        INSTRUCTION_INT16(ifge),            //0x9c
//        INSTRUCTION_INT16(ifgt),            //0x9d
//        INSTRUCTION_INT16(ifle),            //0x9e
//
//        INSTRUCTION_INT16(if_icmpeq),       //0x9f
//        INSTRUCTION_INT16(if_icmpne),       //0xa0
//        INSTRUCTION_INT16(if_icmplt),       //0xa1
//        INSTRUCTION_INT16(if_icmpge),       //0xa2
//        INSTRUCTION_INT16(if_icmpgt),       //0xa3
//        INSTRUCTION_INT16(if_icmple),       //0xa4
//        INSTRUCTION_INT16(if_acmpeq),       //0xa5
//        INSTRUCTION_INT16(if_acmpne),       //0xa6
//
//        INSTRUCTION_INT16(goto),            //0xa7
//        INSTRUCTION_UNSUPPORTED(jsr),       //0xa8
//        INSTRUCTION_UNSUPPORTED(ret),       //0xa9
//        INSTRUCTION_TABLESWITCH(tableswitch),//0xaa
//        INSTRUCTION_LOOKSWITCH(lookupswitch),//0xab
//
//        INSTRUCTION_NOP(ireturn),           //0xac
//        INSTRUCTION_NOP(lreturn),           //0xad
//        INSTRUCTION_NOP(freturn),           //0xae
//        INSTRUCTION_NOP(dreturn),           //0xaf
//        INSTRUCTION_NOP(areturn),           //0xb0
//        INSTRUCTION_NOP(return),            //0xb1
//
//        INSTRUCTION_INDEX16(getstatic),     //0xb2
//        INSTRUCTION_INDEX16(putstatic),     //0xb3
//        INSTRUCTION_INDEX16(getfield),      //0xb4
//        INSTRUCTION_INDEX16(putfield),      //0xb5
//
//        INSTRUCTION_INDEX16(invokevirtual), //0xb6
//        INSTRUCTION_INDEX16(invokespecial), //0xb7
//        INSTRUCTION_INDEX16(invokestatic),  //0xb8
//        INSTRUCTION_INVOKE_INTERFACE(invokeinterface),//0xb9
//        INSTRUCTION_UNSUPPORTED(invokedynamic),        //0xba
//
//        INSTRUCTION_INDEX16(new),            //0xbb
//        INSTRUCTION_NEWARRAY(newarray),     //0xbc
//        INSTRUCTION_INDEX16(anewarray),     //0xbd
//
//        INSTRUCTION_NOP(arraylength),       //0xbe
//        INSTRUCTION_NOP(athrow),            //0xbf
//        INSTRUCTION_INDEX16(checkcast),    //0xc0
//        INSTRUCTION_INDEX16(instanceof),   //0xc1
//        INSTRUCTION_NOP(monitorenter),      //0xc2
//        INSTRUCTION_NOP(monitorexit),       //0xc3
//        INSTRUCTION_WIDE(wide),         //0xc4
//        INSTRUCTION_MULTIANEWARRAY(multianewarray),//0xc5
//        INSTRUCTION_INT16(ifnull),       //0xc6
//        INSTRUCTION_INT16(ifnonnull),    //0xc7
//        INSTRUCTION_INT32(goto_w),       //0xc8
//        INSTRUCTION_UNSUPPORTED(jsr_w),        //0xc9
//        INSTRUCTION_UNSUPPORTED(breakpoint),   //0xca
//
//        //......
//
//        INSTRUCTION_UNSUPPORTED(impdepl),      //0xfe
//        INSTRUCTION_UNSUPPORTED(impdepl),      //0xff
};