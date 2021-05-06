#include<stdio.h>
#include"dbg.h"

int normal_copy(char* from, char* to , int count)
{
	int i = 0;
	for(i = 0; i < count; i++)
	{
		to[i] = from[i];
	}
	return i;
}

int duffs_device(char* from, char* to, int count)
{
	/* numbers of 8 and offset by 1 */
	int num_chunk = (count + 7) / 8; 

	switch (count % 8)
	{
		case 0 : 
			do {
				*to++ = *from++;
				case 7 : *to++ = *from++;
				case 6 : *to++ = *from++;
				case 5 : *to++ = *from++;
				case 4 : *to++ = *from++;
				case 3 : *to++ = *from++;
				case 2 : *to++ = *from++;
				case 1 : *to++ = *from++;
			}while(--num_chunk > 0);
	}
	return count;
}

int my_device(char* from, char* to , int count)
{
	/* numbers of 8 and offset by 1 */
	int num_chunk = (count + 7) / 8; 

	switch (count % 8)
	{
loop:	case 0 : *to++ = *from++;
		case 7 : *to++ = *from++;
		case 6 : *to++ = *from++;
		case 5 : *to++ = *from++;
		case 4 : *to++ = *from++;
		case 3 : *to++ = *from++;
		case 2 : *to++ = *from++;
		case 1 : *to++ = *from++;
		if (--num_chunk > 0) goto loop;
	}
	return count;
}

int check_string(char* target, char expect, int count)
{
	int i = 0;
	for (i = 0; i < count; i++) 
	{
		check(target[i] == expect, "check failed.");
	}
	return 0;
error:
	return -1;
}
int main(int argc, char* argv[])
{
	char from[100] = {'a'};
	char to[100] = {'b'};
	
	/* initialize the two array into different values */
	memset(from, 'x', 100);
	memset(to, 'y', 100);

	/* copy normal and check */
	int res = 0;
	normal_copy(from, to, 100);
	res = check_string(to, 'x',100);
	if (res == 0) printf("normal copy checks pass\n");

	/* reset */
	memset(to, 'y', 100);
	duffs_device(from, to, 100);
	res = check_string(to, 'x',100);
	if (res == 0) printf("duffs device check pass\n");

	/* reset */
	memset(to, 'y', 100);
	my_device(from, to, 100);
	res = check_string(to, 'x',100);
	if (res == 0) printf("my device check pass\n");
}
