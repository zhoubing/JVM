//
// Created by zhoubing on 2017/7/6.
//

#ifndef UNTITLED2_CLASSPATH_H
#define UNTITLED2_CLASSPATH_H

#include "runtime/frame.h"
#include "entry.h"

typedef struct ByteCodeReader ByteCodeReader;
typedef struct classpath {
    ByteCodeReader *(*readClass)(Entry *class_entry);
} ClassPath;

#endif //UNTITLED2_CLASSPATH_H