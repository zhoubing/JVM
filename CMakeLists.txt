cmake_minimum_required(VERSION 3.7)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cmd.c cmd.h constant_pool.c runtime/localvars.c runtime/localvars.h constant_pool.h access_token.c access_token.h attribute_info.c attribute_info.h bytecode_reader.c bytecode_reader.h utility.h class.c class.h access_flag.h main.c utility.c type_system/object.c type_system/object.h runtime/thread.c runtime/thread.h runtime/vmstack.c runtime/vmstack.h runtime/frame.c runtime/frame.h runtime/instructions.c runtime/instructions.h runtime/interpreter.c runtime/interpreter.h classpath.c classpath.h entry.c entry.h kernel/nvm_typedef.h runtime/operandstack.c runtime/operandstack.h opcode/opcode.c opcode/opcode.h opcode/constants.c opcode/constants.h opcode/loads.c opcode/loads.h opcode/stores.c opcode/stores.h opcode/stack.c opcode/stack.h opcode/math.c opcode/math.h opcode/conversions.c opcode/conversions.h opcode/comparisions.c opcode/comparisions.h opcode/control.c opcode/control.h opcode/references.c opcode/references.h opcode/extended.c opcode/extended.h opcode/reserved.c opcode/reserved.h)
add_executable(untitled2 ${SOURCE_FILES})