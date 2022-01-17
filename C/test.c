#include <stdio.h>
 
/* function declaration */
void func(void);
extern int t;
//extern int t; — t must be defined elsewhere and is referenced from this file.

static int count = 5; /* global variable */
 
int main() {
    printf ("%d\n", t);
   while(count--) {
      func();
   }
	
   return 0;
}

/* function definition */
void func( void ) {
   static int i = 5; /* local static variable */
   i++;

   printf("i is %d and count is %d\n", i, count);
}