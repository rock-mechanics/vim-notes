#include<stdio.h>

int main( int argc, char * argv[] )
{
	char * names = "Jing";
	printf("my name is %s\n", names + 100000000000);
}

// names is an address of the first character of "Jing", which is "J"
// when added by a number, what you do is shift the address to somewhere else in the memory. which is illegal to use.
// thus a segmentation error occurs.
