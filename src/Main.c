#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Canteen.h"
#include "Menu.h"
#include "FileIO.h"


int main()
{
    load_data();
    save_data();
    return 0;
}