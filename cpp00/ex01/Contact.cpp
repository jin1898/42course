/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:36:02 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/28 15:56:26 by jsunwoo          ###   ########.fr       */
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
