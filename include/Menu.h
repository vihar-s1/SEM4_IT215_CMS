#ifndef MENU_H
#define MENU_H

struct Menu_item
{
    char name[40];
    int price;
    int current_order; // number of times the item is ordered by a particular customer
    int total_order;   // total number of times the item is ordered by all customers
};

void add_to_bill(int, int, int);
#endif // MENU_H