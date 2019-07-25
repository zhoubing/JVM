//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_BYTECODE_READER_H
#define UNTITLED2_BYTECODE_READER_H

typedef struct bytecode_reader ByteCodeReader;

struct bytecode_reader {
    char *buf;

    int index;

    int size;

    uint8_t (*read_8bit)(ByteCodeReader *reader);

    uint16_t (*read_16bit)(ByteCodeReader *reader);

    uint32_t (*read_32bit)(ByteCodeReader *reader);

    uint8_t *(*read_bytes)(ByteCodeReader *reader, int bytes);

    uint16_t (*read_constant_pool_size)(ByteCodeReader *reader);
};

ByteCodeReader *new_bytecode_reader(char *bytecode, uint32_t len);

#endif //UNTITLED2_BYTECODE_READER_H
