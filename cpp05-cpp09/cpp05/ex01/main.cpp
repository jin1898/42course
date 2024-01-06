#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form form;
	Form f1("f1", false, 50, 25);
	Form f2("f2", false, 100, 100);
	Form copy(f1);

	std::cout << form << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << copy << std::endl;
	std::cout << std::endl;

	std::cout << form << std::endl;
	form = f1;
	std::cout << std::endl;
	std::cout << form << std::endl;
	std::cout << f1 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Testing exceptions" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try {
        Form Wrong("wrong",false, 300, 5);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	try {
        Form Wrong2("wrong2", false, 142, -5);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	try {
        Form Wrong3("wrong3", false, -6, 587);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat bur1(150, "bur1");
	Bureaucrat bur2(1, "bur2");
	Bureaucrat bur3(75, "bur3");

	Form f3("f3", false, 100, 100);
	Form f32(f3);
	Form f33(f3);
	Form f4("f4", false, 75, 50);
	Form f42(f4);
	Form f43(f4);

	try {
		f3.beSigned(bur2);
		f32.beSigned(bur3);
		f33.beSigned(bur1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		f4.beSigned(bur2);
		f42.beSigned(bur3);
		f43.beSigned(bur1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	Form f5("f5", false, 100, 100);
	Form f52(f5);
	Form f53(f5);

	try {
		bur2.signForm(f5);
		std::cout << f5 << std::endl;
		bur3.signForm(f52);
		std::cout << f52 << std::endl;
		bur1.signForm(f53);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	Form f6("f6", false, 100, 100);
	Form f62(f6);
	Form f63(f6);

	try {
		bur2.signForm(f6);
		std::cout << f6 << std::endl;
		bur3.signForm(f62);
		std::cout << f62 << std::endl;
		bur1.signForm(f63);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

}