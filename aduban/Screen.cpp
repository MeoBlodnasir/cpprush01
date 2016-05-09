#include "Screen.hpp"

// Private
	// Constructors
Screen::Screen(Screen const &model) {
	*this = model;
}

	// Operators
Screen&	Screen::operator=(Screen const &copy) {
	(void)copy;
	return *this;
}


Screen::Screen()
{
	init();
	return;
}
// Public
	// Constructors
void	Screen::init() {
	initscr();
	clear();
	noecho();
	cbreak();
//	timeout(0);
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	ioctl(0, TIOCGWINSZ, &_win);
	_height = _win.ws_row;
	_width = _win.ws_col;
}

	// Destructors
Screen::~Screen() {
	endwin();
}

	// Functions
void			Screen::print_message(const char *message) {
	printw(message);
}

int				Screen::getHeight(void) const {
	return _height;
}

int				Screen::getWidth(void) const {
	return _width;
}

struct winsize	Screen::getWin(void) const {
	return _win;
}





std::ostream	&operator<<(std::ostream &o, Screen const &i)
{
	o << "Height : " << i.getHeight() << " ; Width : " << i.getWidth() << std::endl;
	return o;
}
