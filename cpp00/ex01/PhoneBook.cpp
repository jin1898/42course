/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:19 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/11/04 11:08:12 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook PhoneBook::ft_add(int i, PhoneBook P)
{
	std::cout << "인덱스 : " << i  << std::endl;
	Contact a;
	Contact NewP(a.input_info("first_name: ", 1), a.input_info("last_name: ", 1), a.input_info("nickname: ",1)
	, a.input_info("phone: ",1), a.input_info("scrat: ",1));

	P.contact[i] = NewP;
	return (P);
}
static int check_number(std::string input, int max_index)
{
	if(input.size() != 1) // 길이가 1개이상이라는 뜻은 두자리 수이상이라는뜻! 하지만 주어진 인덱스는 7개 즉 한자리수여야한다!
		return(0);
	if(((input[0] - 48) >= 0) && ((input[0] - 48) <= max_index))
		return(1);
	return (0);
}

void PhoneBook::current_repository_display(PhoneBook P)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "      INDEX|" << "FIRST NAME|" << " LAST NAME|" << "  NICKNAME" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	int index = 0;
	while(index < 8)
	{
		if(P.contact[index].check_empty(P.contact[index]))
			break;
		std::cout << "|" << std::setw(10) << index << "|";
		P.contact[index].print_info(P.contact[index]);
		index++;
	}
	int max_index = index - 1;
	std::string input;
	while(1)
	{
		std::cout << "<Select the indexes you want to view.> ";
		getline(std::cin,input);
		input.erase(0,input.find_first_not_of("\t \v\f\r"));
		while(std::isspace(input[input.length() -1]))
			input.erase(input.find_last_not_of("\t \v\r\f") + 1, input[input.length() -1]);
		if(input.empty())
			continue;
		if(check_number(input, max_index))
			index = (int)input[0] - 48;
		else
		{
			std::cout << "Invalid number, please enter again." << std::endl;
			continue;
		}
		P.contact[index].individual_output(P.contact[index]);
		break;
	}

}
void PhoneBook::search(PhoneBook P)
{
	if(P.contact[0].check_empty(P.contact[0]))
	{
		std::cout << "Empty. Nothing to print." << std::endl;
		return ;
	}
	PhoneBook::current_repository_display(P);

}
