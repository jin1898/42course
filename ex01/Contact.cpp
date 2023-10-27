/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:36:02 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/27 18:17:06 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::input_info(std::string output, int i)
{
	std::string input;

	if(i > 0)
		std::cout << output << std::endl;
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