//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_UTILITY_H
#define UNTITLED2_UTILITY_H
#include <memory.h>
#include "stdio.h"

//const int a = 1;
#define big_edian() (*((char *) &a) == 0)
//#define little_edian() (*((char *) &a) == 1)

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define IS_ATTRIBUTE_CODE(attr, klass) strncmp(((ConstantUtf8 *) klass->constant_pool->constant_info_arr[attr->attribute_name_index])->str, "Code", 4) == 0

#define log_file_function_line() /*printf("File: %s, Function Name: %s Line: %d\n", __FILE__, __FUNCTION__, __LINE__)*/

#define log_utf8(param, len) \
    char *log = malloc(len + 1); \
    memset(log, 0x00, len + 1); \
    memcpy(log, param, len); \
    printf("utf8 is %s\n", log)

#define log(param) printf("%s\n", param)

#define malloc_x(size) \
    malloc(size); \
//    printf("allocate memory: %d\n", size);\
   // log_file_function_line()

#endif //UNTITLED2_UTILITY_H
