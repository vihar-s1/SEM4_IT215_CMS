#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "Canteen.h"

/*
. returns -1 if invalid password
. returns  1 if invalid ID
. returns  0 for valid ID and Password
*/
int canteen_login(long ID, char *password)
{
    struct Canteen *canteen = NULL;

    for (int i = 0; i < 5; i++)
    {
        if (canteens[i].ID == ID)
        {
            if (strcmp(canteens[i].password, password) == 0)
                return 0;
            else
                return -1;
        }
    }
    return 1;
}

void edit_menu_items(int can_no)
{
    int n;
    do
    {
        printf("Enter 1 to edit an item's name\nEnter 2 to edit an item's price\nEnter 3 to remove an item\nEnter 4 to replace an item\nEnter 5 to add a new item\nEnter 6 to stop editing\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            printf("Enter the item number whose name you want to edit: ");
            int no;
            scanf("%d", &no);
            if (no > 0 && no <= canteens[can_no].items_avail)
            {
                char new_name[40];
                scanf("%s", new_name);
                //canteens[can_no]->Menu[no - 1].name = new_name;
            }
            else
            {
                printf("Enter a valid item number\n");
            }
        }
        }
    } while (n != 6);
}