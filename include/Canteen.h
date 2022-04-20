#ifndef CANTEEN_H
#define CANTEEN_H

struct Canteen
{
    long ID;           //* Canteen ID Number
    char name[50];     //* Canteen Name
    char password[15]; //* Canteen Login Password

    long total_orders;
    long total_income;
    struct Menu_item Menu[100] //* Canteen Menu
    int items;
};

// Global Definition
// canteen[i] -> ith canteen
struct Canteen *canteens[5];

canteens[0]->Menu[0]->name="Full Thaali";
canteens[0]->Menu[0]->price=53;
canteens[0]->Menu[0]->current_order=0;
canteens[0]->Menu[0]->total_order=0;
canteens[0]->Menu[1]->name="Half Thaali";
canteens[0]->Menu[1]->price=37;
canteens[0]->Menu[1]->current_order=0;
canteens[0]->Menu[1]->total_order=0;

#endif // CANTEEN_H