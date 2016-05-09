
#include "osinfos.hpp"
#include <sys/utsname.h>
#include <iostream>
#include <string>



std::string	OSinfos::getName()
{
	return _name;
}


OSinfos::OSinfos()
{
	_name = "OS infos";
	_height = 10;
	OSinfos::setInfos();
	return ;
}

OSinfos::~OSinfos()
{
	return ;
}

void	OSinfos::setInfos()
{
	struct utsname k;
	uname(&k);
	tab[0] = "Sysname: " + static_cast<std::string>(k.sysname);
	tab[1] = k.nodename;
	tab[2]  = "Release: " + static_cast<std::string>(k.release);
	tab[3]  = "Version: " + static_cast<std::string>(k.version);
	if (tab[3].length() > 38)
	{
		std::string str = "\n";
		tab[3].insert(38, str);
		maxsize = tab[3].length() - 38 + 1;
	}
	tab[4]  =  "Machine: " + static_cast<std::string>(k.machine);
	return ;
}

std::string	OSinfos::getSysname()
{
	return tab[0];
}

std::string	OSinfos::getNodename()
{
	return tab[1];
}

std::string	OSinfos::getRelease()
{
	return tab[2];
}

std::string	OSinfos::getVersion()
{
	return tab[3];
}

std::string	OSinfos::getMachine()
{
	return tab[4];
}

