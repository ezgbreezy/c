#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct {
        double day;
        int hours;
        int dtime;
        float tax;
    } rate;

typedef struct {
    rate comp;
    char name[50];
    char position[50];
} person;

// Define macros
#define RATE_CALC (user.comp.day/(((user.comp.hours-8)*.5)+user.comp.hours)) // Hourly rate calculation
#define TAX_CALC user.comp.day*days*(1-user.comp.tax) // After tax wage calculation

int main(void)
{
    person user;
    int days = 0;
    
    printf("\nEnter name: ");
    scanf("%s", user.name);

    printf("\nEnter position: ");
    scanf("%s", user.position);

    printf("\nEnter day rate: ");
    scanf("%lf", &user.comp.day); 

    printf("Enter guaranteed hours: ");
    scanf("%i", &user.comp.hours);

    printf("Enter number of hours till 2x overtime: ");
    scanf("%i", &user.comp.dtime);

    printf("Enter number of days: ");
    scanf("%i", &days);

    printf("Enter tax rate percentage in decimal format: ");
    scanf("%f", &user.comp.tax);

    printf("\n");

    if (user.comp.hours > 8 && user.comp.hours <= user.comp.dtime) {
        printf("Rate info for: %s, %s\n", user.name, user.position);
        printf("\nHourly rate: $%.2lf\n", RATE_CALC);
        printf("1.5x overtime rate: $%.2lf\n", RATE_CALC * 1.5);
        printf("2x overtime rate: $%.2lf\n\n", RATE_CALC * 2);
        printf("Total pre-tax wages: $%.2lf\n\n", user.comp.day*days);
        printf("Estimated post-tax wages: $%.2f\n\n", TAX_CALC);}
    else if (user.comp.hours <= 8) {
        printf("\nHourly rate: $%.2f\n", user.comp.day
        /user.comp.hours);
        printf("1.5x overtime rate: $%.2f\n", (user.comp.day/user.comp.hours) * 1.5);
        printf("2x overtime rate: $%.2f\n\n", (user.comp.day/user.comp.hours) * 2); 
        printf("Total pre-tax wages: $%.2lf\n\n", user.comp.day*days); 
        printf("Estimated post-tax wages: $%.2f\n\n", TAX_CALC);
        }
    else {        
        printf("\nUnable to process entry.\n\n");
        return 1; }
    
    return 0;
}