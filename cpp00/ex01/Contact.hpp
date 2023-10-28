/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:04:32 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/28 15:55:19 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>

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
	Contact(std::string f_n, std::string l_n, std::string nn, std::string phone, std::string scrate);
	Contact();

};

#endif
