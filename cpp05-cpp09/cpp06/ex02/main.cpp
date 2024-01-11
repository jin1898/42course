#include "./Base.hpp"
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate() {
	int i = rand() % 3;
	if (i == 0) {
		std::cout <<  "Congratulations, [A] has been generated" << std::endl;
		return new A();
	}
	else if (i == 1) {
		std::cout << "Congratulations, [B] has been generated" << std::endl;
		return new B();
	}
	else {
		std::cout << "Congratulations, [C] has been generated" << std::endl;
		return new C();
	}
}

void identify(Base* p) {
	std::cout << "<Which pointer is base?>" << std::endl;
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	std::cout << "<Which Reference is base?>" << std::endl;
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 10; i++)
	{
		std::cout << "-start------------------" << std::endl;
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << "------------------end-" << std::endl;
	}
	return 0;
}
