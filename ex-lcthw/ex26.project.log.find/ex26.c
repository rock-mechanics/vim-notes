#include<stdio.h>
#include<stdlib.h>
#include"dbg.h"
#include<string.h>
#include<dirent.h>
#include"charscan.h"
#include"strlist.h"
#include"process_arg.h"

int get_result(struct group_scanner** gscs, int size)
{
	int i = 0;
	int res = 0;
	for (i = 0; i < size; i++)
	{
		res += (gscs[i])->result;
	}
	return res;
}
void reset_all(struct group_scanner** gscs, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		reset_group_scanner(gscs[i]);
	}
}
void close_all(struct group_scanner** gscs, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		close_group_scanner(gscs[i]);
	}
}

int main(int argc, char* argv[])
{
	int list_count = count_arg_lists(argc, argv);
	struct string_list** lists = get_arg_lists(argc, argv);
	// print the arguments
	printf("argument lists : \n");
	int i = 0;
	for (i = 0; i < list_count; i++)
	{
		print_list(lists[i]);
	}

	printf("search results : \n");

	// process the files
	DIR* dir;
	struct dirent * entry;
	char* dirname = "./test/";
	dir = opendir(dirname);

	//initialize line string memory
	int line_size = 100;
	char* line = calloc(1, line_size + 1);
	int index = 0;

	//initialize group scanners for list 1
	struct group_scanner* gscs[list_count];
	i = 0;
	// list counts starts from index 0, there is one list there.
	for (i = 0; i < list_count; i++)
	{
		int string_count = get_list_length(lists[i]);
		gscs[i] = initialize_group_scanner(string_count);
		char* string = NULL;
		while((string = next_string_in_list(&(lists[i]))))
		{
			// build individual scanners
			struct char_scanner* sc = initialize_scanner(string, strlen(string));
			add_scanner(gscs[i], sc);
		}
	}

	while ((entry = readdir(dir)) != NULL)
	{
		// ignore the default directory which is . and ..
		if (strncmp(entry->d_name, ".", 1) == 0 || strncmp(entry->d_name, "..", 2) == 0) continue;
		printf("%s\n", entry->d_name);
		fflush(stdout);
		// strlen counts the no of characters before the null char.
		char fname [strlen(dirname) + strlen(entry->d_name) + 2];
		sprintf(fname, "%s%s", dirname, entry->d_name);
		FILE* f = fopen(fname, "r");
		if (!f) continue;

		// start to processing the file
		char ch = fgetc(f);
		while(1)
		{
			if (ch == EOF)
			{
				index = 0;
				if (get_result(gscs, list_count)) printf("\t%s\n", line);
				fflush(stdout);
				reset_all(gscs, list_count);
				break;
			}
			else if (ch == '\n')
			{
				index = 0;
				if (get_result(gscs, list_count)) printf("\t%s\n", line);
				fflush(stdout);
				reset_all(gscs, list_count);

				// a new line is encoutered, clear the line buffer.
				memset(line, 0, line_size);
				// get next character and continue next line
				ch = fgetc(f);
				continue;
			}

			line[index] = ch;
			index++;

			i = 0;
			for (i = 0; i < list_count; i++)
			{
				group_scan_char(gscs[i], ch);
			}
			ch = fgetc(f);
		}

		// process next file
		fclose(f);
	}

	close_all(gscs,list_count);
	free(line);
	closedir(dir);
}

