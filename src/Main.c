#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#include "Canteen.h"
#include "Menu.h"
#include "FileIO.h"

void (*old_SIGALRM)();

void new_SIGALRM()
{
    printf("\nSession Timed Out!!\n");
    return;
}

long ID;
char password[15];

int main()
{
    old_SIGALRM = signal(SIGALRM, new_SIGALRM);

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

        printf("\nYour Choice: ");
        int choice;
        scanf("%d", &choice);
        printf("\n");

        if (choice == 0)
            break;

        int canteen_no, login;

        switch (choice)
        {
        case 1:
            printf("Enter ID: ");
            scanf("%ld", &ID);
            printf("Enter Password: ");
            scanf("%s", password);

            login = canteen_login(ID, password);
            if (login == -1)
            {
                printf("\nInvalid Password Entered!! Try Again!!\n");
                break;
            }
            else if (login == -2)
            {
                printf("\nInvalid User ID!! Try Again!!\n");
                break;
            }
            else
                run_canteen_ui(login + 1);
            break;

        case 2:
            printf("Enter Canteen Number From 1 to 5: ");
            scanf("%d", &canteen_no);

            if (1 <= canteen_no && canteen_no <= 5)
            {
                order(canteen_no);
                printf("\nPress Enter To Display Bill...");
                getc(stdin);
                print_bill();
            }
            else
            {
                printf("Invalid Canteen Number Entered.\nTry Again!!\n");
                getc(stdin);
            }
            break;

        default:
            printf("incorrect Choice!! Try Again!!\n");
            break;
        }
    }

    save_data();

    signal(SIGALRM, old_SIGALRM);
    return 0;
}