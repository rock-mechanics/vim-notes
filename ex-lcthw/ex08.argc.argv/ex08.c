#include<stdio.h>

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		printf("You have only one argument, abort!\n");
	}
	else if (argc > 1 && argc < 4)
	{
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			printf("the %d th argument is %s\n", i, argv[i]);
		}
	}
	else
	{
		printf("You have too many arguments, abort!\n");
	}



}
