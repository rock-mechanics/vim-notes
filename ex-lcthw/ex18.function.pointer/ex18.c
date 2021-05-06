#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

// compare_num becomes a type
typedef int (*compare_num) (int num1, int num2);

void bubble_sort( int numbers[], int count, compare_num cp)
{

	int i = 0;
	int j = 0;

	for (i = 0; i < count; i++)
	{
		for(j = 0; j < count -i - 1; j++)
		{
			if ( cp( numbers[j] ,numbers[j+1] ))
			{
				int temp = numbers[j+1];
				numbers[j+1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

int increase_order (int num1, int num2)
{
	if (num1 > num2) return 1;
	return 0;
}

int decrease_order (int num1, int num2)
{
	if (num1 < num2) return 1;
	return 0;
}

void print_ints(int* nums, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int main(int argc, char * argv[])
{
	int nums[] = {3, 4, 2, 5, 1};
	int size = 5;
	print_ints(nums, size);
	bubble_sort(nums, size, increase_order);
	print_ints(nums, size);
	bubble_sort(nums, size, decrease_order);
	print_ints(nums, size);
}


