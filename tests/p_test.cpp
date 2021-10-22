extern "C"
{
#define new tripouille
#include "ft_printf.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "print.hpp"
#define TEST_LIMIT 10

int iTest = 1;
int testNumber;
char * testName;
bool showTest = false;
static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;
int main(int ac, char ** av)
{
	signal(SIGSEGV, sigsegv);
	cout << FG_LYELLOW << "category: p" << RESET_ALL;
	
	testName = av[0];
	if (ac != 1)
		printTestNumber(av[1], TEST_LIMIT);
	cout << endl;
	TEST(1, print(" %p ", -1));
	TEST(2, print(" %p ", 1));
	TEST(3, print(" %p ", 15));
	TEST(4, print(" %p ", 16));
	TEST(5, print(" %p ", 17));
	TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
	TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
	TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
	TEST(9, print(" %p %p ", 0, 0));
	TEST(10,print("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));
	cout << ENDL;
	return (0);
}