#ifndef _ex22_h_
#define _ex22_h_

// makes the 'size' variable in ex22.c available to other .c files

extern int the_size;

// using extern only declares the variable without allocating the memory
// gets and sets an internal static variable in ex22.c

int get_age();
void set_age(int age);

// functon declaration is default extern. so other c files can access these functions.

// updates a static variable that's inside the update_ratio

double update_ratio(double ratio);
double* update_my_ratio(double ratio);
void print_size();

#endif
