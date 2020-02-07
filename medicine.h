#include "date.h"
#ifndef MEDICINE_H
#define MEDICINE_H

struct medicine{
    char medicineName[30];
    struct date expirationDate;
    struct date purchaseDate;
    unsigned quantity;
    unsigned price;
};
struct medicine getMedicine(struct medicine parameter);
void const showMedicine(struct medicine parameter);

#endif