extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 12

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: c" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print("%c", '0'));
	TEST(2, print(" %c ", '0'));
	TEST(3, print(" %c", '0' - 256));
	TEST(4, print("%c ", '0' + 256));
	TEST(5, print(" %c %c %c ", '0', 0, '1'));
	TEST(6, print(" %c %c %c ", ' ', ' ', ' '));
	TEST(7, print(" %c %c %c ", '1', '2', '3'));
	TEST(8, print(" %c %c %c ", '2', '1', 0));
	TEST(9, print(" %c %c %c ", 0, '1', '2'));
	TEST(10, print("%c", '\0'));
	TEST(11, print(" %c ", '\0'));
	TEST(12, print("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31));
	cout << ENDL;
	return (0);
}