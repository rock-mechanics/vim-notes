#include<stdio.h>
#include<ctype.h>
#include<string.h>

// ctype.h contains character process functions such as isalpha and isblank
// forward declaration 

int can_print_it(char ch);
void print_letters( int len, char arg[]);

void print_arguments(int argc, char* argv[])
{
	int i = 0;
	for (i = 1; i < argc ; i++)
	{
		int length = strlen(argv[i]);
		print_letters(length, argv[i]);
	}
}

void print_letters(int len, char arg[] )
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		char ch = arg[i];
		if (can_print_it(ch))
		{
			printf("'%c' == %d\n", ch, ch);
		}
	}
}

int can_print_it(char ch)
{
	return isalpha(ch) || isblank(ch);
}

int main(int argc, char * argv[])
{
	print_arguments(argc, argv);
	return 0;
}





