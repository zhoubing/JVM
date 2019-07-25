cmake_minimum_required(VERSION 3.7)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES cmd.c cmd.h constant_pool.c constant_pool.h access_token.c access_token.h attribute_info.c attribute_info.h bytecode_reader.c bytecode_reader.h utility.h class.c class.h access_flag.h main.c utility.c type_system/object.c type_system/object.h runtime/vmthread.c runtime/vmthread.h runtime/vmstack.c runtime/vmstack.h runtime/frame.c runtime/frame.h runtime/instructions.c runtime/instructions.h runtime/interpreter.c runtime/interpreter.h classpath.c classpath.h entry.c entry.h)
add_executable(untitled2 ${SOURCE_FILES})