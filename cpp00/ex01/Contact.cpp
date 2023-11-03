/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:36:02 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/11/03 15:49:40 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::input_info(std::string output, int i)
{
	std::string input;

	if(i > 0)
		std::cout << output;
	while(1)
	{
		std::getline(std::cin, input);
		input.erase(0,input.find_first_not_of("\t\v\r\f"));
		while(isspace(input[input.length()-1]))
			input.erase(input.find_last_not_of("\t\r\v\f"));
		if(input.empty())
			std::cout << "empty! please try again" << std::endl;
		else
			break;
	}
	return(input);
}
Contact::Contact(std::string f_n, std::string l_n, std::string nn, std::string phone, std::string scrate)
{
	m_first_name = f_n;
	m_last_name = l_n;
	m_nickname = nn;
	m_phone = phone;
	m_scrat = scrate;
}
Contact::Contact()
{
};

int	Contact::check_empty(Contact contact)
{
	if(contact.m_first_name.empty())
		return(1);
	return(0);
}
void Contact::print_info(Contact contact)
{
	if(contact.m_first_name.size() > 10)
		std::cout << std::string(contact.m_first_name.begin(), contact.m_first_name.begin()+9) << '.' << "|";
	else
		std::cout << std::setw(10) << contact.m_first_name << "|";

	if(contact.m_last_name.size() > 10)
		std::cout << std::string(contact.m_last_name.begin(), contact.m_last_name.begin() + 9) << '.' << "|";
	else
		std::cout << std::setw(10) << contact.m_last_name << "|";
	if(contact.m_nickname.size() > 10)
		std::cout << std::string(contact.m_nickname.begin(), contact.m_nickname.begin() + 9) << '.' << "|";
	else
		std::cout << std::setw(10) << contact.m_nickname << "|";
	std::cout << std::endl << "|-------------------------------------------|" << std::endl;
}
void Contact::individual_output(Contact contact)
{
	std::cout << "First name: " << contact.m_first_name << std::endl;
	std::cout << "Last name: " << contact.m_last_name << std::endl;
	std::cout << "Nickname: " << contact.m_nickname << std::endl;
	std::cout << "Phone number: " << contact.m_phone << std::endl;
	std::cout << "Darkest secret: " << contact.m_scrat << std::endl;
}
