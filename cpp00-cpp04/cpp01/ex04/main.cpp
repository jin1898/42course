#include <fstream>
#include <iostream>
#include <string>

bool check_arg(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "ft_sed: usage: ./ft_sed <filename> <old string> <new string>" << std::endl;
		return false;
	}
	if (argv[2][0] == '\0')
	{
		std::cout << "ft_sed: first RE may not be empty" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (!check_arg(argc, argv))
		return 0;
	std::ifstream inputFS(argv[1]);
	std::string oldString(argv[2]);
	std::string newString(argv[3]);
	if (!inputFS.is_open())
	{
		std::cout << "ft_sed: file open error" << std::endl;
		return 0;
	}
	std::ofstream outputFS(std::string(argv[1]).append(".replace").c_str());
	if (!outputFS.is_open())
	{
		std::cout << "ft_sed: file open error" << std::endl;
		return 0;
	}
	while (inputFS && outputFS)
	{
		std::string inputLine;
		std::string::size_type found;
		std::string::size_type pos = 0;
		std::getline(inputFS, inputLine);
		while ((found = inputLine.find(oldString, pos)) != std::string::npos)
		{
			inputLine.erase(found, oldString.length());
			inputLine.insert(found, newString);
			pos = found + newString.length();
		}
		if (inputLine.length() > 0)
		{
			outputFS << inputLine;
		}
		if (inputFS.eof())
		{
			int c;
			inputFS.seekg(-inputFS.gcount(), inputFS.cur);
			while ((c = inputFS.get()) != EOF)
			{
				outputFS << static_cast<char>(c);
			}
		}
		else
		{
			outputFS << std::endl;
		}
	}
	return 0;
}
