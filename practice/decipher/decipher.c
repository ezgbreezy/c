#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void validate_input(int argc, char* argv[]);
char* encipher(char* plaintext, int key);
char* decipher(char* ciphertext, int key);

bool is_decipher = false; // False sets program to encipher (default)

int main(int argc, char* argv[])
{
   validate_input(argc, argv);

   int key = atoi(argv[2]);

    if (is_decipher == true)
    {
        char* input_text;
        printf("Enter text to decipher: ");
        scanf("%s", input_text);
        printf("\nDeciphered text: %s\n\n", decipher(input_text, key));
    }
    else
    {
        char* input_text;
        printf("Enter text to encipher: ");
        scanf("%s", input_text);
        printf("\nEnciphered text: %s\n\n", encipher(input_text, key));
    }
    return 0;
}

void validate_input(int argc, char* argv[])
{
    if (argc < 3) // Check for argument count, exit with error if not 2
    {
        printf("\nUsage: ./decipher [-encipher/-e or -decipher/-d] [numeric key] [text]\n\n");
        printf("1. Set program to [-encipher] or [-decipher] ([-e] or [-d] also work)\n");
        printf("2. Enter non-negative numeric cipher key (eg. 42)\n");
        exit(1);
    }

    if (strcmp(argv[1], "-decipher") == 0 || strcmp(argv[1],"-d") == 0)
    {
        is_decipher = true;
    }
    else if (strcmp(argv[1], "-encipher") == 0 || strcmp(argv[1],"-e") == 0)
    {
        is_decipher = false;
    }
    else
    {
        printf("\nError: Cipher type not set\n\n");
        printf("Usage: ./decipher [-encipher or -decipher] [numeric key] [text]\n\n");
        exit(2);
    }

    if (argv[2] <= 0)
    {
        printf("\nError: Numeric key must be non-negative, non-zero integer\n\n");
        printf("Usage: ./decipher [-encipher or -decipher] [numeric key] [text]\n\n");
        exit(3);
    }
    // Iterate through numeric key, check if on-negative integer
    for (int i = 0; argv[2][i] != '\0'; i++)
    {
        if (isdigit(argv[2][i]) == 0)
        {
            printf("\nError: Numeric key must be non-negative, non-zero integer\n\n");
            printf("Usage: ./decipher [-encipher or -decipher] [numeric key] [text]\n\n");
            exit(3);
        }
    }
}

char* encipher(char* plaintext, int key)
{
    char* ciphertext = malloc(strlen(plaintext));

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90) // If uppercase rotate
        {
            ciphertext[i] = 65 + (((plaintext[i] - 65) + key) % 26);
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122) // If lowercase rotate
        {
            ciphertext[i] = 97 + (((plaintext[i] - 97) + key) % 26);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}

char* decipher(char* ciphertext, int key)
{
    char* plaintext;

    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        if (ciphertext[i] >= 65 && ciphertext[i] <= 90) // If uppercase rotate
        {
            plaintext[i] = 65 + (((ciphertext[i] - 65) + (26 - (key % 26))) % 26);
        }
        else if (ciphertext[i] >= 97 && ciphertext[i] <= 122) // If lowercase rotate
        {
            plaintext[i] = 97 + (((ciphertext[i] - 97) + (26 - (key % 26))) % 26);
        }
        else
        {
            plaintext[i] = ciphertext[i];
        }
    }
    return plaintext;
}