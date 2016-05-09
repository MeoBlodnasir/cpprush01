#include "Frame.hpp"
#include <string>
#include <sstream>


// Private
	// Constructors
Frame::Frame() {
	return;
}
Frame::Frame(Frame const &model) {
	*this = model;
}

	// Operators
Frame&	Frame::operator=(Frame const &copy) {
	(void)copy;
	return *this;
}



// Public
	// Constructors
Frame::Frame(Screen const & src) {
//	char	border = '|';
	
	_height = src.getHeight();
	_width = src.getWidth();
	_leftlimit = _width * 1 / 4;
	_rightlimit = _width * 3 / 4;
	_downlimit = _height;
/*
	for (int i = 0; i <= _height; i++) {
		mvaddch(i, _leftlimit, border);
		mvaddch(i, _rightlimit, border);
	}*/
}

/*void	Frame::drawBorders(void)const
{
	char border = '|';
	for (int i = 0; i <= _height; i++) {
		mvaddch(i, _leftlimit, border);
		mvaddch(i, _rightlimit, border);
	}
}
*/
	// Destructors
Frame::~Frame() {
	return;
}

	// Functions
	/*
void			Frame::add_character(IGameEntity & src) {
	for (int i = 0; i < src.getSizeY(); ++i) {
		for (int j = 0; j < src.getSizeX(); ++j) {
			mvaddch(src.getY() + i, src.getX() + j, src.getRep());
		}
	}
}

void			Frame::delete_character(IGameEntity & src) {
	for (int i = 0; i < src.getSizeY(); ++i) {
		for (int j = 0; j < src.getSizeX(); ++j) {
			mvaddch(src.getY() + i, src.getX() + j, ' ');
		}
	}
}*/

int				Frame::getHeight(void) const {
	return _height;
}

int				Frame::getWidth(void) const {
	return _width;
}

int				Frame::getminX(void) const {
	return _leftlimit;
}

int				Frame::getmaxX(void) const {
	return _rightlimit;
}

int				Frame::getmaxY(void) const {
	return _downlimit;
}

int				Frame::getminY(void) const {
	return 0;
}






