/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:07 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/10/28 17:38:25 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		void ft_add(int i, PhoneBook P);
		void search();
};

#endif
