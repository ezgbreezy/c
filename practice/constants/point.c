/*
* Practicing with constants' behavior. 
*
* Try to reassign by pointing to the constant and assigning to dereferenced pointer
*/

#include <stdio.h>
#include <ctype.h>

void constant(const char c);

int main(void)
{
    const char c = 'c';

    constant(c);

    printf("main: %c\n", c);

    return 0;
}

void constant(const char c)
{

    /* Tried to reassign using pointer to constant
    * Does not compile: 
    * error: read-only variable is not assignable
    *
    *   const char *p = &c; 
    *   *p = upper;
    * 
    */

}
