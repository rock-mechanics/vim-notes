#include<stdio.h>

int main(int argc, char* argv[])
{
	int numbers[] = {10, 20, 30, 40};
	char name[] = "Zed";
	char full_name[] = {'z', 'e', 'd', ' ', 'a', '.', ' ', 's', 'h', 'a', 'w', '\0'};

	//this should cause an segmentation error.
	printf("the size of int is %u\n", sizeof(int));
	printf("the size of int[] is %u\n", sizeof(numbers));
	printf("\tthe number of int in this array is %d\n", sizeof(numbers)/sizeof(int));
	printf("the size of char is %u\n", sizeof(char));
	printf("the size of char[] is %u\n", sizeof(name));
	printf("\tthe number of char in this array is %d\n", sizeof(name)/sizeof(char));
	printf("the size of char[] is %u\n", sizeof(full_name));
	printf("\tthe number of char in this array is %d\n", sizeof(full_name)/sizeof(char));
	printf("%s\n", name);
}
