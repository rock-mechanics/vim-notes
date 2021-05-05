#include<stdio.h>
#include<stdlib.h>
#include"dbg.h"
#include<string.h>
#include<dirent.h>

struct string_list
{
	char * head;
	struct string_list* tail;
};

struct char_queue
{
	char  head;
	struct char_queue* tail;
};

struct char_queue* get_a_char_queue()
{
	struct char_queue* new_list = malloc(sizeof (struct char_queue));
	new_list->head = '\0';
	new_list->tail = NULL;
	return new_list;
}

void enqueue_char(struct char_queue** list_ptr, char ch)
{
	if (*list->head == '\0')
	{
		*list->head = ch;
	}
	else
	{
		struct char_queue * new_list = get_a_char_queue();
		new_list->head = ch;
		*list_ptr->tail = malloc(sizeof(struct char_queue*));
		*list_ptr->tail = new_list;
		*list_ptr = new_list;
		new_list=NULL;
	}
};

char dequeue_char(struct char_queue** list_ptr)
{
	if (*list_ptr->head == '\0')
	{
		return '\0';
	}
	else
	{
		char ret = *list_ptr->head;
		*list_ptr = *list_ptr->tail;
		return ret;
	}
};

char free_char_queue(struct char_queue* list_ptr)
{
	if (list_ptr)
	{
		if (list_ptr->tail)
		{
			free_char_queue(list_ptr->tail);
		}
		free(list_ptr);
	}
};
// this struct used to store of the scanning result.
struct char_scanner
{
	char* target;
	int size;
	int index;
	int result; // the scanning results
};

void scan_char(struct char_scanner* scanner, char ch)
{
	if (scanner->result) return; // the scanning complete, no action
	if (scanner->target[scanner->index] == ch) // char is matched
	{
		scanner->index++; // match next char
		if (scanner->index >= scanner->size)
		{
			scanner->result = 1;
		}
	}
	else
	{
		if (scanner->index != 0) //matching in progress
		{
			scanner->index = 0; 
			// char not matched. start over, take this as first
			scan_char(scanner, ch);
		}
		// if match have not started, skip to next character
	}
}

struct char_scanner* initialize_scanner(char* target, int size)
{
	struct char_scanner* ptr = malloc(sizeof(struct char_scanner));
	ptr->index = 0;
	ptr->size = size;

	//copy the string
	ptr->target = calloc(1, size + 1);// one more space for null
	int i = 0;
	for(i = 0; i < size; i++)
	{
		ptr->target[i] = target[i];
	}
	ptr->result = 0;
	return ptr;
}

void close_scanner(struct char_scanner* scanner)
{
	if (scanner)
	{
		if(scanner->target)
		{
			free(scanner->target);
		}
		free(scanner);
	}
}

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

	// process the arguments
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

	// let's process the files
	DIR* dir;
	struct dirent * entry;
	char* dirname = "./test/";

	// testing
	char* hello = "hello";
	int test_size = strlen(hello);

	dir = opendir(dirname);
	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
		// strlen counts the no of characters before the null char.
		char fname [strlen(dirname) + strlen(entry->d_name) + 2];
		sprintf(fname, "%s%s", dirname, entry->d_name);
		FILE* f = fopen(fname, "r");
		if (!f) continue;
		char ch = fgetc(f);
		int count = 0;

		//initialize scanner
		struct char_scanner* sc = initialize_scanner(hello, test_size);
		
		while(ch != EOF)
		{
			if (ch == '\n')
			{
				count++;
			}
			scan_char(sc, ch);
			ch = fgetc(f);
		}

		printf("file %s : scan result is %d\n",entry->d_name, sc->result);

		close_scanner(sc);
		fclose(f);
	}

	closedir(dir);

	// ends the file reading, start freeing memory

	for (i = 0; i < list_index; i++)
	{
		free_list (lists[i]);
	}
}

