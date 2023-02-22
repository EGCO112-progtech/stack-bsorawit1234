#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "node.h"
#include "stack.h"

int main(int argc, char **argv){
   Stack s;
   s.top = NULL;

   printf("Checking the parentheses in argv arguments\n");
   for(int i = 1; i < argc; i++) {
      pop_all(&s);
      printf("argv %d %s\n", i, isBalance(&s, argv[i]));
   }

   return 0;
}
