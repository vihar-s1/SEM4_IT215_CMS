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

void create_bill(int); // creates bill 
void add_to_bill(int, int, int); // add items to bill 
void get_bill(int);   // provide  bill to customer 
void print_bill(); // prints bill for customer

#endif // MENU_H