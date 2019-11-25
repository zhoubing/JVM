//
// Created by zhoubing on 2017/6/12.
//

#ifndef UNTITLED2_UTILITY_H
#define UNTITLED2_UTILITY_H
//const int a = 1;
#define big_edian() (*((char *) &a) == 0)
//#define little_edian() (*((char *) &a) == 1)

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define IS_ATTRIBUTE_CODE(attr, klass) strcmp(((ConstantUtf8 *) klass->constant_pool->constant_info_arr[attr->attribute_name_index])->str, "Code") == 0


void log(const char *param,...);

void log_file_function_line();

#endif //UNTITLED2_UTILITY_H
