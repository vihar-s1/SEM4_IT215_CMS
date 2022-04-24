#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>

struct Menu_item
{
    char name[40];
    int price;
    int current_order; // number of times the item is ordered by a particular customer
    int total_order;   // total number of times the item is ordered by all customers
};
Menu_item arr[100];

// void initialise_one_item(Menu_item *ptr, int cost, int cur_order = 0, int tot_order = 0,char )
// {

//     char *temp = (*ptr).name;
//     strcpy(temp, "Spicy Ranch Pizza");
//     (*ptr).price = cost;
//     (*ptr).current_order = cur_order;
//     (*ptr).total_order = tot_order;
// }
void initialise_menu_items()
{
    char *ptr = arr[1].name;
    strcpy(ptr, "Spicy Ranch Pizza");
    arr[1].price = 350;
    ptr = arr[2].name;
    strcpy(ptr, "Margherita pizza");
    arr[2].price = 380;
    ptr = arr[3].name;
    strcpy(ptr, "Hawaiian pizza");
    arr[3].price = 420;
    ptr = arr[4].name;
    strcpy(ptr, "Veg Supreme Pizza");
    arr[4].price = 370;
    ptr = arr[5].name;
    strcpy(ptr, "Gobi Paratha");
    arr[5].price = 150;
    ptr = arr[6].name;
    strcpy(ptr, "Aloo paratha");
    arr[6].price = 120;
    ptr = arr[6].name;
    strcpy(ptr, "Aloo paratha");
    arr[6].price = 120;
    ptr = arr[7].name;
    strcpy(ptr, "Paneer Paratha");
    arr[7].price = 170;
    ptr = arr[8].name;
    strcpy(ptr, "Paneer Burger");
    arr[8].price = 50;
    ptr = arr[9].name;
    strcpy(ptr, "Momo Burger");
    arr[9].price = 50;
    ptr = arr[10].name;
    strcpy(ptr, "Club sandwich");
    arr[10].price = 50;
    ptr = arr[11].name;
    strcpy(ptr, "Paneer sandwich");
    arr[11].price = 60;
    ptr = arr[12].name;
    strcpy(ptr, "Falafel sandwich");
    arr[12].price = 70;
    ptr = arr[13].name;
    strcpy(ptr, "Chicken Biryani");
    arr[13].price = 250;
    ptr = arr[14].name;
    strcpy(ptr, "Schezwan Biryani");
    arr[14].price = 200;
    ptr = arr[15].name;
    strcpy(ptr, "Veg Pulao");
    arr[15].price = 180;
    ptr = arr[16].name;
    strcpy(ptr, "Rajma Chawal");
    arr[16].price = 100;
}
int main()
{

    initialise_menu_items();
    bool entry = true;
    int counter = 0;
    printf("\n\n");
    printf("WELCOME TO DNS CAFETARIA MANAGEMENT SYSTEM \n");
    printf("WHAT WOULD YOU LIKE TO ORDER TODAY?\n");

    while (entry)
    {
        printf("\n\n");
        printf("Choose one of the following\n");
        printf("\n\nCanteen No. 1\n\n1) Spicy Ranch Pizza ------ 350 Rs.\n2) Margherita pizza ------ 380 Rs.\n3) Hawaiian pizza ------ 420 Rs.\n \n\nCanteen No. 2\n\n4) Veg Supreme Pizza ------ 370 Rs.\n5) Gobi Paratha ------ 150 Rs.\n6) Aloo paratha ------ 120 Rs.\n \n\nCanteen No. 3\n\n7) Paneer Paratha ------ 170 Rs.\n8) Paneer Burger ------ 50 Rs.\n9) Momo Burger ------ 50 Rs.\n \n\nCanteen No. 4\n\n10) Club Sandwich ------ 50 Rs.\n11) Paneer Sandwich ------ 60 Rs.\n12) Falafel Sandwich ------ 70 Rs.\n \n\nCanteen No. 5\n\n13) Chicken Biryani ------ 250 Rs.\n14) Schezwan Biryani ------ 200 Rs.\n15) Veg Pulao ------ 180 Rs.\n16) Rajma Chawal ------ 100 Rs.\n17) Exit \n");
        int n;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            int canteen = 1;
            int item_id = 1;
            printf("Case executed");
            int quantity;
            printf("How much quantity do you want?\n");
            scanf("%d", &quantity);
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 2:
        {
            int item_id = n;

            int canteen = 1;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 3:
        {
            int item_id = n;
            int canteen = 1;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 4:
        {
            int item_id = n;
            int canteen = 2;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 5:
        {
            int item_id = n;
            int canteen = 2;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 6:
        {
            int item_id = n;
            int canteen = 2;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 7:
        {
            int item_id = n;
            int canteen = 3;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 8:
        {
            int item_id = n;
            int canteen = 3;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 9:
        {
            int item_id = n;
            int canteen = 3;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 10:
        {
            int item_id = n;
            int canteen = 4;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 11:
        {
            int item_id = n;
            int canteen = 4;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 12:
        {
            int item_id = n;
            int canteen = 4;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 13:
        {
            int item_id = n;
            int canteen = 5;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 14:
        {
            int item_id = n;
            int canteen = 5;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 15:
        {
            int item_id = n;
            int canteen = 5;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 16:
        {
            int item_id = n;
            int canteen = 5;
            printf("Case executed");
            printf("\n\nYou have succesfully added the items to the cart. Do you want to add other items? \nEnter 1 for new item\n Enter 0 for exit\n\n");
            int nextitem;
            scanf("%d", &nextitem);
            if (nextitem)
                continue;
            else
                entry = false;
            continue;
        }
        case 17:
        {
            entry = false;
            break;
            // generate bill code function call
        }
        default:
        {
            printf("\nInvalid Choice \n Enter again\n");
        }
        }
    }
    return 0;
}

/*
    The format
    id of the item
    quantity
    price
    \n\nYou have succesfully added the items to the cart. Do you want to add other items?\n\n


*/