//
// Created by zhoubing on 2017/6/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "class.h"
#include "runtime/interpreter.h"

int main (int argc, char **argv)
{
  char *env = getenv ("JAVA_HOME");
  FILE *fp = fopen ("Pi.class", "r");
  fseek (fp, 0, SEEK_END);
  long file_len = ftell (fp);
  char *p_class_buffer = malloc (file_len + 1);
  rewind (fp);
  fread (p_class_buffer, 1, file_len, fp);
  p_class_buffer[file_len] = 0;
  fclose (fp);

  struct vm_class *p_vm_class = vm_class_new ();
  vm_class_load_bytecode (p_vm_class, p_class_buffer, file_len);
  struct vm_method *main = p_vm_class->get_main (p_vm_class);

  if (main == 0) {
    exit (1);
  } else {
    struct interpreter *interpreter = new_interpreter (p_vm_class);
    interpreter->run (interpreter, main);
  }

//    OperandStack *vmstack = new_operand_stack(10);
//    vmstack->push_long(vmstack, 9223372036854775807);
//    vmstack->push_long(vmstack, 9223372036854775801);
//    vmstack->push_long(vmstack, 9223372036854775800);
//    vmstack->push_long(vmstack, 9223372036854775711);
//    vmstack->push_long(vmstack, 9223372036854775511);
//
//    printf("%ld\n", vmstack->pop_long(vmstack));
//    printf("%ld\n", vmstack->pop_long(vmstack));
//    printf("%ld\n", vmstack->pop_long(vmstack));
//    printf("%ld\n", vmstack->pop_long(vmstack));
//    printf("%ld\n", vmstack->pop_long(vmstack));

//    LocalVars *localVars = new_local_vars(10);
//    localVars->set_long(localVars, 0, 9223372036854775807);
//    localVars->set_long(localVars, 2, 9223372036854775801);
//    localVars->set_long(localVars, 4, 9223372036854775800);
//    localVars->set_long(localVars, 6, 9223372036854775711);
//    localVars->set_long(localVars, 8, 9223372036854775511);
//
//    printf("%ld\n", localVars->get_long(localVars, 4));
//    printf("%ld\n", localVars->get_long(localVars, 2));
//    printf("%ld\n", localVars->get_long(localVars, 8));
//    printf("%ld\n", localVars->get_long(localVars, 0));
//    printf("%ld\n", localVars->get_long(localVars, 6));
  return 0;
}