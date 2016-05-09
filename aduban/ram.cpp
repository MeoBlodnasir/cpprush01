/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ram.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:22:37 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 20:04:48 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ram.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>


std::string	Ram::getName()
{
	return _name;
}

Ram::Ram()
{
	_name = "RAM:";
}

Ram::~Ram()
{
	return ;
}

void	Ram::setAll()
{
	int mib [] = { CTL_HW, HW_MEMSIZE };
	int64_t value = 0;
	size_t length = sizeof(value);

	if(-1 == sysctl(mib, 2, &value, &length, NULL, 0))
		std::cout << "ERROR" << std::endl;
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	if(KERN_SUCCESS != host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count))
		std::cout << "ERROR" << std::endl;
	total = vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count;
	//		std::cout <<total << std::endl;
	wired = vmstat.wire_count / total;
	active = vmstat.active_count / total;
	inactive = vmstat.inactive_count / total;
	free = vmstat.free_count / total;
}

