#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Menu_item
{
    char name[40];
    int price;
    int current_order; // number of times the item is ordered by a particular customer
    int total_order;   // total number of times the item is ordered by all customers
};

// menu[i][j] -> i is the canteen number and j the item.
// struct Menu_item menu[5][100];

void display_menu(int canteen_no)
{
    if (canteen_no > 0 && canteen_no <= 5)
    {
        for (int i = 0; i < 50; i++)
        {
            printf("%d. %40s \t %3.2d\n", i + 1, menu[canteen_no - 1][i].name, menu[canteen_no - 1][i].price);
        }
    }
}

void order()
{
    int n;
    printf("There are 5 canteens numbered from 1 to 5.\nEnter the canteen number you want to order from: ");
    scanf("%d", &n);
    if (n >= 1 && n <= 5)
    {
        int it_no;
        printf("Enter the number of the item you wish to order: ");
        scanf("%d", &it_no);
        if (it_no >= 1 && it_no <= 100)
        {
            int qty;
            printf("Enter the quantity of item %d: ", it_no);
            scanf("%d", &qty);
            if (qty > 0 && qty < 51)
            {
                add_to_bill(n, it_no - 1, qty);
            }
            else{
                printf("Enter a valid quantity\n");
            }
        }
        else
        {
            printf("Enter a valid item number\n");
            return;
        }
    }
    else
    {
        printf("Enter a valid canteen number\n");
        return;
    }
}

void add_to_bill(int can_no, int it_no, int qty)
{
}

/*#define S_SIZE 10000

struct Student{
    long int id;
    char password[15];
};

struct Student students[S_SIZE][1];

int student_login_func(struct Student** arr, long int id, char* passwd){
    for(int i = 0; i < S_SIZE ; i++){
        if(id==student_details[i].id){
            if(strcmp(passwd==student_details[i].password)){
                printf("Logged in successfully\n");
                return 0;
            }
            else{
                printf("Incorrect password\n");
                return -1;
            }
        }
    }
    return 1;
}

int create_acc(long int id,char* passwd){
    struct Student *new_stud = malloc( sieof(struct student_details) );
}*/