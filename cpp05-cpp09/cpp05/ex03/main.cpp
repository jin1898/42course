#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
    Bureaucrat berau(137, "beru");
    ShrubberyCreationForm form("houssam");
    RobotomyRequestForm form2("Robot");
    try
    {
        berau.signForm(form);
        berau.executeForm(form);
        berau.signForm(form2);
        berau.executeForm(form2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (0);
    }
}
