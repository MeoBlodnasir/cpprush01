/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwok.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 17:51:09 by aduban            #+#    #+#             */
/*   Updated: 2015/06/28 17:57:12 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "network.hpp"
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <string.h> 
#include <arpa/inet.h>


std::string	Network::getName()
{
	return _name;
}

Network::Network()
{
	_name = "Network:";
	return;
}

Network::~Network()
{
	return;
}

void	Network::setAll()
{

	int mib[] = {
		CTL_NET,
		PF_ROUTE,
		0,
		0,
		NET_RT_IFLIST2,
		0
	};
	size_t len;
	if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
		exit(1);
	}
	char buf[len];// = (char *)malloc(len);
	if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
		exit(1);
	}
	char *lim = buf + len;
	char *next = NULL;
	totalibytes = 0;
	totalobytes = 0;
	for (next = buf; next < lim; ) {
		struct if_msghdr *ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
			totalibytes += if2m->ifm_data.ifi_ibytes;
			totalobytes += if2m->ifm_data.ifi_obytes;
		}
	}
	struct ifaddrs * ifAddrStruct=NULL;
	struct ifaddrs * ifa=NULL;
	void * tmpAddrPtr=NULL;

	getifaddrs(&ifAddrStruct);

	for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr->sa_family == AF_INET) {
			tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
			char addressBuffer[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
			ipv4 = addressBuffer;
		//	std::cout << ipv4 << std::endl;
		} else if (ifa->ifa_addr->sa_family == AF_INET6) {
			tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
			char addressBuffer[INET6_ADDRSTRLEN];
			inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
			ipv6 = addressBuffer;
		}
	}
}

