#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"strlist.h"

int count_arg_lists(int argc, char* argv[])
{
	int i = 0;
	int count = 0;
	if (argc < 2) return 0;
	// strncmp returns zero if string are matched.
	if (strncmp(argv[1], "-o", 2) != 0) count++; // at least there is one string list.
	if (strncmp(argv[argc-1], "-o", 2) == 0) count--; // last argument is missing

	for(i = 1; i < argc; i++)
	{
		if (strncmp(argv[i], "-o", 2) == 0)
		{
			count++;
		}
	}
	return count;
}

struct string_list** get_arg_lists(int argc, char* argv[])
{
	int max_list = 10;
	struct string_list** lists = malloc(sizeof(struct string_list* ) * max_list);

	int list_count = 0; 

	lists[list_count] = get_a_list();
	int i = 0;
	for (i = 1; i < argc; i++)
	{
		if (strncmp("-o",argv[i], 2) == 0)
		{
			list_count++;
			lists[list_count] = get_a_list();
		}
		else
		{
			insert_string(&(lists[list_count]), argv[i]);
		}
	}
	return lists;
}
