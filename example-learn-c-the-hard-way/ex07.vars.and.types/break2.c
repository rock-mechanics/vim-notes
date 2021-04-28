#include<stdio.h>

int main( int argc, char * argv[] )
{
	char * names = "Jing";
	char * money = "money";
	names[4] = 'Z';
	printf("my names is %s\n", names);
	printf("my money is %s\n", money);
}

/* we can basically points to any memeory from one address of the array */
