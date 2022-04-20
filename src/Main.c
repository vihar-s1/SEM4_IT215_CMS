#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Canteen.h"
#include "Menu.h"
#include "FileIO.h"


int main()
{
    load_data();
    printf("Hello World\n");
    save_data();
    printf("Hello World\n");
    return 0;
}