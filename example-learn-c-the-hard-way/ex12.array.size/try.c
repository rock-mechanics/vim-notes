#include<stdio.h>

int main(int argc, char* argv[])
{
	char letters[] = {'a', 'b', 'c', 'd', '\0'};
	int numbers[] = {1, 2, 3, 4};

	char *mysecret = "this should not be shown";

	numbers[3] = letters[0];

	printf("int array overflow : %d\n", numbers[4]);
	printf("let's print the string : %s\n", letters);

	letters[4]=numbers;
	printf("assign the end of string to the start of the number array\n");
	printf("let's print the string : %s\n", letters);

}
