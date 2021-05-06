#include<stdio.h>

int main(int argc, char* argv[])
{
	printf("pointer and array are alike, but they are not the same.\n");
	printf("let's define an array\n");
	
	char ahello[] = {'h', 'e', 'l', 'l', 'o'};
	//let's leave the last digit for null, so they have the same elements.
	char * phello = "hell";

	int number = 100;
	int * pointer_number = &number;

	printf("the size of array hello is %d\n", sizeof(ahello));
	printf("the size of pointer hello is %d\n", sizeof(phello));
	printf("the size of number is %d\n", sizeof(number));
	printf("the size of pointer to number is %d\n", sizeof(pointer_number));

	printf("\n");
	printf("pointer is an addres, it contains 8 bytes\n");
	printf("array is arbitary size depends on the elements in it\n");
}
