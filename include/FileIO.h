#ifndef FILEIO_H
#define FILEIO_H

void *load_canteen(void *); // loads canteen data
void *save_canteen(void *); // saves canteen details
void *load_menu(void *);    // saves menu file
void *save_menu(void *);    // saves menu data

void load_data(); // loads data
void save_data(); // saves data

#endif // FILEIO_H