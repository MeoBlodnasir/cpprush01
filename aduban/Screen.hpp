#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>
#include <iostream>
#include <ncurses.h>
#include <sys/ioctl.h>
#include "IMonitorDisplay.hpp"

class Screen: public IMonitorDisplay{
private:
	int				_height;
	int				_width;
	struct winsize	_win;
	Screen(Screen const & src);
	Screen&	operator=(Screen const &);

public:
	Screen();
	virtual ~Screen();
	void			print_message(const char *message);
	void	init();
	int				getHeight(void) const ;
	int				getWidth(void) const ;
	struct winsize	getWin(void) const ;
	
};

std::ostream	&operator<<(std::ostream &o, Screen const &i);

#endif
