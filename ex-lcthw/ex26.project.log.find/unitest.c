#include<stdio.h>
#include"charscan.h"
#include"dbg.h"
#include<string.h>

int test_single_phrase(struct char_scanner* sc, char* test);
int test_group_scanner(struct group_scanner* gsc, char* test);

int main(int argc, char* argv[])
{
	
	char* phrase = "jing"; // target string
	char* testphrase1 = "this is a jjjing string";
	char* testphrase2 = "this is not a string";

	// test char scanner
	struct char_scanner* sc = NULL;
	sc = initialize_scanner(phrase, strlen(phrase));
	// this one should success
	check_debug(test_single_phrase(sc, testphrase1) == 1, "test 1 failed");
	// this one should fail
	check_debug(test_single_phrase(sc, testphrase2) == 0, "test 2 failed");
	close_scanner(sc);

	// test group scanner
	struct group_scanner* gsc = initialize_group_scanner( 2 );
	char* p1 = "jing";
	char* p2 = "string";
	struct char_scanner* sc1 = initialize_scanner(p1, strlen(p1));
	struct char_scanner* sc2 = initialize_scanner(p2, strlen(p2));
	// add these two scanner to the group scanner.
	add_scanner(gsc, sc1);
	add_scanner(gsc, sc2);
	check(test_group_scanner(gsc, testphrase1) == 1, "group test 1 failed");
	check(test_group_scanner(gsc, testphrase2) == 0, "group test 2 failed");
	return 0;
error:
	return 1;
}

int test_single_phrase(struct char_scanner* sc, char* test)
{
	reset_scanner(sc);
	int count = strlen(test);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		scan_char(sc, test[i]);
	}
	return sc->result;
}

int test_group_scanner(struct group_scanner* gsc, char* test)
{
	group_scan_string(gsc, test);
	return gsc->result;
}
