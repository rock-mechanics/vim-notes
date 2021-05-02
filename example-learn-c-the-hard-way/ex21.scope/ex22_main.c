#include "ex22.h"
#include "dbg.h"

// no need to include stdio.h cause we are using 
// debug to print io message

const char* my_name = "Jing Chen";

void scope_demo(int count)
{
	log_info("count before if is : %d", count);
	// if is a mini function predefined by c
	// starting of if function
	if (count > 10)
	{
		int count = 100;
		// overshadwo the count variable in block
		log_info("count in if is : %d", count);
	}
	// end of if function
	log_info("count after if is : %d", count);

	count = 300;
	log_info("count after assignment is : %d", count);
}

int main(int argc, char* argv[])
{
	log_info("My name: %s, age : %d", my_name, get_age());
	// we use get_age() directly without include it
	// this should compile, cause we include prototype
	// later we can link the c file to get the definition.
	
	set_age(100);
	log_info("My age is now %d", get_age());

	// directly access the extern variable.
	log_info("the size is %d", the_size);
	// access the variable from a function
	print_size();

	// update the ratio
	log_info("ratio at first: %f", update_ratio(2.0));
	log_info("ratio at again: %f", update_ratio(10.0));
	log_info("ratio at once more: %f", update_ratio(3000.0));

	double* myratio = update_my_ratio(5000.0);
	log_info("my ratio is %f", *myratio);

	*myratio = 1000.0;
	log_info("my ratio is %f", *myratio);

	double* another = update_my_ratio(5000.0);
	log_info("my ratio is %f", *another);


	// test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("count after calling scope demo: %d", count);
	return 0;
}

