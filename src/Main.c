#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>

#include "Canteen.h"
#include "Menu.h"
#include "FileIO.h"

long ID;
char password[15];

void (*old_SIGALRM)();

void new_SIGALRM()
{
    save_data();
    printf("No Response for Too Long...\nExiting...\n");
    signal(SIGALRM, old_SIGALRM);
    exit(-1);
}

int main()
{
    load_data();
    bool entry = true;
    signal(SIGALRM, new_SIGALRM);
    int childpid;

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

        int canteen_no, login; // canteen no for various canteen

        switch (choice)
        {
        case 1:
            /*childpid = fork();
            if (childpid != 0)
            {*/
            printf("Enter ID: ");
            scanf("%ld", &ID);
            printf("Enter Password: ");
            scanf("%s", password);
            /*    kill(childpid, SIGKILL);
            }
            else
            {
                sleep(SLEEP_TIME);
                kill(getppid(), SIGALRM);
                exit(0);
            }*/

            login = canteen_login(ID, password);
            if (login == -1) // for invalid password
            {
                printf("\nInvalid Password Entered!! Try Again!!\n");
                break;
            }
            else if (login == -2) // for  login id
            {
                printf("\nInvalid User ID!! Try Again!!\n");
                break;
            }
            else
                run_canteen_ui(login + 1); // running using canteen user interface
            getc(stdin);
            break;

        case 2:
            /*childpid = fork();
            if (childpid != 0)
            {*/
            printf("Enter Canteen Number From 1 to 5: ");
            scanf("%d", &canteen_no);
            /*kill(childpid, SIGKILL);
        }
        else
        {
            sleep(SLEEP_TIME);
            kill(getppid(), SIGALRM);
            exit(0);
        }*/

            if (1 <= canteen_no && canteen_no <= 5)
            {
                order(canteen_no); // function for various canteen selection
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

    return 0;
}