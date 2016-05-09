/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 19:48:40 by aduban            #+#    #+#             */
/*   Updated: 2015/06/28 15:29:31 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_CLASS_HPP
# define SDL_CLASS_HPP

#include <SDL.h>
#include "IMonitorDisplay.hpp"
#include "SDL_ttf.h"
#include <iostream>
class SDL: public IMonitorDisplay
{
	public:
		SDL();
		~SDL();
		SDL_Window		*fenetre;
		SDL_Event		evenements;
		void		ft_init_sdl_color(int r, int g, int b);
			void		ft_init_sdl_rect(int w, int h, int x, int y);
			void    ft_write_on_screen(std::string str, int h, int x, int y, int color);
			void		ft_write_tty(const char* str);
			SDL_Renderer		*_renderer;
			void     putPixel(int x, int y, int col);
void		rect(int x, int y, int width, int height, int col);
			void	init();
	private:
			SDL(SDL const &);
			SDL & operator=(SDL const &);
			std::string			_name;
			SDL_Window			*_win;
			TTF_Font			*_font;
			SDL_Color 			color;
			SDL_Rect			pos;
			int					_h;
			int					_w;
			int					_y;
			int					_x;
			int					_r;
			int					_g;
			int					_b;
};

#endif
