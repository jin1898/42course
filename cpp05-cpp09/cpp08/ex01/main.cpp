#include <ctime>
#include <list>
#include "Span.hpp"

static void out_of_range_test(void)
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
		std::cout << sp.getshortSpan() << std::endl;
		std::cout << sp.getlongestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void basic_test(void)
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Sp: " << sp.getshortSpan() << std::endl;
		std::cout << "Longest Sp: " << sp.getlongestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp2(sp);
	std::cout << "Shortest Sp2: " << sp2.getshortSpan() << std::endl;	
	std::cout << "Shortest Sp2: " << sp2.getlongestSpan() << "\n\n";

	Span sp3(2);
	sp3 = sp;
	std::cout << "Shortest Sp3: " << sp3.getshortSpan() << std::endl;	
	std::cout << "Shortest Sp3: " << sp3.getlongestSpan() << "\n\n";
}

static void several_number_test(void)
{
	srand(time(0));
	Span sp = Span(10000);
	try
	{
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(rand() % 200);
		std::cout << "Shortest Sp: " << sp.getshortSpan() << std::endl;
		std::cout << "Shortest Sp: " << sp.getlongestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp2 = Span(20000);
	try
	{
		sp2.addSeveralNumbers<std::vector<size_t> >(sp.getBegin(), sp.getEnd());
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		for (int i = 0; i < 10000; ++i)
			sp2.addNumber(rand() % 2000);
		std::cout << "Shortest Sp2: " << sp2.getshortSpan() << std::endl;
		std::cout << "Shortest Sp2: " << sp2.getlongestSpan() << "\n\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	out_of_range_test();
	basic_test();
	several_number_test();
	return (0);
}