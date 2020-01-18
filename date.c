#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "date.h"
const char month[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December"};

struct date getDate(struct date parameter){
    DAY:
    printf("Enter day : ");
    scanf("%d", &parameter.day);
    if(parameter.day > 31){
        printf("Day should be between 1 and 31, please enter again..\n");
        goto DAY;
    }
    MONTH:
    printf("Enter month : ");
    scanf("%d", &parameter.month);
    if(parameter.month > 12){
        printf("Month should be between 1 and 12, please enter again..\n");
        goto MONTH;
    }
    printf("Enter year : ");
    scanf("%d", &parameter.year);
    return parameter;
}

void showDate(struct date parameter){
    printf("%d", parameter.day);
    printf(" ");
    printf("%s", month[parameter.month - 1]);
    printf(" ");
    printf("%d", parameter.year);
}