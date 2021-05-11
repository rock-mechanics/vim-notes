#include<stdio.h>
#include"dbg.h"
#include<dlfcn.h> // dynamic link functions

typedef int (*lib_function) (const char* data);
// define a type called lib_function 
// which is a pointer to a function
// the fuction takes a string and return an int.


int main(int argc, char* argv[])
{
	check (argc == 4 , "Usage : ex29 libex29.so function data");
	
	char* lib_file = argv[1];
	char* function_to_run = argv[2];
	char* data = argv[3]

	// load the library, and return a pointer to the library
	void *lib = dlopen(lib_file, RTLD_NOW);
	check(lib != NULL, "Failed to open the library %s : %s", lib_file, dlerror());

	lib_function func = dlsym(lib, func_to_run);
	// go to lib pointed file, look for a symbol called $(func_to_run), then return the chunk of code to a ponter called func
	check(func != NULL, "Did not find %s function in the library %s : %s", func_to_run, lib_file, dlerror());

	// now we have a pointer to the function, we can run it.
	int rc = 0;
	rc = func(data);
	check(rc == 0, "Function %s return %d for data : %s", func_to_run, rc, data);

	rc = dlclose(lib);
	check(rc == 0, "Failed to close %s", lib_file);
	return 0;

error:
	return 1;
}
