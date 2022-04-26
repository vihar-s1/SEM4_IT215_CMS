#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "Canteen.h"
#include "Menu.h"
#define YES 1
#define NO 0

/*
. returns -1 if invalid password
. returns -2 if invalid ID
. returns  index for valid ID and Password
*/
int canteen_login(long ID, char *password)
{
    struct Canteen *canteen = NULL;

    for (int i = 0; i < 5; i++)
    {
        if (canteens[i]->ID == ID)
        {
            if (strcmp(canteens[i]->password, password) == 0)
                return i;
            else
                return -1;
        }
    }
    return -2;
}

void edit_menu_items(int can_no)
{
    int n;
    do
    {
        printf("Enter 1 to edit an item's name\nEnter 2 to edit an item's price\nEnter 3 to remove an item\n");
        printf("Enter 4 to replace an item\nEnter 5 to add a new item\nEnter 6 to exit\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the item number whose name you want to edit: ");
            int no;
            scanf("%d", &no);
            if (no > 0 && no <= canteens[can_no]->items_avail)
            {
                char new_name[40];
                scanf("%s", new_name);
                strcpy(canteens[can_no]->Menu[no - 1]->name, new_name);
            }
            else
                printf("Enter a valid item number\n");
            break;
        }
    } while (n != 6);
}

void order(int can_no)
{
    create_bill(can_no);
    display_menu(can_no);
    int order_more = YES;
    int item_avail = canteens[can_no - 1]->items_avail;
    do
    {
        int item_no;

        do
        {
            printf("\nEnter Item Number to Order: ");
            scanf("%d", &item_no);
            if (0 < item_no && item_no <= item_avail)
                break;
            printf("Invalid item number. Enter between 1 to %d inclusive!!\n", item_avail);
        } while (1);

        int qty;
        do
        {
            printf("\nEnter Quantity: ");
            scanf("%d", &qty);
            if (0 < qty && qty < 51)
                break;
            printf("Ivalid quantity. Enter between 1 and 50 inclusive!!\n");
        } while (1);

        add_to_bill(can_no, item_no, qty);

        printf("Do you want to order more? Y/N: ");
        char ch;
        scanf("%c", &ch);

        if (ch == 'N' || ch == 'n')
            order_more = NO;

    } while (order_more);

    FILE *bill = fopen("../Database/bill", "a");
    int total = 0;
    for (int i = 0; i < canteens[can_no - 1]->items_avail; i++)
    {
        total += canteens[can_no - 1]->Menu[i]->current_order * canteens[can_no - 1]->Menu[i]->price;
        canteens[can_no - 1]->Menu[i]->current_order = 0;
    }

    fprintf(bill, "----------------------------------------------------------\n%-49s    %5d\n\nEOF", "NET AMOUNT", total);
    fclose(bill);

    getc(stdin);
}

void run_canteen_ui(int can_no)
{
    while (1)
    {
        getc(stdin);
        printf("\nPress Enter To Continue...");
        getc(stdin);

        system("clear");
        printf("__________________________________________\n\n");
        printf("         WELCOME TO DNS CANTEEN UI        \n");
        printf("__________________________________________\n\n");
        printf("            Enter 0 to logout             \n");
        printf(" Enter 1 to view total orders and income  \n");
        printf("          Enter 2 to Edit Menu            \n");
        printf("__________________________________________\n");

        printf("\nYour Choice: ");
        int choice;
        scanf("%d", &choice);
        printf("\n");

        if (choice == 0)
            return;

        switch (choice)
        {
        case 1:
            printf("Total Orders: %ld\nTotal Income: %ld\n", canteens[can_no - 1]->total_orders, canteens[can_no - 1]->total_income);
            break;
        case 2:
            edit_menu_items(can_no);
            break;
        default:
            printf("Incorrect Choice!! Try Again!\n");
            break;
        }
    }
}