#include<stdio.h>
#include"process_arg.h"
#include"dbg.h"

int main(int argc, char* argv[])
{
	int count = count_arg_lists(argc, argv);
	debug("the number of list is %d", count);

	struct string_list** lists = get_arg_lists(argc, argv);

	int i = 0;
	// print the lists
	for (i = 0; i < count; i++)
	{
		printf("list number %d : \n", i);
		print_list(lists[i]);
	}


	printf("test next_string_in_list\n");

	for (i = 0; i < count; i++)
	{
		printf("list number %d : \n", i);
		char* string = NULL;
		while((string = next_string_in_list(&(lists[i]))))
		{
			printf("list items : %s\n", string);
		}
	}

	// free the lists
	for (i = 0; i < count; i++)
	{
		free_list(lists[i]);
	}
	free(lists);
}

