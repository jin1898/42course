/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:55:19 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/28 17:46:29 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::ft_add(int i, PhoneBook P)
{
	std::cout << "인덱스 : " << i  << std::endl;
	Contact a;
	Contact NewP(a.input_info("first_name: ", 1), a.input_info("last_name: ", 1), a.input_info("nickname: ",1)
	, a.input_info("phone: ",1), a.input_info("scrat: ",1));

	P.contact[i] = NewP;
}
void PhoneBook::search()
{
	if(P.contact[0].empty)
		std::cout << "Empty. Nothing to print." << std::endl;

	current_repository_display();



}
