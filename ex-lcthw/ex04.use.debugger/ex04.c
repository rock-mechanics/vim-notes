#include<stdio.h>

// a common program to clash on purpose.
static void clash()
{
	// character pointer is a start of the string
	// in C, strings has no ideas where to end.

	char * values = "fixed"; 

	int i = 0;
	for (i = 0; i < 10000000 ; i++)
	{
		printf("the %dth character is %c\n", i, values[i]);
	}
}
int main (int argc, char * argv[])
{
	printf("argc is %d\n", argc);
	printf("argv is %s\n", argv[0]);
	printf("let's run this clash program\n");
	clash();
	return 0;
}
