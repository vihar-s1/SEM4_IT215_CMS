#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Menu.h"
#include "Canteen.h"

void display_menu(int canteen_no)
{
    if (canteen_no > 0 && canteen_no <= 5)
    {
        for (int i = 0; i < 50; i++)
        {
            printf("%d. %40s \t %3.2d\n", i + 1, canteens[canteen_no - 1].Menu[i].name, canteens[canteen_no - 1].Menu[i].price);
        }
    }
}

void order()
{
    int n;
    printf("There are 5 canteens numbered from 1 to 5.\nEnter the canteen number you want to order from: ");
    scanf("%d", &n);
    if (n >= 1 && n <= 5)
    {
        int it_no;
        printf("Enter the number of the item you wish to order: ");
        scanf("%d", &it_no);
        if (it_no >= 1 && it_no <= 100)
        {
            int qty;
            printf("Enter the quantity of item %d: ", it_no);
            scanf("%d", &qty);
            if (qty > 0 && qty < 51)
            {
                add_to_bill(n, it_no - 1, qty);
            }
            else
            {
                printf("Enter a valid quantity\n");
            }
        }
        else
        {
            printf("Enter a valid item number\n");
            return;
        }
    }
    else
    {
        printf("Enter a valid canteen number\n");
        return;
    }
}

void add_to_bill(int can_no, int it_no, int qty)
{
    printf("Complete Function add_to_bill(int, int, int);");
}