#include<stdio.h>
#include"dbg.h"
#include<stdlib.h>

int main(int argc, char* argv[])
{
	printf("let's try fscanf, input a number\n");
	fflush(stdout);
	int number = 0;
	fscanf(stdin, "%d", &number);
	check(number!=0, "fscanf failed");
	printf("number is %d\n", number);

	FILE* f = fopen("test.txt", "r");
	check(f!=NULL, "file not opened correctly");
	char msg[20];
	memset(msg, 20, '\0');

	/* reads to next blank character */
	int rc = fscanf(f, "%s\n", msg);
	check(rc != 0, "fscanf failed");
	printf("msg is %s\n", msg);

	memset(msg, 20, '\0');
	/* reads fixed number of characters */
	rc = fscanf(f, "%19c", msg);
	check(rc != 0, "fscanf failed");
	printf("msg is %s\n", msg);

	fclose(f);

error:
	exit(1);
}
