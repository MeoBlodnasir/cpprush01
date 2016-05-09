/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   osinfos.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:14:45 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:42:08 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOS_HPP
# define OSINFOS_HPP

#include "IMonitorModule.hpp"
#include <iostream>

class OSinfos: public IMonitorModule
{
	private:

		OSinfos(OSinfos const &);
		OSinfos & operator = (OSinfos const &);
	public:
		std::string tab[5];
		std::string	getName();
		OSinfos();
		~OSinfos();
		void	setInfos();
		std::string	getSysname();
		std::string	getNodename();
		std::string	getRelease();
		std::string	getVersion();
		std::string	getMachine();


};

#endif
