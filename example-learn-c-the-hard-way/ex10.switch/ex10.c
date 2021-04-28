#include<stdio.h>

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("you need one argument\n");

		// that is how you terminate a program.
		return 1;
	}

	int i = 0;

	for (i = 0; argv[1][i]!='\0'; i++)
	{
		switch (argv[1][i])
		{
			//fall through
			case 'a':
			case 'A' : 
				printf("A");
				break;
			//fall through
			case 'e':
			case 'E' : 
				printf("E");
				break;
			//fall through
			case 'i':
			case 'I' : 
				printf("I");
				break;
			//fall through
			case 'o':
			case 'O' : 
				printf("O");
				break;
			//fall through
			case 'u':
			case 'U' : 
				printf("U");
				break;
			default : 
				printf("x");
		}
	}
	printf("\n");
}
