#ifndef CANTEEN_H
#define CANTEEN_H

struct Canteen
{
    long ID;           //* Canteen ID Number
    char name[50];     //* Canteen Name
    char password[15]; //* Canteen Login Password

    long total_orders;
    long total_income;
    // struct Menu_item Menu[50] //* Canteen Menu
};

// Global Definition
// canteen[i] -> ith canteen
struct Canteen *canteens[5];

#endif // CANTEEN_H