//
// Created by zhoubing on 2017/6/6.
//

#include "cmd.h"

typedef struct Cmd {
    int help_flag;
    int version_flag;
    char *cp_options;
    char *class;
    char **args;
};