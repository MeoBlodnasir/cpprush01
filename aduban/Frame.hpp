#ifndef FRAME_HPP
#define FRAME_HPP


class Player;

#include "Screen.hpp"


class Frame {
private:
	int				_height;
	int				_width;
	int				_leftlimit;
	int				_rightlimit;
	int				_downlimit;
	int				_score;
	Frame(void);
	Frame(Frame const & src);
	Frame&	operator=(Frame const &);

public:
	Frame(Screen const &);
	~Frame();


	int		getHeight(void) const ;
	int		getWidth(void) const ;
	int		getmaxY(void) const ;
	int		getmaxX(void) const ;
	int		getminX(void) const ;
	int		getminY(void) const ;
	void	drawBorders(void) const ;

};

std::ostream	&operator<<(std::ostream &o, Frame const &i);

#endif
