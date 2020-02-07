#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "medicine.h"

void makeBill(struct medicine billMedicine[],int billQuantity[], int number){
    int totalMoney = 0;
    system("cls");
    printf("---------------------------------------\n");
    printf("                Bill\n");
    printf("---------------------------------------\n");
    printf("Medicine Name       Price      Quantity\n");
    for(int i = 0; i < number; ++i){
        printf(billMedicine[i].medicineName);
        printf("        ");
        printf("%d", billMedicine[i].price);
        printf("        ");
        printf("%d", billQuantity[i]);
        printf("\n");
        totalMoney += billQuantity[i] * billMedicine[i].price;
    }
    printf("Total amount : %d", totalMoney);
    printf("\n---------------------------------------\n");
    printf("Press any key to continue... ");
    getch();
}


void addMedicine(){
    char c = 'n';

    FILE *filePointer;
    filePointer = fopen("text.dat","ab");
    if(filePointer == NULL){
        printf("\nError in opening the file\n");
        getch();
        return;
    }
    
    do{
        system("cls");
        printf("---------------------------------------\n");
        printf("       Add new medicine here : \n");
        printf("---------------------------------------\n");
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

        printf("\nDo you want to add more ? (y/n)\n");
        scanf(" %c", &c);

    }while(c == 'y' || c == 'Y');
    
    fclose(filePointer); 
    printf("\nPress any button to continue..\n");
    printf("---------------------------------------\n");
    getch();
    
}

void sellMedicine(){

    system("cls");
    printf("---------------------------------------\n");
    printf("            Sale window\n");
    printf("Enter number Medicines : ");
    int numberOfItem, actualNum = 0;
    fflush(stdin);
    scanf("%d", &numberOfItem);

    FILE *filePointer;
    filePointer = fopen("text.dat","rb + wb");
    if(filePointer == NULL){
        printf("\nError in opening the file\n");
        getch();
        return;
    }
    struct medicine billMedicine[numberOfItem];
    int billQuantity[numberOfItem];

    while(numberOfItem != 0){

        if(fseek(filePointer, 0, SEEK_SET) != 0){
            printf("\nsome problem");
            return;
        }

        char medicineName[30];
        fflush(stdin);
        printf("Enter name of the medicine : ");
        gets(medicineName);
        struct medicine medicine;
        int isFound = 0;
        while(fread(&medicine, sizeof(struct medicine), 1, filePointer)){
            if(strcmp(medicine.medicineName, medicineName) == 0){
                showMedicine(medicine);
                isFound = 1;
                if(medicine.quantity > 0){
                    printf("\nCurrent stock : %d\n", medicine.quantity);
                    int quantity;
                    QUANTITY:
                    printf("How many amount ? : ");
                    scanf("%d", &quantity);
                    if(quantity > medicine.quantity){
                        printf("We don't have that much of stock !\nEnter amount again : \n");
                        goto QUANTITY;
                    }
                    medicine.quantity -= quantity;
                    // copying medicine into billMedicine to pass it to makeBill function
                    // dates are not being copyed
                    strcpy(billMedicine[actualNum].medicineName, medicineName);
                    billMedicine[actualNum].price = medicine.price;
                    billQuantity[actualNum++] = quantity;

                    fseek(filePointer, -sizeof(medicine), SEEK_CUR);
                    fwrite(&medicine, sizeof(struct medicine), 1, filePointer);
                    printf("---------------------------------------\n");
                    break;
                }
                else{
                    printf("\nWe don't have that in stock !\n");
                    printf("Current amount in stock %d\n", medicine.quantity);
                    getch();
                    break;
                }
            }
        }
        if(!isFound){
            printf("Don't have %s in stock ..\n", medicineName);
            getch();
        }
        numberOfItem--;
    }
    fclose(filePointer);
    printf("Press any key to generate the bill... ");
    getch();
    makeBill(billMedicine, billQuantity, actualNum);
}


void checkStock(){
    system("cls");
    printf("---------------------------------------\n");
    printf("               stock\n");
    printf("---------------------------------------\n");
    FILE *filePointer;
    filePointer = fopen("text.dat","rb");
    if(filePointer == NULL){
        printf("\nError in opening the file\n");
        getch();
        return;
    }

    struct medicine temp;
    while(fread(&temp, sizeof(struct medicine), 1, filePointer)){
        showMedicine(temp);
        printf("\n---------------------------------------\n");
    }
    printf("Press any key to continue... ");
    getch();
}

void restock(){
    

}

void mainMenu(){
    int choice = 0;
    while(1){
        system("cls");
        printf("---------------------------------------\n");
        printf("               Main menu\n");
        printf("---------------------------------------\n");
        printf("Enter your choice : \n");
        printf("1 To enter new medicine\n");
        printf("2 To opening sales window\n");
        printf("3 To check stock\n");
        printf("4 To restock\n");
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
                restock();
                break;
            }
            case 5:{
                printf("Thank you for using this software.");
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