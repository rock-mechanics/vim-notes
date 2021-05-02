#include<stdio.h>
#include"dbg.h"

#define MAX_DATA 10

typedef enum EyeColor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES, BLACK_EYES, OTHER_EYES
}EyeColor;

const char* EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
}Person;

int main(int argc, char* argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char * in = NULL;

	printf("What's you First Name? ");
	/* fget reads from 'stdin' file by MAX_DATA - 1 characters and save in you.first_name */
	/* this will includes the newline character */
	/* it will add a null character at the end, so the length should be one character shorter*/
	in = fgets(you.first_name, MAX_DATA - 1, stdin);
	check(in != NULL, "Failed to read first name");

	printf("What's you Last Name? ");
	in = fgets(you.last_name, MAX_DATA - 1, stdin);
	check(in != NULL, "Failed to read last name");

	printf("how old are you ? ");
	int rc = fscanf(stdin, "%d", &you.age);
	check(rc > 0, "You have to enter an number.");

	printf("What color are your eyes : \n");
	for(i = 0; i < OTHER_EYES; i++)
	{
		printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
	}
	printf(">  ");

	int eyes = -1;
	rc = fscanf(stdin, "%d", &eyes);
	check(rc > 0, "You have to enter an number.");

	you.eyes = eyes - 1;
	check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option");

	printf("How much do you make an hour? ");
	rc = fscanf(stdin, "%f", &you.income);
	check(rc > 0, "Enter a floating point number.");

	printf("\n--------Results-----------\n");

	printf("First Name: %s", you.first_name);
	printf("Last Name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);
	return 0;
error:
	return 1;
}
