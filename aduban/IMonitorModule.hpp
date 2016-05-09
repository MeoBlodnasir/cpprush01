/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 13:45:42 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:35:19 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>

class IMonitorModule
{
	private:

		IMonitorModule(IMonitorModule const &);
		IMonitorModule & operator=(IMonitorModule const &);
	public:
		IMonitorModule();
		virtual ~IMonitorModule();
		virtual std::string getName() = 0;
		int getHeight();
		static int maxsize;
	protected:
		int _height;
		std::string _name;
};

#endif
