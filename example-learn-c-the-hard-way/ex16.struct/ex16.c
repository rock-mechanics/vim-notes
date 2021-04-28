#include<stdio.h>
#include<string.h> // this gives us the strdup function.
#include<assert.h> // this gives us assert function which can generate an error if condition is not met
#include<stdlib.h> // this gives us function like malloc.

struct Person
{
	char * name;
	int age;
	int height;
	int weight;
};

// function returns a pointer to a struct instance.
struct Person* Person_create(char * name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who -> name = strdup(name);
	who -> age = age;
	who -> height = height;
	who -> weight = weight;
	return who;
}

// in the function, the person itself is a pointer to memory
// the person name property is a pointer to memory. 
// they needs to be freed manually to allow other program to use that piece of memory.
void Person_destroy( struct Person *who )
{
	assert(who != NULL);
	free(who->name);
	free(who);
}

void Person_print( struct Person* who)
{
	printf("Name : %s\n", who->name);
	printf("\tAge : %d\n", who->age);
	printf("\tHeight : %d\n", who->height);
	printf("\tWeight : %d\n", who->weight);
}

int main(int argc, char* argv[])
{
	// make two person struct
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memeory location %p : \n", joe);
	Person_print(joe);

	printf("Frank is at memeory location %p : \n", frank);
	Person_print(frank);

	// 20 years later data
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	//destroy them both so we clean up.
	
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
