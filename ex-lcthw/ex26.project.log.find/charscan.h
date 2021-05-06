
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
