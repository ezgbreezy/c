#include <stdio.h>

int main(void)
{
    char *string = "Hello"; // A string variable (char *)
    char *p = &string[0]; // Pointer to the first character of a string (char **)
    char *p2 = string; // Pointer to string (char **)
    char *p3 = &string[1]; // Pointer to second character in string (char **)

    printf("1: %p\n", p); // Prints pointer address
    printf("2: %p\n", string); // Prints address of first character of string
    printf("3: %s\n", string); // Prints entire string
    printf("4: %c\n", string[0]); // Prints first character of string (string[0])
    printf("4.1: %c\n", *(string + 1)); // Prints dereferenced value of string[1] or (string + 1) second character
    printf("4.2: %p\n", (string + 1)); // Prints address of first address after address being pointed too
    printf("5: %c\n", *p); // Prints dereferenced value pointer is pointing too (first character of string)
    printf("6: %s\n", p); // Prints entire string via pointer to string (pointer to pointer)
    printf("7: %s\n", p2); // Prints dereferenced value pointer is pointing too (entire string)
    printf("8: %s\n", p3); // Prints entire string starting at second character (string[1])
}