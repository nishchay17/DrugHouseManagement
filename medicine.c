#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "medicine.h"

struct medicine getMedicine(struct medicine parameter){
    printf("Enter medicine's name : ");
    fflush(stdin);
    gets(parameter.medicineName);
    printf("Enter expiration date\n");
    parameter.expirationDate = getDate(parameter.expirationDate);
    printf("Enter purchase date\n");
    parameter.purchaseDate = getDate(parameter.purchaseDate);
    printf("Enter Quantity : ");
    scanf("%d", &parameter.quantity);
    printf("Enter price : ");
    scanf("%d", &parameter.price);
    return parameter;
}

void showMedicine(struct medicine parameter){
    printf("Medicine name : ");
    printf("%s",parameter.medicineName);
    printf("\nExpiration date : ");
    showDate(parameter.expirationDate);
    printf("\nPurchase date : ");
    showDate(parameter.purchaseDate);
    printf("\nQuantity : ");
    printf("%d", parameter.quantity);
    printf("\nPrice : ");
    printf("%d", parameter.price);
}