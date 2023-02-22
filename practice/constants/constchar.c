/*
* Practicing with constants' behavior. 
*
* Inspired by comments from siebenschlaefer and ryanplusplus 
* on Issue #56: https://github.com/exercism/c-test-runner/issues/56
*
* 1. Try to manipulate const chars using casting
* 
*
*/

#include <stdio.h>

void constant(const char c);

int main(void)
{
    const char c = 'c';

    constant(c);

    printf("%c\n", c);

    return 0;
}

void constant(const char c)
{
    // Try to manipulate by casting
    (char) c = 'm';
    
    printf("%c\n", c);
}
