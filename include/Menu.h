#ifndef MENU_H
#define MENU_H

struct Menu_item
{
    char name[40];
    int price;
    int current_order; // number of times the item is ordered by a particular customer
    int total_order;   // total number of times the item is ordered by all customers
};

void display_menu(int);

void create_bill(int);
void add_to_bill(int, int, int);
void print_bill();

#endif // MENU_H