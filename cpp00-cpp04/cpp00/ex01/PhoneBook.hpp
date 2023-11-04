/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:07 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/11/03 15:15:47 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		PhoneBook ft_add(int i, PhoneBook P);
		void search(PhoneBook P);
		void current_repository_display(PhoneBook P);
};

#endif
