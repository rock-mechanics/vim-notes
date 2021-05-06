#define MAX_SIZE 500 
/* CPP will replace all the MAX_SIZE to 500 before compile the code.
 * all upper case is a convention for ease of read.
 */

#define NUMBER 1 , 2 , 3, 4, 5 
/* macros ends with one line */
#include<stdio.h>

int main(int argc, char* argv[])
{
	printf("expand the MAX_SIZE to %d\n", MAX_SIZE);

	printf("expands NUMBER to : \n");
	int number[] = {NUMBER};
	int i = 0;

	for (i = 0; i < sizeof(number)/sizeof(int); i++)
	{
		printf("\t%d\n",number[i] );
	}

	int X = 0;
	printf("X is %d before define\n", X);
	#define X 10
	/* the macro only takes effect after the definition line. */
	printf("X is %d after define\n", X);

	#undef X 
	/* stop the expansion */
	printf("X is %d after undefine\n", X);

	#define biggerone(a, b) a > b ? a : b
	printf("4 and 5, bigger one is %d\n", biggerone(4, 5));

	#define Y 100
	#define Z (Y + 100)
	/* macros are fully expanded before substitution of code text. */
	printf("Z is %d after expansion\n", Z);

	#define eprintf(...) fprintf (stderr, __VA_ARGS__)
	/* ... is for function takes variable arguments.
	 * __VA_ARGS__ is for back refer of all the supplied arguments
	 */
	eprintf("ha, this is good\n");

	#undef eprintf
	#define eprintf(msg...) fprintf (stderr, msg)
	/* this is the same as above, but with msg name for all the args
	 */
	eprintf("ha, this is good\n");


}


