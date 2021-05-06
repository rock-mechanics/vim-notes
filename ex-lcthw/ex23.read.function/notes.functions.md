# io functions

## fscanf 
fscanf takes three arguments
* file stream to read from for example `stdin`
* format string
	1. `%s`, reads to the next white space or new line or tab
	2. `%c`, reads the next character, there is no `null` char appended at end.
	3. `%10c`, reads the next 10 characters
* memory pointer to save the readed content.

