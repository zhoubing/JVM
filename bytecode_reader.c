//
// Created by zhoubing on 2017/6/12.
//

#include <memory.h>
#include <stdlib.h>
#include "bytecode_reader.h"

uint8_t read8bit(ByteCodeReader *reader) {
    uint8_t val = 0;
    memcpy(&val, reader->buf + reader->index, sizeof(uint8_t));
    //reader->buf += sizeof(uint8_t);
    val &= 0xff;
    reader->index += sizeof(uint8_t);
    return val;
}

uint16_t read16bit(ByteCodeReader *reader) {
    uint16_t val = 0;
    uint8_t high = read8bit(reader);
    uint8_t low = read8bit(reader);
    val |= low;
    val |= high << 8;
    val &= 0xffff;
    return val;
}

uint32_t read32bit(ByteCodeReader *reader) {
    uint32_t val = 0;
    uint16_t high = read16bit(reader);
    uint16_t low = read16bit(reader);
    val |= low;
    val |= high << 16;
    val &= 0xffffffff;
    return val;
}

uint8_t *read_bytes(ByteCodeReader *reader, int bytes) {
    size_t len = bytes * sizeof(uint8_t);
    uint8_t *str = (uint8_t *) malloc(len);
    //指针指向原数据还是重新分配内存拷贝出来？
    memcpy(str, reader->buf + reader->index, len);
    reader->index += len;
    return str;
}

ByteCodeReader *new_bytecode_reader(char *bytecode, uint32_t len) {
    ByteCodeReader *reader = malloc(sizeof(ByteCodeReader));
    reader->buf = bytecode;
    reader->size = len;
    reader->index = 0;
    reader->read_16bit = read16bit;
    reader->read_32bit = read32bit;
    reader->read_8bit = read8bit;
    reader->read_bytes = read_bytes;
    return reader;
}