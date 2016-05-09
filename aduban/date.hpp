/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:29:59 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:40:10 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
class Date: public IMonitorModule
{
	private:
		std::string t;
		Date & operator=(Date const &);
	public:
		Date();
		std::string	getName();
		Date(Date const &);
		~Date();
		void	setTime();
		std::string getTime();
};

#endif
