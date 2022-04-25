#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "Canteen.h"
#include "Menu.h"
#include "FileIO.h"

int main()
{
    load_data();
    bool entry = true;

    while (entry)
    {
        printf("\nPress Enter To Continue...");
        getc(stdin);

        system("clear");
        printf("__________________________________________\n\n");
        printf("WELCOME TO DNS CAFETERIA MANAGEMENT SYSTEM\n");
        printf("__________________________________________\n\n");
        printf("             Enter 0 to Exit              \n");
        printf("         Enter 1 for Canteen Login        \n");
        printf("          Enter 2 to Order Food           \n");
        printf("__________________________________________\n");

        printf("Your Choice: ");
        int choice;
        scanf("%d", &choice);
        printf("\n");

        if (choice == 0)
            return 0;

        int canteen_no;
        switch (choice)
        {
        case 1:
            /* code */
            break;

        case 2:
            printf("Enter Canteen Number From 1 to 5: ");
            scanf("%d", &canteen_no);

            if (1 <= canteen_no && canteen_no <= 5)
                order(canteen_no);
            else
                printf("Invalid Canteen Number Entered.\nTry Again!!\n");

            printf("\nPress Enter To Display Bill...");
            getc(stdin);
            print_bill();
            break;

        default:
            break;
        }
    }

    save_data();
    return 0;
}