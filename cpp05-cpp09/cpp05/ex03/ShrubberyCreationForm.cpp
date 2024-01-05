#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation",false, 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm 생성자 생성" << std::endl;
}
// ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation",false, 145, 137)
// {
// 	std::cout << "[OCCF]ShrubberyCreationForm 생성자 생성" << std::endl;
// }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target)
{
	std::cout << "[OCCF]ShrubberyCreationForm 복사 생성자 생성" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[OCCF]ShrubberyCreationForm 소멸자 생성" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy) {
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if(this->getIsSigned() && executor.getGrade() >= this->getExecuteGrade()) {
		std::ofstream target;
		target.open(this->target + "_Shrubbery");
		if(target.is_open())
			std::cout << "file open fail" << std::endl;

		else
		{
			target << "  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣀⡀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  \n"
						"⠀⢀⢀⠠⢄⠀⠀⠘⠀⠠⠼⡀⠠⠤⣀⣀⣾⣷⡾⣿⣷⣀⢳⣿⣿⣿⣦⣆⡠⢀⣀⡸⠄⢀⠘⠤⢄⠀⠤⢄⢀⠀⠀⠀⠡⠜⠀⠀⠀\n"
						"⠀⠀⠀⠀⠀⠀⢠⠀⠀⢠⠀⠀⢠⣿⣏⠱⢾⡙⢏⠟⡥⢩⠛⣼⠷⢫⡹⡿⢟⢿⣛⡿⣿⣷⣦⣠⣤⡄⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀\n"
						"⠰⠀⢰⠒⠁⠈⠒⣶⣬⣶⣟⠻⡹⢾⣿⠻⠍⠆⠈⠄⡀⢩⢆⠙⡀⠇⣉⢾⡾⣵⣾⣿⣯⢿⣟⣿⣿⣶⠐⠁⠐⠒⠁⠈⠀⠀⠀\n"
						"⢀⠀⢀⠀⢂⣰⣟⠏⡿⣿⣟⣳⣕⣻⣦⢋⡔⠀⠁⠠⠐⠈⡌⠀⢠⠐⣊⠲⣱⢻⡾⣽⣻⢿⣾⢟⣿⣿⣿⣤⣄⡀⠆⠸⠀⠀⠀\n"
						"⠀⠀⠈⠀⢰⣤⣶⣿⣯⣞⣽⣿⣛⢶⡺⣧⢆⣡⡀⠄⡁⠐⠤⢁⠢⢡⠄⣒⠦⢳⡡⣏⡖⢧⢫⢏⡜⣯⣿⣻⣽⢻⣿⣧⣄⣀⠀⠀⠀\n"
						"⠀⠠⢰⣶⠾⡟⡧⣿⢿⡿⣿⣽⣛⣶⣽⣯⣛⠤⣐⠈⡄⢩⠐⢂⡱⣠⢛⡴⢩⠳⣝⣭⢻⣭⡷⣎⣽⣽⣻⣷⢾⣩⣖⣿⡿⠋⠀⠀⠀\n"
						"⠀⠀⢀⣻⢮⡱⢻⣿⢯⣿⡙⡷⢻⡙⣾⣳⡿⣏⡙⣎⡐⡡⡜⢆⢧⡱⢎⠾⣥⢻⡼⣾⠻⡅⡛⡗⣿⢾⣻⣿⣟⣶⣿⣻⣷⡶⠀⠀⠀\n"
						"⠀⠨⢙⣿⣯⣷⡿⢇⠲⡅⠹⢈⠡⢏⡔⢫⣟⣾⣝⣦⣳⡱⣭⣞⢦⣝⢮⣻⡜⣧⣟⡹⠅⢀⠡⢙⠴⡻⢭⢓⡎⠗⣮⠿⣿⣦⡀⠀⠀\n"
						"⠀⢠⢭⡹⠬⣙⢳⡉⠂⢀⠐⠠⠑⡄⢬⢲⣹⣿⣿⣿⣷⣿⣷⣿⣷⣿⣿⣷⣹⣶⢏⡒⠀⠂⢀⠁⢊⠘⣇⠎⠘⡠⠃⡞⡥⠾⣧⡄⠀\n"
						"⢀⡸⡑⠆⠡⠐⢨⠚⠄⣀⠂⡅⢣⠼⣭⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⠀⢂⠀⠎⢠⠑⡈⠀⢂⠠⠑⠠⠜⡓⣎⣳⡦\n"
						"⡨⢒⠠⠀⡐⠈⡀⡘⠰⣠⢓⣬⢳⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣡⡐⠆⡨⠘⡀⠆⢀⠐⠀⡂⢌⡡⢆⣹⠴⣻⠀\n"
						"⠁⣇⠒⡁⠄⡠⢡⢈⣅⠲⣭⢾⣿⣿⣿⣿⣿⣿⣿⣿⡯⠿⢿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣽⣡⡗⣱⡜⡰⢂⠠⡑⡌⢀⡳⢍⣦⢻⣏⠁\n"
						"⠀⠗⣏⢄⢣⡔⣢⠝⣆⠷⣮⣷⣿⣿⣿⣿⣿⡿⠟⢿⣿⣶⣼⣿⡿⣧⣿⣿⠾⠛⢛⣿⣿⣿⣿⣿⣼⠱⣊⠶⡱⣍⢦⠹⣜⡸⢿⣅⠀\n"
						"⠀⢀⠙⠘⡯⣶⣿⣞⣿⣿⣾⣿⣿⣿⣿⣿⠛⣟⣆⠀⠙⣿⣿⣿⣿⣿⣿⠃⡆⠀⠀⣿⣿⣿⣿⣿⣷⣯⢧⣓⡳⡜⡶⣫⢼⣹⡧⠛⠁\n"
						"⠀⠀⠁⠀⠐⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠿⣿⣿⣆⠀⢸⣿⣿⣿⣿⡿⠀⠀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣧⣿⣵⣫⡵⠯⠾⠽⠃⠀⠀\n"
						"⠀⠈⠈⠀⠸⠤⡀⠻⠿⠛⢙⠟⠟⠁⠧⠔⠀⠠⠍⠛⢿⣿⣿⣿⣿⣿⣇⣴⣾⣿⠟⢋⠉⠻⢿⣿⣿⣿⣿⡿⠿⡀⠠⠤⡀⢀⠀⠀⠀\n"
						"⠀⢀⠠⠀⢠⠀⠀⠘⠀⠀⠘⠀⠀⠀⡄⢀⠀⠄⠠⠁⠂⠹⣿⣿⣿⣿⣿⣿⠛⠀⠀⠜⠀⠀⠈⠀⠈⢈⠀⢠⠀⠁⠠⠀⠀⠘⠀⠀⠀\n"
						"⠀⠈⠀⠒⠂⠈⠒⢲⠀⠐⠲⠁⠐⠒⠁⠀⠒⠀⠈⠒⠎⠈⣿⣿⣿⣿⡟⠁⠐⠒⠀⢱⠒⠀⠰⠒⠊⠀⠒⠊⠈⠒⠂⠀⠖⢲⠀⠀⠀\n"
						"⠀⠐⠀⢀⡰⠀⢀⣀⠀⢀⣀⠄⢀⣀⠆⠐⢀⠀⠐⣀⡀⠀⣿⣿⣿⣿⣻⠀⠆⣀⠀⢀⣀⠀⢀⣀⡀⠀⠀⡐⠀⢀⡀⠀⣀⣀⠀⠀⠀\n"
						"⠀⢀⢀⠤⢄⠀⠄⠘⠀⠀⠌⡀⠀⠠⡀⢀⠠⠀⢀⠤⠀⠀⣿⣿⣿⣿⣿⠀⡀⠀⠀⡸⠀⠀⠈⠤⠀⢀⠀⢄⢀⠂⠄⠀⠁⠜⠀⠀⠀\n"
						"⠀⠀⠀⠀⠀⠀⠄⢠⠀⠀⢠⠂⠀⠀⠃⠀⠀⠀⠀⠀⡄⠀⣿⣿⣿⣿⣿⡀⠃⠀⠀⢠⠀⠀⢠⠀⠄⠀⠀⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀\n"
						"⠀⢐⠰⠁⢐⠒⠀⠀⠂⠀⠈⠂⠀⠈⡆⠰⠀⠒⠐⠁⢐⢒⣿⣿⣿⣿⣿⡇⡎⠀⠂⡊⠀⠀⠂⠀⠑⠐⠁⢰⠐⠁⠐⠂⠀⠈⠀⠀⠀\n"
						"⠀⠀⢀⠀⢀⢀⠀⠸⠀⠀⠸⠀⠀⠀⡀⠀⠀⡀⢀⠂⠆⣸⣿⣿⣿⣿⣿⡇⡀⠀⡀⠸⠀⠀⢈⠀⠁⢀⠀⢀⢀⠃⢀⠀⠅⠸⠀⠀⠀\n"
						"⠀⠈⠀⠀⠘⠀⠀⢀⠀⠀⢠⠂⠀⠀⠃⠈⠀⠀⠐⠀⠀⣾⣿⣿⣿⣿⣿⣿⣀⠀⠀⢡⠀⠀⢀⠀⡀⠈⠀⠈⠀⡀⠀⠀⡀⢠⠀⠀⠀\n"
						"⠀⠠⢀⠒⢢⠀⠐⠊⠀⠐⠊⠄⠐⠒⡄⣀⣂⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣬⣒⡀⠈⠒⠀⠀⠐⢢⠀⠑⠂⠀⠑⠈⠀⠀⠀\n"
						"⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠐⠀⠀⠀⠁⠈⢀⠈⠉⡉⠍⠉⡏⠉⠉⠉⠉⠉⢉⠉⠀⢰⠁⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠐⠀";
		}
	}
	else
		throw ShrubberyCreationForm::FNotSigned();
}
