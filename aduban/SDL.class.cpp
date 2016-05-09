
#include "SDL.class.hpp"
#include <iostream>
SDL::SDL()
{
	init();
	return ;
}

SDL::~SDL()
{
	return ;
}

void	SDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		exit(0);
	}
	fenetre = SDL_CreateWindow("top", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (fenetre == 0)
		exit(0);
	if (TTF_Init() != 0){
		//	logSDLError(std::cout, "TTF_Init");
		SDL_Quit();
	}
	if ((this->_renderer = SDL_CreateRenderer(fenetre, -1, \
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC \
					)) == NULL)
	{
		//	ft_putstr_fd("SDL_Create_Renderer error ", 2);
		//		//	ft_putendl_fd(SDL_GetError(), 2);
		exit(-1);
	}
	if ((this->_font = TTF_OpenFont("Aller_Rg.ttf", 65)) == NULL)
	{
		//	ft_putstr_fd("TTF_OpenFont error ", 2);
		//		//	ft_putendl_fd(TTF_GetError(), 2);
		exit(-1);
	}
}

void            SDL::putPixel(int x, int y, int col) {

	SDL_SetRenderDrawColor(this->_renderer, (col&0xFF0000)>>16, (col&0x00FF00)>>8, (col&0x0000FF),255);
	SDL_RenderDrawPoint(this->_renderer, x, y);
}



void		SDL::rect(int x, int y, int width, int height, int col)
{/*
	int tmp = y;
	int tmp2 = x;
	while (x < tmp2 + width)
	{
		y = tmp;
		while (y < tmp + height)
		{
			SDL::putPixel(x, y, col);
			y++;
		}
		x++;
	}*/
	(void)col;
	SDL_Rect 	rect = {x, y, width, height};
//	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);

	SDL_SetRenderDrawColor(this->_renderer, (col&0xFF0000)>>16, (col&0x00FF00)>>8, (col&0x0000FF),255);
			SDL_RenderFillRect(_renderer, &rect);

}

void		SDL::ft_write_tty(const char* str)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = NULL;
	texture = NULL;
	if ((surface = TTF_RenderText_Blended(this->_font, str, this->color)) == NULL)
	{
		exit(-1);
	}
	if ((texture = SDL_CreateTextureFromSurface(this->_renderer, surface)) == 0)
	{
		exit(-1);
	}
	SDL_FreeSurface(surface);
	if (SDL_RenderCopy(this->_renderer, texture, NULL, &this->pos) < 0)
	{
		exit(-1);

	}
	SDL_DestroyTexture(texture);
}

void    SDL::ft_write_on_screen(std::string str, int h, int x, int y, int color)
{

	ft_init_sdl_rect(str.length() * ((h + h) / 5), h, x, y);
	ft_init_sdl_color(color & 0xFF, (color >> 8) & 0xFF, (color >> 16) & 0xFF);
	ft_write_tty(str.c_str());
}

void		SDL::ft_init_sdl_rect(int w, int h, int x, int y)
{
	this->pos.h = h;
	this->pos.w = w;
	this->pos.x = x;
	this->pos.y = y;
}

void		SDL::ft_init_sdl_color(int r, int g, int b)
{
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;	
}
