/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:00:51 by aduban            #+#    #+#             */
/*   Updated: 2015/06/27 22:05:23 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Hostname.hpp"
#include <sys/utsname.h>
#include <pwd.h>
#include <unistd.h>

Hostname::Hostname()
{
	_name = "Host:";
	_height = 4;
	Hostname::setHostUser();
	return ;
}

Hostname::~Hostname()
{
	return ;
}

void Hostname::setHostUser(void)
{
	uid_t					uid = getuid();
	struct passwd			*passwd = getpwuid(uid);
	struct utsname			utsname;

	uname(&utsname);
	_hostname =  utsname.nodename;
	_username = passwd->pw_name;
}

std::string Hostname::getHost()
{
	return _hostname;
}

std::string Hostname::getUsername()
{
	return _username;
}

std::string Hostname::getName()
{
	return _name;
}


Hostname & Hostname::operator=(Hostname const & rhs)
{
	_hostname = rhs._hostname;
	_username = rhs._username;
	_name = rhs._name;
	return *this;
}

Hostname::Hostname(Hostname const & src)
{
	*this = src;
}
