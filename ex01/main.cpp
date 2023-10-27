/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:50:11 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/27 18:25:01 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	Contact C;
	PhoneBook P;
	std::string input = "";
	int	i = 0;

	std::cout << "<Welcome to jin's history book.> \n<Please enter a command (ADD,EXIT,SEARCH)>" << std::endl;
	while(input != "EXIT")
	{
		input = C.input_info(input, 0);
		if(input == "ADD")
		{
			if(i > 7)
			{
				std::cout << "<Capacity is full.>\n<Oldest information will be overwritten first.>\n";
				i = 0;
			}
			if(i < 7)
				P.add(i);
		}
		else if(input == "SEARCH")
			std::cout << "SEARCH scces" << std::endl;
			// SEARCH();
		else if(input.empty())
			continue;
		else
			std::cout << "<error try agin (ADD,EXIT,SEARCH)>\n";
	}
	std::cout << "<Thank you for your support. The program will exit.>" << std::endl;
	return(0);
}