#ifndef DATE_H
#define DATE_H

struct date{
    int day;
    int month;
    int year;
};

struct date getDate(struct date parameter);
void showDate(struct date parameter);

#endif