#include<stdio.h>
#include<stdlib.h>
#include"dbg.h"
#include<string.h>

struct string_list
{
	char * head;
	struct string_list* tail;
};

void free_list(struct string_list* list)
{
	if (list)
	{
		// the character array is staticlly allocated.
		// thus no need to free them.
		/* if (list->head) free(list->head); */
		if (list->tail) free_list(list->tail);
		free(list);
	}
}

struct string_list* get_a_list()
{
	struct string_list* new_list = malloc(sizeof (struct string_list));
	new_list->head = NULL;
	new_list->tail = NULL;
	return new_list;
}

void insert_string(struct string_list** list, char* str_content )
{
	if (!(*list)->head)
	{
		(*list)->head = malloc(sizeof(char*));
		(*list)->head = str_content;
	}
	else
	{
		struct string_list* new_list = get_a_list();
		new_list->head = malloc(sizeof(char*));
		new_list->head = str_content;
		new_list->tail = malloc(sizeof(struct string_list*));
		new_list->tail = *list;
		*list = new_list;
	}
}

int get_list_length(struct string_list* list)
{
	while (list && list->head)
	{
		return 1 + get_list_length(list->tail);
	}
	return 0;
}

void print_list(struct string_list* list)
{
	if (list && list->head)
	{
		printf("%s ", list->head);
		print_list(list->tail);
	}
}

int main(int argc, char* argv[])
{
	int max_list = 10;
	struct string_list* lists[max_list];
	int list_index = 0;
	lists[list_index] = get_a_list();
	int i = 0;

	// the first argument is omitted. which is the program name.
	for (i = 1; i < argc; i++)
	{
		if (strncmp("-o",argv[i], 2) == 0)
		{
			list_index++;
			lists[list_index] = get_a_list();
		}
		else
		{
			insert_string(&lists[list_index], argv[i]);
		}
	}

	for (i = 0; i <= list_index; i++)
	{
		printf("list %d : ", i);
		if (lists[i])
		{
			if (get_list_length(lists[i])) print_list(lists[i]);
		}
		printf("\n");
	}

	for (i = 0; i < list_index; i++)
	{
		free_list (lists[i]);
	}
}

