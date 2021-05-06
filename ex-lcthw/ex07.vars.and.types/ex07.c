#include<stdio.h>
#include<math.h>

int int_power(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x;
	}
	else
	{
		return x * int_power(x, y - 1);
	}
}

long long long_power(long long x, long long y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x;
	}
	else
	{
		return x * int_power(x, y - 1);
	}
}

int main (int argc, char * argv[])
{
	int distance = 100;
	float power = 2.345f;
	double superpower = 56789.4532;
	char initial = 'A';
	char firstname[] = "Zed";
	char lastname[] = "Shaw";

	printf("You are %d miles away\n", distance);
	printf("You are %f levels of power\n", power);
	printf("You are %f levels of superpower\n", superpower);
	printf("I have an intial of %c\n", initial);
	printf("I have an first name of %s\n", firstname);
	printf("I have an last name of %s\n", lastname);


	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at an imaginary rate of %f\n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs\n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("This is just %e portion of the universe\n", part_of_universe);

	char nullbyte = '\0';
	int care_percent = bugs * nullbyte;

	printf("Which means you should care %d%%\n", care_percent);

	printf("\n");
	printf("the size of an int is %lu\n", sizeof( int ));
	printf("\tthis is a signed integer, it contains 4 bytes = 4 * 8 = 32 bits, the first bit is the sign\n");
	printf("\tthere is a place for 0 in the positive range, the largest number is %d, if we add 1, we get %d\n", int_power(2,31)-1, int_power(2,31));
	printf("\tthe smallest number is %d, if we minus 1, we get %d\n", -int_power(2,31), -int_power(2,31) - 1);
	printf("\tthat is an integer overflow\n");
	printf("\n");
	printf("the size of an long is %lu\n", sizeof( long ));
	printf("the size of an long long is %lu\n", sizeof( long long ));
	printf("the size of an float is %lu\n", sizeof( float ));
	printf("the size of an double is %lu\n", sizeof( double ));

	return 0;
}
