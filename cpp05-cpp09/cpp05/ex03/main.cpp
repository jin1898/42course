#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void) {
	std::srand(std::time(NULL));
    
    Intern someRandomIntern;
    
    AForm* scf;
    
    try {
        scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Richard");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *scf << std::endl;

    std::cout << std::endl;

    AForm* rrf;
    
    try {
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *rrf << std::endl;

    std::cout << std::endl;
    
    AForm* ppf;
    
    try {
        ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Hector");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << *ppf << std::endl;
}