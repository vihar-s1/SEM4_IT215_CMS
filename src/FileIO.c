#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "FileIO.h"
#include "Canteen.h"
#include "Menu.h"

void load_data()
{
    FILE *read = fopen("../Database/Canteen_Details1.txt", "r");

    char *line = (char *)malloc(100 * sizeof(char));
    for (int i = 0; i < 5; i++)
    {
        size_t size = 100;
        getline(&line, &size, read);
        sscanf(line, "Canteen ID: %ld", &canteens[i].ID);
        getline(&line, &size, read);
        sscanf(line, "Name: %[^\n]s", canteens[i].name);
        getline(&line, &size, read);
        sscanf(line, "Password: %s", canteens[i].password);
        getline(&line, &size, read);
        sscanf(line, "Total Orders: %ld", &canteens[i].total_orders);
        getline(&line, &size, read);
        sscanf(line, "Total Income: %ld", &canteens[i].total_income);
        getline(&line, &size, read);
    }
    fclose(read);
}

void save_data()
{
    FILE *write = fopen("../Database/Canteen_Details2.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        fprintf(write, "Canteen ID: %ld\nName: %s\n", canteens[i].ID, canteens[i].name);
        fprintf(write, "Password: %s\n", canteens[i].password);
        fprintf(write, "Total Orders: %ld\nTotal Income: %ld\n\n", canteens[i].total_orders, canteens[i].total_income);
    }
    fclose(write);
}