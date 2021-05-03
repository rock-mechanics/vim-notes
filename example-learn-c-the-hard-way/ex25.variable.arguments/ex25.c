#include<stdio.h>
#include<stdarg.h>
#include"dbg.h"
#include<stdlib.h>

#define MAX_DATA 100 

int read_string(char** out_string, int max_buffer)
{
	*out_string = calloc(1, max_buffer + 1);
	check_mem(*out_string);

	char* result = fgets(*out_string, max_buffer, stdin);
	check(result != NULL, "Input error");

	return 0;
error: 
	// free the allocated memeory
	if(*out_string) free(*out_string);
	// make the pointer pointes to nothing instead of the illegal memory
	*out_string = NULL;
	return -1;
}

int read_int(long* out_int)
{
	char* input = NULL;
	char* end = NULL;
	int rc = read_string(&input, MAX_DATA);
	check(rc != 0, "Failed to read the number");

	*out_int = strtol(input, &end, 10);
	check((*end == '\0' || *end == '\n') && *input != '\0' , "Invalid number: %s", input);

	free(input);
	return 0;
error:
	if(input) free(input);
	return -1;
}

int read_scan(const char* fmt, ...)
{
	int i = 0;
	int rc = 0;
	long *out_int = NULL;
	char *out_char = NULL;
	char **out_string = NULL;
	int max_buffer = 0;

	//set up the variable argument list
	va_list arglist;
	// fill up the argument list
	va_start(arglist, fmt);

	// loop through all the format string
	for(i = 0; fmt[i] != '\0'; i++)
	{
		if (fmt[i] == '%') // a format argumet is encoutered
		{
			i++; // move to the next character
			switch(fmt[i])
			{
				case '\0':
					sentinel("Invalid format, you ended with %%");
					break;
				case 'd':
					out_int = va_arg(arglist, long*); //va_arg gets the next arguments, which has type long* 
					// out_int has the same address value as the argument
					// let's fill in the value from user input
					rc = read_int(out_int);
					check(rc == 0, "Failed to read int");
					break;
				case 'c' : 
					out_char = va_arg(arglist, char*);
					*out_char = (char)fgetc(stdin);
					break;
				case 's' : 
					max_buffer = va_arg(arglist, int); // next argument is an int
					out_string = va_arg(arglist, char**); // next argument is a pointer to a string
					rc = read_string(out_string, max_buffer); // modify the underlying string it points to
					check(rc == 0, "Failed to read string.");
					break;
				default:
					sentinel("Invalid format");
			}
		}
		else
		{
			fgetc(stdin);
		}
		check(!feof(stdin) && !ferror(stdin), "Input Error");
	}
	va_end(arglist);
	return 0;
error:
	va_end(arglist);
	return -1;
}

int main(int argc, char* argv[])
{
	char * first_name = NULL;
	char initial = '';
	char * last_name = NULL;
	long age = 0;

	int rc = 0;
	printf("What's your first name? ");
	rc = read_scan("%s", MAX_DATA, &first_name);
	check(rc == 0, "Failed first name");

	printf("What's your last name? ");
	rc = read_scan("%s", MAX_DATA, &last_name);
	check(rc == 0, "Failed last name");

	printf("What's your intial? ");
	rc = read_scan("%c", &initial);
	check(rc == 0, "Failed initial");

	printf("How old are you ?");
	rc = read_scan("%d", &age);
	check(rc == 0, "Failed read age");

	printf("-----Results-----");
	printf("First Name : %s", first_name);
	printf("Initial : %c\n", initial);
	printf("Last Name : %s", last_name);
	printf("Age : %ld", age);

	free(first_name);
	free(last_name);

	return 0;
error:
	return -1;
}
