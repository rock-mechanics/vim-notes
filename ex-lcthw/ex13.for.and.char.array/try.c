#include<stdio.h>

int main(int argc, char * argv[])
{
	int i = 0;
	
	// go through each string in argv
	// skip argv[0] since it is the file path of the program
	//
	
	// assign the argv
	argv[2] = "this is good";

	printf("argc is %d\n", argc);
	
	for (i = 1; i < argc; i++)
	{
		printf("arg %d : %s\n", i, argv[i]);
	}

	// let's make our own array of strings
	
	char* states[] = {"California", NULL,  "Oregen", "Washington", "Texas"};
	

	int num_states = sizeof(states) / sizeof(char * );

	printf("the number of states is %d\n", num_states);

	for (i = 0; i < num_states; i++)
	{
		printf("state %d: %s\n", i, states[i]);
	}
}
