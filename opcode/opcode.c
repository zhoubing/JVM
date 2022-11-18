//
// Created by zhoubing on 2022/11/17.
//

#include "opcode.h"

#include "constants.h"
#include "loads.h"
#include "stores.h"
#include "stack.h"
#include "math.h"
#include "conversions.h"
#include "comparisions.h"
#include "control.h"
#include "references.h"
#include "extended.h"
#include "reserved.h"

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
        //0x56
        {Read_sastore, Run_sastore},
        //0x57
        {Read_pop, Run_pop},
        //0x58
        {Read_pop2, Run_pop2},
        //0x59
        {Read_dup, Run_dup},
        //0x5a
        {Read_dup_x1, Run_dup_x1},
        //0x5b
        {Read_dup_x2, Run_dup_x2},
        //0x5c
        {Read_dup2, Run_dup2},
        //0x5d
        {Read_dup2_x1, Run_dup2_x1},
        //0x5e
        {Read_dup2_x2, Run_dup2_x2},
        //0x5f
        {Read_swap, Run_swap},
        //0x60
        {Read_iadd, Run_iadd},
        //0x61
        {Read_ladd, Run_ladd},
        //0x62
        {Read_fadd, Run_fadd},
        //0x63
        {Read_dadd, Run_dadd},
        //0x64
        {Read_isub, Run_isub},
        //0x65
        {Read_lsub, Run_lsub},
        //0x66
        {Read_lsub, Run_fsub},
        //0x67
        {Read_dsub, Run_dsub},
        //0x68
        {Read_imul, Run_imul},
        //0x69
        {Read_lmul, Run_lmul},
        //0x6a
        {Read_fmul, Run_fmul},
        //0x6b
        {Read_dmul, Run_dmul},
        //0x6c
        {Read_idiv, Run_idiv},
        //0x6d
        {Read_ldiv, Run_ldiv},
        //0x6e
        {Read_fdiv, Run_fdiv},
        //0x6f
        {Read_ddiv, Run_ddiv},
        //0x70
        {Read_irem, Run_irem},
        //0x71
        {Read_lrem, Run_lrem},
        //0x72
        {Read_frem, Run_frem},
        //0x73
        {Read_drem, Run_drem},
        //0x74
        {Read_ineg, Run_ineg},
        //0x75
        {Read_lneg, Run_lneg},
        //0x76
        {Read_fneg, Run_fneg},
        //0x77
        {Read_dneg, Run_dneg},
        //0x78
        {Read_ishl, Run_ishl},
        //0x79
        {Read_lshl, Run_lshl},
        //0x7a
        {Read_ishr, Run_ishr},
        //0x7b
        {Read_lshr, Run_lshr},
        //0x7c
        {Read_iushr, Run_iushr},
        //0x7d
        {Read_lushr, Run_lushr},
        //0x7e
        {Read_iand, Run_iand},
        //0x7f
        {Read_land, Run_land},
        //0x80
        {Read_ior, Run_ior},
        //0x81
        {Read_lor, Run_lor},
        //0x82
        {Read_ixor, Run_ixor},
        //0x83
        {Read_lxor, Run_lxor},
        //0x84
        {Read_iinc, Run_iinc},
        //0x85
        {Read_i2l, Run_i2l},
        //0x86
        {Read_i2f, Run_i2f},
        //0x87
        {Read_i2d, Run_i2d},
        //0x88
        {Read_l2i, Run_l2i},
        //0x89
        {Read_l2f, Run_l2f},
        //0x8a
        {Read_l2d, Run_l2d},
        //0x8b
        {Read_f2i, Run_f2i},
        //0x8c
        {Read_f2l, Run_f2l},
        //0x8d
        {Read_f2d, Run_f2d},
        //0x8e
        {Read_d2i, Run_d2i},
        //0x8f
        {Read_d2l, Run_d2l},
        //0x90
        {Read_d2f, Run_d2f},
        //0x91
        {Read_i2b, Run_i2b},
        //0x92
        {Read_i2c, Run_i2s},
        //0x93
        {Read_i2s, Run_i2s},
        //0x94
        {Read_lcmp, Run_lcmp},
        //0x95
        {Read_fcmpl, Run_fcmpl},
        //0x96
        {Read_fcmpg, Run_fcmpg},
        //0x97
        {Read_dcmpl, Run_dcmpl},
        //0x98
        {Read_dcmpg, Run_dcmpg},
        //0x99
        {Read_ifeq, Run_ifeq},
        //0x9a
        {Read_ifne, Run_ifne},
        //0x9b
        {Read_iflt, Run_iflt},
        //0x9c
        {Read_ifge, Run_ifge},
        //0x9d
        {Read_ifgt, Run_ifgt},
        //0x9e
        {Read_ifle, Run_ifle},
        //0x9f
        {Read_if_icmpeq, Run_if_icmpeq},
        //0xa0
        {Read_if_icmpne, Run_if_icmpne},
        //0xa1
        {Read_if_icmplt, Run_if_icmplt},
        //0xa2
        {Read_if_icmpge, Run_if_icmpge},
        //0xa3
        {Read_if_icmpgt, Run_if_icmpgt},
        //0xa4
        {Read_if_icmple, Run_if_icmple},
        //0xa5
        {Read_if_acmpeq, Run_if_acmpeq},
        //0xa6
        {Read_if_acmpne, Run_if_acmpne},
        //0xa7
        {Read_goto, Run_goto},
        //0xa8
        {Read_jsr, Run_jsr},
        //0xa9
        {Read_ret, Run_ret},
        //0xaa
        {Read_tableswitch, Run_tableswitch},
        //0xab
        {Read_lookupswitch, Run_lookupswitch},
        //0xac
        {Read_ireturn, Run_ireturn},
        //0xad
        {Read_lreturn, Run_lreturn},
        //0xae
        {Read_freturn, Run_freturn},
        //0xaf
        {Read_dreturn, Run_dreturn},
        //0xb0
        {Read_areturn, Run_areturn},
        //0xb1
        {Read_return, Run_return},
        //0xb2
        {Read_getstatic, Run_getstatic},
        //0xb3
        {Read_putstatic, Run_putstatic},
        //0xb4
        {Read_getfield, Run_getfield},
        //0xb5
        {Read_putfield, Run_putfield},
        //0xb6
        {Read_invokevirtual, Run_invokevirtual},
        //0xb7
        {Read_invokespecial, Run_invokespecial},
        //0xb8
        {Read_invokestatic, Run_invokestatic},
        //0xb9
        {Read_invokeinterface, Run_invokeinterface},
        //0xba
        {Read_invokedynamic, Run_invokedynamic},
        //0xbb
        {Read_new, Run_new},
        //0xbc
        {Read_newarray, Run_newarray},
        //0xbd
        {Read_anewarray, Run_anewarray},
        //0xbe
        {Read_arraylength, Run_arraylength},
        //0xbf
        {Read_athrow, Run_athrow},
        //0xc0
        {Read_checkcast, Run_checkcast},
        //0xc1
        {Read_instanceof, Run_instanceof},
        //0xc2
        {Read_monitorenter, Run_monitorenter},
        //0xc3
        {Read_monitorexit, Run_monitorexit},
        //0xc4
        {Read_wide, Run_wide},
        //0xc5
        {Read_multianewarray, Run_multianewarray},
        //0xc6
        {Read_ifnull, Run_ifnull},
        //0xc7
        {Read_ifnonnull, Run_ifnonnull},
        //0xc8
        {Read_goto_w, Run_goto_w},
        //0xc9
        {Read_jsr_w, Run_jsr_w},
        //0xca
        {Read_breakpoint, Run_breakpoint},


//        void Read_impdep1(Frame *frame);
//
//        int Run_impdep1(Frame *frame);
//
//        void Read_impdep2(Frame *frame);
//
//        int Run_impdep2(Frame *frame);

};