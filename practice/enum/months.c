#include "months.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
* Declare enumeration type called month. 
* Values here start at 1 and are assigned up to 12.  
* Feb is 2, Mar is 3, etc.
* 0 has not been assigned.
*/

enum months {Jan = 1, Feb, Mar, Apr, May, Jun, 
                      Jul, Aug, Sep, Oct, Nov, Dec};

char * get_month(void);
int calc_month(char *input);

int main(void)
{
    char *input = get_month();

    printf("Month entered: %u\n", calc_month(input));
}

char * get_month(void)
{
    char *input = malloc(sizeof(char) * 3);

    while (strlen(input) != 3)
    {
        printf("Enter a month: ");
        scanf("%s", input);
    }

    return input;
}

int calc_month(char *input)
{
    enum months month = Jan;
    
    char *month_str[12] = {"Jan", "Feb", "Mar", "Apr", 
                       "May", "Jun", "Jul", "Aug", 
                       "Sep", "Oct", "Nov", "Dec"};

    while(month <= Dec)
    {
        if(strcmp(input, month_str[month - 1]) == 0)
        {
            return month;
        }
        month++;
    }

    return 0;
}

