#include<stdio.h>

int main(int argc, char* argv[])
{
	// by default, c will fill uninitialized elements to 0
	// 0 is 0 by integer
	// 0 is null by character
	// 0 can be otherthings if data type is different
	// after all, all data are represented by integer and 0 is quite a special integer
	int numbers[4] = {1};
	char names[4] = {'a'};
	int spoiler[4] = {1, 2, 3, 4};

	// first print out the raw data.
	printf("%d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%d, %d, %d, %d\n", spoiler[0], spoiler[1], spoiler[2], spoiler[3]);
	printf("%c, %c, %c, %c\n", names[0], names[1], names[2], names[3]);

	// print the character array as string.
	printf("name : %s\n", names);

	// set up numbers
	
	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 2;
	numbers[3] = 3;

	// set up the name
	names[0] = 'Z';
	names[1] = 'e';
	names[2] = 'd';

	// let's left the last character.
	//
	// let's print out after they are initialized
	printf("%d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("%c, %c, %c, %c\n", names[0], names[1], names[2], names[3]);

	// print the character array as string.
	printf("name : %s\n", names);

	//let's define the string in another way
	char* another = "Zed";
	printf("another : %s\n", another);
	printf("%c, %c, %c, %c\n", another[0], another[1], another[2], another[3]);

	printf("let's see the integer value of the ending character : %d\n", another[3]);
	printf("so, character is integer by default, they are converted using ASCII table\n");
	printf("the null character is %d\n", '\0');

	return 0;
}
