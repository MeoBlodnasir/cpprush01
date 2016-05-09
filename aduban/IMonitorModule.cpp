
#include "IMonitorModule.hpp"

int	IMonitorModule::maxsize = 0;

IMonitorModule::IMonitorModule(IMonitorModule const &)
{

}



IMonitorModule::IMonitorModule()
{
	return ;
}

IMonitorModule::~IMonitorModule()
{
	return ;
}

std::string IMonitorModule::getName()
{
	return _name;
}

int IMonitorModule::getHeight()
{
	return _height;
}

