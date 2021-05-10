#include<stdio.h>
#include"dbg.h"
#include<assert.h>

void risky_copy(char* from, char* to );
int safer_copy(int from_size, char* from, int to_size, char* to );
int main(int argc, char* argv[])
{
	char from[] = "01234567";
	int from_size = sizeof(from);

	// since the array size can be calculated directly using sizeof
	char to [] = "abcdef";
	int to_size = sizeof(to);

	debug("copy string %s with size %d to string %s with size %d", from, from_size, to, to_size);
	int rc = safer_copy(from_size, from, to_size, to);

	check(rc > 0, "copy failed");
	check(to[to_size-1] == '\0', "string is not terminated");

	debug("result is %s with size %d", to, to_size);
error:
	return 1;
}
void risky_copy(char* from, char* to )
{
	int i = 0;
	
	while (from[i] != '\0')
	{
		// the size of `to` is never checked, thus it may cause buffer overflow
		to[i] = from[i];
		i++;
	}
}
int safer_copy(int from_size, char* from, int to_size, char* to )
{
	assert( from != NULL && to != NULL && "from and to cannot be null");
	// one byte is left for null character
	int smaller_size = from_size > to_size - 1 ? to_size - 1 : from_size;

	if (from_size < 0 || to_size <= 0)
	{
		return -1;
	}

	int i = 0;
	for (i = 0; i < smaller_size; i++)
	{
		debug("copy character %d : %c", i, from[i]);
		to[i] = from[i];
	}

	// end the to string with a null character
	to [smaller_size] = '\0';
	return i;
}
