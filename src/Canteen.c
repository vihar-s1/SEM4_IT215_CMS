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
int canteen_login(long ID, char* password)
{
    struct Canteen *canteen = NULL;

    for (int i=0; i<5; i++)
    {
        if (canteens[i]->ID == ID)
        {
            if ( strcmp(canteens[i]->password, password) == 0 )
                return 0;
            else
                return -1;
        }
    }
    return 1;
}