#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#include "FileIO.h"
#include "Canteen.h"
#include "Menu.h"

#define LINE_LEN 256

void *load_canteen(void *args)
{
    FILE *read = fopen("../Database/Canteen_Details.txt", "r");

    char *line = (char *)malloc(LINE_LEN * sizeof(char));
    size_t size = LINE_LEN;
    int i;
    while (1)
    {
        getline(&line, &size, read);

        if (strcmp(line, "EOF") == 0)
            break;

        sscanf(line, "Canteen Number: %d", &i);
        getline(&line, &size, read);
        sscanf(line, "ID: %ld", &canteens[i].ID);
        getline(&line, &size, read);
        sscanf(line, "Name: %[^\n]s", canteens[i].name);
        getline(&line, &size, read);
        sscanf(line, "Password: %s", canteens[i].password);
        getline(&line, &size, read);
        sscanf(line, "Total Orders: %ld", &canteens[i].total_orders);
        getline(&line, &size, read);
        sscanf(line, "Total Income: %ld", &canteens[i].total_income);
        getline(&line, &size, read); //. Blank Line
    }
    fclose(read);
}

void *save_canteen(void *args)
{
    FILE *write = fopen("../Database/Canteen_Details.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        fprintf(write, "Canteen Number: %d\nID: %ld\nName: %s\n", i, canteens[i].ID, canteens[i].name);
        fprintf(write, "Password: %s\n", canteens[i].password);
        fprintf(write, "Total Orders: %ld\nTotal Income: %ld\n\n", canteens[i].total_orders, canteens[i].total_income);
    }
    fprintf(write, "EOF");
    fclose(write);
}

void *load_menu(void *args)
{
    char *line = (char *)malloc(LINE_LEN * sizeof(char));
    size_t size = LINE_LEN;
    FILE *read = fopen("../Database/Menu_Details.txt", "r");
    int i;
    while (1)
    {
        getline(&line, &size, read);
        if (strcmp(line, "EOF") == 0)
            break;

        sscanf(line, "Canteen Index: %d", &i);
        getline(&line, &size, read);
        sscanf(line, "Items Available: %d", &canteens[i].items_avail);
        for (int j = 0; j < canteens[i].items_avail; j++)
        {
            getline(&line, &size, read);
            int x = atoi(line + (strlen(line) - 5 - 1));
            sscanf(line, "%[^:]s", canteens[i].Menu[j].name);
            canteens[i].Menu[j].price = x;
        }
        getline(&line, &size, read); //. Blank Line
    }
    fclose(read);
}

void *save_menu(void *args)
{
    FILE *write = fopen("../Database/Menu_Details.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        fprintf(write, "Canteen Index: %d\nItems Available: %d\n", i, canteens[i].items_avail);

        for (int j = 0; j < canteens[i].items_avail; j++)
            fprintf(write, "%s: %05d\n", canteens[i].Menu[j].name, canteens[i].Menu[j].price);

        fprintf(write, "\n");
    }
    fprintf(write, "EOF");
    fclose(write);
}

void load_data()
{
    pthread_t threadID[2];
    pthread_create(&threadID[0], NULL, (void *)load_canteen, NULL);
    pthread_create(&threadID[1], NULL, (void *)load_menu, NULL);

    int *retval;
    pthread_join(threadID[0], (void **)&retval);
    pthread_join(threadID[1], (void **)&retval);
    printf("data loaded\n");
}

void save_data()
{
    pthread_t threadID[2];
    pthread_create(&threadID[0], NULL, (void *)save_canteen, NULL);
    pthread_create(&threadID[1], NULL, (void *)save_menu, NULL);

    int *retval;
    pthread_join(threadID[0], (void **)&retval);
    pthread_join(threadID[1], (void **)&retval);
    printf("data saved\n");
}