#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "medicine.h"


void addMedicine(){
    system("cls");
    printf("---------------------------------------\n");
    printf("       Add new medicine here : \n");
    printf("---------------------------------------\n");
    FILE *filePointer;
    filePointer = fopen("text.txt","a");
    if(filePointer == NULL){
        printf("\nError in opening the file\n");
        getch();
        return;
    }
    
    struct medicine temp;
    temp = getMedicine(temp);
    system("cls");
    fwrite(&temp, sizeof(struct medicine), 1, filePointer);
    printf("---------------------------------------\n");
    if(fwrite != 0){
        printf("File written successfully !\n\nNew medicine which is added : \n");
        showMedicine(temp);
    }
    else
        printf("Error writing file !\n");
    fclose(filePointer); 
    printf("\nPress any button to continue..\n");
    printf("---------------------------------------\n");
    getch();
}

void sellMedicine(){
    system("cls");
    printf("---------------------------------------\n");
    printf("            Sale window\n");
    printf("Enter number items to be sell\n");
    int numberOfItem;
    fflush(stdin);
    scanf("%d", &numberOfItem);

    FILE *filePointer;
    filePointer = fopen("text.txt","a");
    if(filePointer == NULL){
        printf("\nError in opening the file\n");
        getch();
        return;
    }

    while(numberOfItem != 0){
        // fseek(filePointer, 0, SEEK_SET);
        char medicineName[30];
        fflush(stdin);
        printf("Enter name of the medicine : ");
        gets(medicineName);
        struct medicine medicine;
        int isFound = 0;
        while(fread(&medicine, sizeof(struct medicine), 1, filePointer)){
            showMedicine(medicine);
            if(strcmp(medicine.medicineName, medicineName) == 0){
                isFound = 1;
                if(medicine.quantity > 0){
                    printf("Current stock : %d\n", medicine.quantity);
                    int quantity;
                    QUANTITY:
                    printf("How many amount ? : ");
                    scanf("%d", &quantity);
                    if(quantity > medicine.quantity){
                        printf("We don't have that much of stock !\nEnter amount again : ");
                        goto QUANTITY;
                    }
                    medicine.quantity -= quantity;
                    break;
                }
                else{
                    printf("We don't have that much of stock !\n");
                    printf("Current amount in stock %d\n", medicine.quantity);
                    break;
                }
            }
        }
        if(!isFound){
            printf("Don't have %s in stock ..", medicineName);
            getch();
        }
        numberOfItem--;
    }
}

void checkStock(){

}

void report(){

}

void mainMenu(){
    int choice = 0;
    while(1){
        system("cls");
        printf("---------------------------------------\n");
        printf("Enter your choice : \n");
        printf("1 To enter new medicine\n");
        printf("2 To opening sell window\n");
        printf("3 To check stock\n");
        printf("4 To check sales/report\n");
        printf("5 TO EXIT \n");
        printf("---------------------------------------\nYour choice is : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                addMedicine();
                break;
            }
            case 2:{
                sellMedicine();
                break;
            }
            case 3:{
                checkStock();
                break;
            }
            case 4:{
                report();
                break;
            }
            case 5:{
                printf("Thank you...");
                exit(0);
                break;
            }
            default:{
                printf("Wrong choice, please enter one more time");
                getch();
                break;
            }
        }
    }
}

int main(){
    mainMenu();
    return 0;
}