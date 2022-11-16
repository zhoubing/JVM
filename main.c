//
// Created by zhoubing on 2017/6/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "class.h"
#include "runtime/interpreter.h"
#include "runtime/localvars.h"

struct A {
    char *a;
    char *b;
};

int main(int argc, char **argv) {
//    struct A *a = malloc(sizeof(struct A));
//    a->a = "1a";
//    a->b = "1b";
//
//    struct A *b = malloc(sizeof(struct A));
//    b->a = "2a";
//    b->b = "2b";
//
//    struct A *c = malloc(sizeof(struct A));
//    c->a = "3a";
//    c->b = "3b";
//
//    struct A **aar = malloc(sizeof (struct A *));
//    aar[0] = a;
//    aar[1] = b;
//    aar[3] = c;
//
//    printf("%s\n", aar[0]->a);
//    printf("%s\n", aar[3]->a);
//
//    return 0;

    char *env = getenv("JAVA_HOME");
    FILE *fp = fopen("Main2.class", "rb");
    fseek(fp, 0, SEEK_END);
    long file_len = ftell(fp);
    char *p_class_buffer = malloc_x (file_len + 1);
    rewind(fp);
    fread(p_class_buffer, sizeof(char), file_len, fp);
    p_class_buffer[file_len] = 0;
    fclose(fp);

    struct vm_class *p_vm_class = vm_class_new();
    gClass = p_vm_class; //debug用

    vm_class_load_bytecode(p_vm_class, p_class_buffer, file_len);
    struct vm_method *main = p_vm_class->get_main(p_vm_class);
    if (main == 0) {
        exit(-200);
    } else {
        Interpreter_Run(Interpreter_New(p_vm_class), main);
    }

//    LocalVars  * lv = LocalVars_New(32);
//    LocalVars_SetInt(lv, 0, 100);
//    LocalVars_SetInt(lv, 1, -100);
//    LocalVars_SetLong(lv, 2, 2997924580);
//    LocalVars_SetLong(lv, 3, -2997924580);
//
//    printf("%d\n", LocalVars_GetInt(lv, 0));
//    printf("%d\n", LocalVars_GetInt(lv, 1));
//    printf("%d\n", LocalVars_GetLong(lv, 2));
//    printf("%d\n", LocalVars_GetLong(lv, 3));
    return 0;
}