/*
* Practicing with constants' behavior. 
*
* Inspired by comments from siebenschlaefer and ryanplusplus 
* on Issue #56: https://github.com/exercism/c-test-runner/issues/56
*
* Try to reassign const char using casting
* 
* Try to cast a const char to a function
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
    /* Tried to reassign using casting
    * Does not compile:
    * error: assignment to cast is illegal, lvalue casts are not supported
    * 
    * (char) c = 'm';
    * 
    */
    
    // Casting to a char - works
    char upper = toupper((char) c);

    printf("upper: %c\n", upper);

    // Casting to an int - works
    int num = (int) c;

    printf("num: %i\n", num);

    /* Tried to reassign using pointer to constant
    * Does not compile: 
    * error: read-only variable is not assignable
    *
    * const char *p = &c; 
    * *p = upper;
    * 
    */

}
