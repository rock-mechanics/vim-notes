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

char* next_string_in_list(struct string_list** list)
{
	if (!(*list) || !(*list)->head)
	{
		return NULL;
	}
	else
	{
		char* ret = (*list)->head;
		*list = (*list)->tail;
		return ret;
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

