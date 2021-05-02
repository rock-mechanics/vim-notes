#include<stdio.h>
#include "ex22.h"

// all the vairable and function decaration is imported here.

#include "dbg.h"

int the_size = 1000; //the variable is declared in ex22.h
//here is the definition with allocation of memory. it is external

static int the_age = 47;
//static means it is only accessible by this file

// other c file cannnot access it directly but with function calls
// they can get a copy of it.
int get_age()
{
	return the_age;
}

void set_age(int age)
{
	the_age = age;
}

double update_ratio(double new_ratio)
{
	static double ratio = 1.0;
	double old_ratio = ratio;
	ratio = new_ratio;
	return old_ratio;
}

double* update_my_ratio(double new_ratio)
{
	static double ratio = 1.0;
	log_info("ration before update %f", ratio);
	ratio = new_ratio;
	return &ratio;
}
void print_size()
{
	log_info("I think size is %d", the_size);
}

