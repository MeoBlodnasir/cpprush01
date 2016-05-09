/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:34:49 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:40:36 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "date.hpp"
#include <iostream>
Date::Date()
{
	_name = "Date and time:";
	_height = 2;
}


std::string	Date::getName()
{
	return _name;
}

Date::~Date()
{
	return;
}

void	Date::setTime()
{
	time_t						currentTime = time(NULL);

	t = ctime(&currentTime);
}

std::string Date::getTime()
{
	Date::setTime();
	return t.substr(0, t.size() - 1);
}

Date::Date(Date const &src)
{
	*this = src;
	return ;
}

Date & Date::operator=(Date const & rhs)
{
	(void)rhs;
	return *this;
}

