//
// Created by zhoubing on 2017/6/6.
//

#ifndef UNTITLED2_CMD_H
#define UNTITLED2_CMD_H
typedef struct _cmd {
    int help_flag;
    int version_flag;
    char *cp_options;
    char *class;
    char **args;
} cmd;
#endif //UNTITLED2_CMD_H
