//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_BYTECODE_READER_H
#define UNTITLED2_BYTECODE_READER_H

struct vm_bytecode_reader {
    char *buf;

    int index;

    int size;
};

uint8_t vm_read_8bit(struct vm_bytecode_reader *reader);

uint16_t vm_read_16bit(struct vm_bytecode_reader *reader);

uint32_t vm_read_32bit(struct vm_bytecode_reader *reader);

uint8_t *vm_read_bytes(struct vm_bytecode_reader *reader, int bytes);

uint16_t vm_read_constant_pool_size(struct vm_bytecode_reader *reader);

struct vm_bytecode_reader *new_bytecode_reader(char *bytecode, uint32_t len);

#endif //UNTITLED2_BYTECODE_READER_H
