#include"dbg.h"
#include<stdio.h>
#include<stdlib.h>
void test_debug();
void test_log_err();
void test_log_warn();
void test_log_info();
int main(int argc, char* argv[])
{
	/* check(arg == 2, "Need an argument"); */
	test_debug();
	/* test_log_err(); */
	/* test_log_warn(); */
	/* test_log_info(); */

}

void test_debug()
{
	debug("I have brown hair");
	debug("I am %d old %d tall", 67, 180);
}
