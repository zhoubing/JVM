//
// Created by zhoubing on 2017/6/12.
//

#include <printf.h>
#include "utility.h"

void log(const char *param, ...) {
    printf("%s\n", param);
}

void log_file_function_line() {
    printf("File: %s, Function Name: %s Line: %d\n", __FILE__, __FUNCTION__, __LINE__);
}