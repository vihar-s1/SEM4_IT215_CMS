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
    int items;
    struct Menu_item Menu[100]; //* Canteen Menu
};

// Global Definition
// canteen[i] -> ith canteen
struct Canteen canteens[5];

/*
canteens[0]->Menu[0]->name = "Full Thaali";
canteens[0]->Menu[0]->price = 53;
canteens[0]->Menu[0]->current_order = 0;
canteens[0]->Menu[0]->total_order = 0;
canteens[0]->Menu[1]->name = "Half Thaali";
canteens[0]->Menu[1]->price = 37;
canteens[0]->Menu[1]->current_order = 0;
canteens[0]->Menu[1]->total_order = 0;
canteens[0]->Menu[2]->name = "Mini Thaali";
canteens[0]->Menu[2]->price = 39;
canteens[0]->Menu[2]->current_order = 0;
canteens[0]->Menu[2]->total_order = 0;
canteens[0]->Menu[3]->name = "Chhole Bhature";
canteens[0]->Menu[3]->price = 40;
canteens[0]->Menu[3]->current_order = 0;
canteens[0]->Menu[3]->total_order = 0;
canteens[0]->Menu[4]->name = "Samosa";
canteens[0]->Menu[4]->price = 15;
canteens[0]->Menu[4]->current_order = 0;
canteens[0]->Menu[4]->total_order = 0;
canteens[0]->Menu[5]->name = "Pav Bhaji";
canteens[0]->Menu[5]->price = 40;
canteens[0]->Menu[5]->current_order = 0;
canteens[0]->Menu[5]->total_order = 0;
canteens[0]->Menu[6]->name = "Veg Sandwich";
canteens[0]->Menu[6]->price = 25;
canteens[0]->Menu[6]->current_order = 0;
canteens[0]->Menu[6]->total_order = 0;
canteens[0]->Menu[7]->name = "Grilled Sandwich";
canteens[0]->Menu[7]->price = 50;
canteens[0]->Menu[7]->current_order = 0;
canteens[0]->Menu[7]->total_order = 0;
canteens[0]->Menu[8]->name = "Cheese Grilled Sandwich";
canteens[0]->Menu[8]->price = 70;
canteens[0]->Menu[8]->current_order = 0;
canteens[0]->Menu[8]->total_order = 0;
canteens[0]->Menu[9]->name = "Bread Butter";
canteens[0]->Menu[9]->price = 15;
canteens[0]->Menu[9]->current_order = 0;
canteens[0]->Menu[9]->total_order = 0;
canteens[0]->Menu[10]->name = "Noodles";
canteens[0]->Menu[10]->price = 40;
canteens[0]->Menu[10]->current_order = 0;
canteens[0]->Menu[10]->total_order = 0;
canteens[0]->Menu[11]->name = "Manchuriyan";
canteens[0]->Menu[11]->price = 40;
canteens[0]->Menu[11]->current_order = 0;
canteens[0]->Menu[11]->total_order = 0;
canteens[0]->Menu[12]->name = "Paneer Chilly";
canteens[0]->Menu[12]->price = 55;
canteens[0]->Menu[12]->current_order = 0;
canteens[0]->Menu[12]->total_order = 0;
canteens[0]->Menu[13]->name = "Paneer Tikka";
canteens[0]->Menu[13]->price = 55;
canteens[0]->Menu[13]->current_order = 0;
canteens[0]->Menu[13]->total_order = 0;
canteens[0]->Menu[14]->name = "Fried Rice";
canteens[0]->Menu[14]->price = 35;
canteens[0]->Menu[14]->current_order = 0;
canteens[0]->Menu[14]->total_order = 0;
*/

#endif // CANTEEN_H