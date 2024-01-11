#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib>
#include <ctime>
# define BB "\x1b[1m\x1b[48;2;188;143;143m"
# define DV "\x1b[1m\x1b[38;2;25;25;599m"
# define CC "\x1b[0m"

Base * generate() {
	int i = rand() % 3;
	if (i == 0) {
		std::cout << DV "A" CC " generated" << std::endl;
		return new A();
	}
	else if (i == 1) {
		std::cout << DV "B" CC " generated" << std::endl;
		return new B();
	}
	else {
		std::cout << DV "C" CC " generated" << std::endl;
		return new C();
	}
}

void identify(Base* p) {
	std::cout << "Type of base ptr: " DV;
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" CC << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" CC << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" CC << std::endl;
	else
		std::cout << "Unknown" CC << std::endl;
}

void identify(Base& p) {
	std::cout << "Type of base ref: " DV;
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" CC << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" CC << std::endl;
			(void)b;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "C" CC << std::endl;
				(void)c;
			}
			catch (std::exception &e) {
				std::cout << "Unknown" CC << std::endl;
			}
		}
	}
}

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 10; i++)
	{
		std::cout << BB "-------------------" CC << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
	return 0;
}