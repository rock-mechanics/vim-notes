#include<stdio.h>

int main(int argc, char* argv[] )
{
	char *name="thi";
	printf("let's print the string as an integer : %d\n", name);

	int number = 1200;
	//this will cause a segmentation fault.
	//printf("let's print the number as a string : %s\n", number);
}

