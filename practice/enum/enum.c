#include <stdio.h>

// Declare enumeration type called week with enumerators for each weekday
enum week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main(void)
{

// Create variable of type 'week' (aka 'int') called "enum_var" 
enum week enum_var;
int int_var;

// Set enum variable and int variable equal to Monday
enum_var = Monday;
int_var = Monday;

// Print constant values, names of enumerated constants cannot be printed
printf("enum variable: %i\n", enum_var);
printf("int variable: %i\n", int_var);

// Enum variables are just signed integer types
enum_var = -3;
int_var = enum_var;
printf("enum: %i int: %i size: %lu\n", enum_var, int_var, sizeof(enum_var));

// Enum constants can be used arithimatically
for (int day = Monday; day <= Sunday; day++)
{

    (day % 2 == 0) ? printf("Even: %i\n", day) : printf("Odd: %i\n", day);

    (day == Sunday) ? printf("Tuesday + Wednesday = %i\n", Tuesday + Wednesday) : 0;
}

}