extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"

# define TEST_LIMIT 12

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
static char *s_hidden = "hi low\0don't print me lol\0";
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: s" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print("%s", ""));
	TEST(2, print(" %s", ""));
	TEST(3, print("%s ", ""));
	TEST(4, print(" %s ", ""));
	TEST(5, print(" %s ", "-"));
	TEST(6, print(" %s %s ", "", "-"));
	TEST(7, print(" %s %s ", " - ", ""));
	TEST(8, print(" %s %s %s %s ", " - ", "", "4", ""));
	TEST(9, print(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	TEST(10, print("%s%s%s", "1", "2", "3's a charm"));
	TEST(11, print(" NULL %s NULL ", NULL));
	TEST(12, print("%s", s_hidden));
	cout << ENDL;
	return (0);
}
