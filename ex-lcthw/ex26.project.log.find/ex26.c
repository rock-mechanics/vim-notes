#include<stdio.h>
#include<stdlib.h>
#include"dbg.h"
#include<string.h>
#include<dirent.h>
#include"charscan.h"
#include"strlist.h"

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

	// process the files
	DIR* dir;
	struct dirent * entry;
	char* dirname = "./test/";

	// testing
	
	char* hello = argv[1];
	check(hello!=NULL, "usage : program <args>");

	int test_size = strlen(hello);

	dir = opendir(dirname);

	//initialize line string memory
	int line_size = 100;
	char* line = calloc(1, line_size + 1);
	int index = 0;

	//initialize scanner for all files
	struct char_scanner* sc = initialize_scanner(hello, test_size);

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s\n", entry->d_name);
		fflush(stdout);
		// strlen counts the no of characters before the null char.
		char fname [strlen(dirname) + strlen(entry->d_name) + 2];
		sprintf(fname, "%s%s", dirname, entry->d_name);
		FILE* f = fopen(fname, "r");
		if (!f) continue;
		char ch = fgetc(f);

		while(1)
		{
			if (ch == EOF)
			{
				if (sc->result) printf("\t%s\n", line);
				fflush(stdout);
				break;
			}
			else if (ch == '\n')
			{
				index = 0;
				if (sc->result) printf("\t%s\n", line);
				fflush(stdout);
				// scanning complete for this line. reset scanner
				reset_scanner(sc);
				// a new line is encoutered, clear the line buffer.
				memset(line, 0, line_size);
				ch = fgetc(f);
				continue;
			}
			line[index] = ch;
			scan_char(sc, ch);
			ch = fgetc(f);
			index++;
		}

		// reach the end of file, reset to start a new file
		reset_scanner(sc);
		// free memory for the scanner
		fclose(f);
	}

	close_scanner(sc);
	free(line);
	closedir(dir);

	// ends the file reading, start freeing memory

	for (i = 0; i < list_index; i++)
	{
		free_list (lists[i]);
	}
error:
	close_scanner(sc);
	free(line);
	closedir(dir);

	// ends the file reading, start freeing memory

	for (i = 0; i < list_index; i++)
	{
		free_list (lists[i]);
	}
	exit(1);
}

