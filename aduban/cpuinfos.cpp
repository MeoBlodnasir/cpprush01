/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpuinfos.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 16:13:36 by aduban            #+#    #+#             */
/*   Updated: 2015/06/28 16:00:18 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cpuinfos.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sstream>

	std::string	Cpuinfos::getName()
{
	return _name;
}

Cpuinfos::Cpuinfos()
{
	_name = "CPU Infos: ";
	Cpuinfos::getInfos();
	return;
}

Cpuinfos::~Cpuinfos()
{
	return;	
}

void	Cpuinfos::getInfos()
{

	long			data;
	size_t			len;
	char			str[1048];

	len = 1048;

	sysctlbyname("machdep.cpu.brand_string", str, &len, NULL, 0);
	this->_cpuName = str;
	len = sizeof(int);
	sysctlbyname("hw.ncpu", &(this->_ncpu), &len, NULL, 0);
	len = sizeof(long);
	sysctlbyname("hw.busfrequency", &(this->_busFrequency), &len, NULL, 0);
//	std::cout << _busFrequency << std::endl;
	len = sizeof(long);
	sysctlbyname("hw.cpufrequency", &data, &len, NULL, 0);
	this->_cpuFrequency = static_cast<double>(static_cast<double>(data) / static_cast<double>(this->_busFrequency) / 10.0);
			}

