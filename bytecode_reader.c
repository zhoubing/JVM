//
// Created by zhoubing on 2017/6/12.
//

#include <memory.h>
#include <stdlib.h>
#include "bytecode_reader.h"
#include "utility.h"
#include "stdio.h"

uint8_t vm_read_8bit(struct vm_bytecode_reader *reader) {
    //printf("vm_read_8bit reader->index: %d\n", reader->index);
    uint8_t val = 0;
    memcpy(&val, reader->buf + reader->index, sizeof(uint8_t));
    val &= 0xff;
    //printf("vm_read_8bit: %d\n", reader);
    reader->index += sizeof(uint8_t);
    return val;
}

uint16_t vm_read_16bit(struct vm_bytecode_reader *reader) {
    uint16_t val = 0;
    uint8_t high = vm_read_8bit(reader);
    uint8_t low = vm_read_8bit(reader);
    val |= low;
    val |= high << 8;
    val &= 0xffff;
    return val;
}

uint32_t vm_read_32bit(struct vm_bytecode_reader *reader) {
    uint32_t val = 0;
    uint16_t high = vm_read_16bit(reader);
    uint16_t low = vm_read_16bit(reader);
    val |= low;
    val |= high << 16;
    val &= 0xffffffff;
    return val;
}

uint8_t *vm_read_bytes(struct vm_bytecode_reader *reader, int bytes) {
    size_t len = bytes * sizeof(uint8_t);
    uint8_t *str = (uint8_t *) malloc_x (len);
    //指针指向原数据还是重新分配内存拷贝出来？
    memcpy(str, reader->buf + reader->index, len);
    reader->index += len;
    return str;
}

struct vm_bytecode_reader *new_bytecode_reader(char *bytecode, uint32_t len) {
    log_file_function_line();
    printf("bytecode len: %d\n", len);
    struct vm_bytecode_reader *reader = malloc_x (sizeof(struct vm_bytecode_reader));
    memset(reader, 0x00, sizeof(struct vm_bytecode_reader));
    reader->buf = bytecode;
    reader->size = len;
    reader->index = 0;
    return reader;
}