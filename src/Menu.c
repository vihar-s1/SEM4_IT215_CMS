#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Menu.h"
#include "Canteen.h"

#define LINE_LEN 256

void display_menu(int canteen_no) //. canteen_no from 1 to 5
{
    if (canteen_no > 0 && canteen_no <= 5)
    {
        printf("%s\n\n", canteens[canteen_no - 1].name);
        for (int i = 0; i < canteens[canteen_no - 1].items_avail; i++)
        {
            printf("%d. %-40s \t %3.2d\n", i + 1, canteens[canteen_no - 1].Menu[i].name, canteens[canteen_no - 1].Menu[i].price);
        }
    }
    else
        printf("Invalid Canteen Number!!\n");
}

void create_bill(int can_no)
{
    if (0 >= can_no || can_no > 5)
        return;

    FILE *bill = fopen("../Database/bill", "w");
    fprintf(bill, "----------------------------------------------------------\n");
    fprintf(bill, "Canteen: %s\nID: %ld\n", canteens[can_no - 1].name, canteens[can_no - 1].ID);
    fprintf(bill, "----------------------------------------------------------\n\n");
    fprintf(bill, "ITEM NAME------------------------------PRICE---QTY---TOTAL\n\n");

    fclose(bill);
}

void add_to_bill(int can_no, int it_no, int qty)
{
    FILE *bill = fopen("../Database/bill", "ab");

    int price = canteens[can_no - 1].Menu[it_no - 1].price;
    fprintf(bill, "%-40s %3d    %02d   %5d\n", canteens[can_no - 1].Menu[it_no - 1].name, price, qty, price * qty);
    getc(stdin);
    

    canteens[can_no - 1].total_orders += qty;
    canteens[can_no - 1].total_income += qty * price;
    canteens[can_no - 1].Menu[it_no - 1].current_order += qty;
    canteens[can_no - 1].Menu[it_no - 1].total_order += qty;
    
    fclose(bill);
}

void print_bill()
{
    FILE *bill = fopen("../Database/bill", "r");
    char *line = malloc(LINE_LEN * sizeof(char));

    size_t size = LINE_LEN;
    system("clear");
    do
    {
        getline(&line, &size, bill);
        if (strcmp(line, "EOF") == 0)
            break;
        printf("%s", line);

    } while (1);

    fclose(bill);
    free((void *)line);
}