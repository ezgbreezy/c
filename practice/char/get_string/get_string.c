#include <stdio.h>
#include <stdlib.h>

int i;

typedef char *string; // Define type 'string' of type char*
string get_string(string s); // Function prototype for get_string()

  
int main()
{
    string s = get_string("Enter a string: "); // Get string from user
    
    printf("%s\n", s); // Print string

    return 0;
}

string get_string(string text) // Function for getting a string from user
{
    string s;
    s = malloc(sizeof(string)); // Allocate 30 bytes of memory for string
    printf("%s", text); // Print text to display to user
    gets(s); // Scan and store user response
    free(s); 
    return s; // Return response
}
