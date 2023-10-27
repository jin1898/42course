/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:04:32 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/27 18:45:15 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string scrat;
	
	public:
	std::string input_info(std::string output, int i);
};

#endif



