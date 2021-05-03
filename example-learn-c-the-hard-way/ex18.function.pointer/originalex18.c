#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

void die(const char* msg);
int typedef (*comp_cb) (int a, int b);
int * bubble_sort(int* numbers, int count, comp_cb cmp);
int sorted_order(int a, int b);
int reverse_order(int a, int b);
int strange_order(int a, int b);
void test_sorting(int * numbers, int count, comp_cb cmp);

int main(int argc, char* argv[])
{
	if (argc < 2) die("Usage : ./ex18 3 4 5 56 ..");

	int count = argc - 1;
	// char** is a pointer to char*
	// argv is a char*
	// plus 1 makes the pointer moves by 1 element
	char** inputs = argv + 1;

	int* numbers = malloc(sizeof(int) * count);

	if (!numbers) die("Memory error");

	int i = 0;

	for (i = 0; i < count; i++)
	{
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	// numbers are defined using malloc
	free(numbers);
	return 0;
}

void die(const char* msg)
{
	if (errno)
	{
		perror(msg);
	}
	else
	{
		printf("Error : %s\n", msg);
	}
}
int * bubble_sort(int* numbers, int count, comp_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;

	int* target = malloc (sizeof(int) * count);

	if (!target) die("Memory error");

	memcpy(target, numbers, sizeof(int)* count);

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (cmp(target[j], target[j+1]) > 0)
			{
				temp = target[j];
				target[j] = target[j+1];
				target[j+1] = temp;
			}
		}
	}
	return target;
}
int sorted_order(int a, int b)
{
	return a - b;
}
int reverse_order(int a, int b)
{
	return b - a;
}
int strange_order(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}
	else
	{
		return a%b;
	}
	
}
void test_sorting(int * numbers, int count, comp_cb cmp)
{
	int i = 0;
	int* sorted = bubble_sort(numbers, count, cmp);

	if (!sorted) die("fail to sort the numbers");

	for (i = 0; i < count; i++)
	{
		printf("%d ", sorted[i]);
	}

	printf("\n");
	
	// sorted memory is allocated inside bubble sort using 
	// malloc, and passed out without freeing it.
	free(sorted);
}

