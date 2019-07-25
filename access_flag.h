//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_ACCESS_FLAG_H
#define UNTITLED2_ACCESS_FLAG_H

typedef enum access_flag AccessFlag;

enum access_flag {
    ACC_PUBLIC = 0x0001,
    ACC_PRIVATE = 0x0002,
    ACC_PROTECTED = 0x0004,
    ACC_STATIC = 0x0008,
    ACC_FINAL = 0x0010,
    ACC_SUPER = 0x0020,  /*1.0.2版本之后此位永远为1*/
    ACC_VOLATILE = 0x0040,
    ACC_TRANSIENT = 0x0080,
    ACC_INTERFACE = 0x0200,
    ACC_ABSTRACT = 0x0400,
    ACC_SYNTHETIC = 0x1000,
    ACC_ANNOTATION = 0x2000,
    ACC_ENUM = 0x4000
};

#endif //UNTITLED2_ACCESS_FLAG_H
