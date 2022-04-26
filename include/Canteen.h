#ifndef CANTEEN_H
#define CANTEEN_H

#include "Menu.h"

struct Canteen
{
    long ID;           //* Canteen ID Number
    char name[50];     //* Canteen Name
    char password[15]; //* Canteen Login Password

    long total_orders;
    long total_income;
    int items_avail;
    struct Menu_item Menu[100]; //* Canteen Menu
};

// Global Definition
// canteen[i] -> ith canteen
struct Canteen canteens[5];

void edit_menu(int); // edits menu 
int canteen_login(long, char *);  // login to canteeen 
void order(int); // order 

void run_canteen_ui(int); //runs canteen user interface

#endif // CANTEEN_H