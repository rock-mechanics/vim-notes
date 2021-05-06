#ifndef __dbg_h__
#define __dbg_h__ //open the switch, and process the entire file, if the switch is already on, ignore the entire file
// the above is used to make sure this file is not included twice, the first time it will open the switch, the second time it will not include the same file.
// instead, it will do nothing

#include <stdio.h>
#include <errno.h>
#include <string.h>

// debug function is some useful info printing when you do testing/debuging when you develop the system.
// you don't want the user to see it. so when relese your software, you want to remove all the debug info.
// when you include #define NDEBUG in your code, all the debug function will expands to nothing.
#ifdef NDEBUG 
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
//__FILE__ and __LINE__ are predefined macros, they are the file name and the line number
//## __VA_ARGS__ is back reference to ... including everything comma etc.
//if M includes some format code such as %d, the arguments is there to fill in the template in the print out message
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
// char* strerror(int number)  : search the error number, and return a pointer to a string

// print error message
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// print warning message
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// print information message
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// check condition, if A not true, produce error. go to the error section
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// if this code ever run, produce an error. place it in place where the code should not run.
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// check if memory pointer is null, if it is , produce error. 
#define check_mem(A) check((A), "Out of memory.")

// print debug message if certain condition is true.
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
