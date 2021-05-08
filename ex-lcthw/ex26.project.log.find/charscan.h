#include<stdlib.h>
#include<string.h>

// this struct is used to scan a list of characters one by one
// it tells whether the target string is contained in the char list
struct char_scanner
{
	char* target;
	int size;
	int index;
	int result; // the scanning results
};

// allocate memory for the scanner
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

// receive chars in consecutively.
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

// restart the scanner
void reset_scanner(struct char_scanner* scanner)
{
	scanner->index = 0;
	scanner->result = 0;
}

// close the scanner and free the memory
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


struct group_scanner
{
	int scanner_capacity;
	int scanner_count;
	struct char_scanner** scanners;
	int result;
};

struct group_scanner*  initialize_group_scanner( int scanner_cap )
{
	struct group_scanner* ptr = malloc(sizeof(struct group_scanner));
	ptr->scanner_capacity = scanner_cap;
	ptr->scanner_count = 0; // there are zero scanner in it.
	ptr->result = 0;
	ptr->scanners = malloc(sizeof(struct char_scanner) * scanner_cap);
	return ptr;
}

void add_scanner(struct group_scanner* ptr, struct char_scanner* sc)
{
	if (!ptr) return;
	if (!sc) return;
	if (ptr->scanner_count < ptr->scanner_capacity)
	{
		ptr->scanners[ptr->scanner_count] = sc;
		ptr->scanner_count++;
	}
}

void group_scan_char(struct group_scanner* ptr, char ch)
{
	int temp_res = 1;
	if (ptr->scanner_count == 0) temp_res = 0;
	int i = 0;
	for (i = 0; i < ptr->scanner_count; i++)
	{
		scan_char(ptr->scanners[i], ch); 
		temp_res *= ptr->scanners[i]->result;
	}
	ptr->result = temp_res;
} 

void close_group_scanner(struct group_scanner* ptr)
{
	int i = 0;
	for (i = 0; i < ptr->scanner_count; i++)
	{
		close_scanner(ptr->scanners[i]);
	}
	free(ptr->scanners);
	free(ptr);
}

void reset_group_scanner(struct group_scanner* ptr)
{
	int i = 0;
	for (i = 0; i < ptr->scanner_count; i++)
	{
		reset_scanner(ptr->scanners[i]);
	}
	ptr->result = 0;
}

void group_scan_string(struct group_scanner* gsc, char* test_string)
{
	reset_group_scanner(gsc);
	int count = strlen(test_string);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		group_scan_char(gsc, test_string[i]);
	}
}
