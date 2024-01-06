#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));
    
    Intern someRandomIntern;
    
    AForm* scf;
    
    try {
        scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Richard");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        delete scf;
    }

    if(scf)
    {
        std::cout << *scf << std::endl;
        std::cout << std::endl;
    }
    else
    {std::cout << "[scf오류로인한 출력 불가!]" << std::endl;}
    AForm* rrf;
    
    try {
        rrf = someRandomIntern.makeForm("Robotomm", "Bender");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        delete rrf;
    }

    if(rrf)
    {
        std::cout << *rrf << std::endl;
        std::cout << std::endl;
    }
    else
    {std::cout << "[rrf오류로인한 출력 불가!]" << std::endl;}
    AForm* ppf;
    
    try {
        ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Hector");
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        delete ppf;
    }
    if(ppf)
    {
        std::cout << *ppf << std::endl;
        std::cout << std::endl;
    }
    else
    {std::cout << "[ppf오류로인한 출력 불가!]" << std::endl;}

    delete ppf;
    delete rrf;
    delete scf;
    std::cout << *ppf << std::endl;
}