/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.con                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:50:11 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/28 15:00:41 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	Contact con;
	PhoneBook P;
	std::string input = "";
	int	i = 0;

	std::cout << "<Welcome to jin's history book.> \n<Please enter a command (ADD,EXIT,SEARCH)>" << std::endl;
	while(input != "EXIT")
	{
		input = con.input_info(input, 0);
		if (input == "")
		{
			std::cout << "\n--An error is detected, and it exits.--\n";
			return 0;
		}
		else if(input == "ADD")
		{
			if(i >= 8)
			{
				std::cout << "<Capacity is full.>\n<Oldest information will be overwritten first.>\n";
				i = 0;
			}
			if(i < 8)
				P = P.ft_add(i, P);
			i++;
		}
		else if(input == "SEARCH")
			P.search(P);
		else if(input.empty())
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if(input == "EXIT" )
			break;
		else
			std::cout << "<error try agin (ADD,EXIT,SEARCH)>\n";
	}
	std::cout << "<Thank you for your support. The program will exit.>" << std::endl;
	return(0);
}
