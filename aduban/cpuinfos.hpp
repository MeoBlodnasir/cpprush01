/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpuinfos.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:10:05 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 19:39:01 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUINFOS_HPP
# define CPUINFOS_HPP

#include "IMonitorModule.hpp"
class Cpuinfos: public IMonitorModule
{
	private:
		Cpuinfos(Cpuinfos const &);
		Cpuinfos & operator=(Cpuinfos const &);
	public:
		Cpuinfos();
		~Cpuinfos();
		std::string	getName();
		std::string					_cpuName;
		int							_ncpu;
		int							_busFrequency;
		double						_cpuFrequency;
		void	getInfos();
	protected:
};

#endif
