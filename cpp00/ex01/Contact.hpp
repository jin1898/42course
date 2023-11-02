/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:04:32 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/11/02 22:15:12 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone;
	std::string m_scrat;

	public:
	std::string input_info(std::string output, int i);
	int	check_empty(Contact contact);
	Contact(std::string f_n, std::string l_n, std::string nn, std::string phone, std::string scrate);
	Contact();
	void print_info(Contact contact);
	void individual_output(Contact contact);

};

#endif
