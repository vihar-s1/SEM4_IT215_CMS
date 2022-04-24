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
        system("clear");
        printf("__________________________________________\n\n");
        printf("WELCOME TO DNS CAFETERIA MANAGEMENT SYSTEM\n");
        printf("__________________________________________\n\n");
        printf("             Enter 0 to Exit              \n");
        printf("         Enter 1 for Canteen Login        \n");
        printf("          Enter 2 to Order Food           \n");
        printf("__________________________________________\n");

        printf("Enter Your Choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0)
            return 0;

        switch (choice)
        {
        case 1:
            /* code */
            break;

        default:
            break;
        }
    }

    save_data();
    return 0;
}