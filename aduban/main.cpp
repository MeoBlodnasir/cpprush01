
#include "Frame.hpp"
#include "Screen.hpp"
#include "Hostname.hpp"
#include "ram.hpp"
#include "cpuinfos.hpp"
#include "date.hpp"
#include "network.hpp"
#include "osinfos.hpp"
#include "SDL.class.hpp"
#include <unistd.h>
#include <ctime>
#include "inc.hpp"


void	drawline(Date date, int h)
{
	int i = 0;
	start_color();
	init_pair(2, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	while (i < date.maxsize)
	{
		mvprintw(h, i++, "*");
	}
	attroff(COLOR_PAIR(2));
}

void	drawborders(Date date, int length)
{
	int i = 0;
	start_color();
	init_pair(2, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	while (i <= date.maxsize)
	{
		mvprintw(0, i, "-");
		mvprintw(length, i++, "-");
	}
	i = 1;
	while (i < length)
	{
		mvprintw(i, 0, "|");
		mvprintw(i++, date.maxsize, "|");
	}
	attroff(COLOR_PAIR(2));
}

void	printhost(Hostname host, int *i)
{
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw((*i)++, 1, ((host.getName()).c_str()));
	attroff(COLOR_PAIR(1));
	mvprintw((*i)++, 1, ((host.getHost()).c_str()));
	mvprintw((*i)++, 1, "Username:");
	mvprintw((*i)++, 1, ((host.getUsername()).c_str()));
}





void	game_loop(Screen* scr, Frame* frame, std::string *conf) {
	(void)scr;
	(void)frame;
	OSinfos infos;
	Hostname host;
	Date date;
	Cpuinfos cpu;
	Ram ram;
	Network network;
	int i = 1;
	timeout(0);
	int j;
	(void)conf;
	int ch;
	// Exit
	//	if (ch == 27) return;
	start_color();
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	while (1)
	{
		ch = getch();
		if (ch == 27)
			break;
		i = 1;
		printhost(host, &i);
		drawline(date, i++);
		attron(COLOR_PAIR(1));
		mvprintw(i++, 1, ((date.getName()).c_str()));
		attroff(COLOR_PAIR(1));
		mvprintw(i++, 1, ((date.getTime()).c_str()));
		drawline(date, i++);
		attron(COLOR_PAIR(1));
		mvprintw(i++, 1, "OS Infos:");
		attroff(COLOR_PAIR(1));
		j = 0;
		while (j < 5)
		{
			if (j != 1)
				mvprintw(i++, 1, (infos.tab[j].c_str()));
			if (j == 3)
				i++;
			j++;
		}
		cpu.getInfos();
		drawline(date, i++);
		attron(COLOR_PAIR(1));
		mvprintw(i++, 1, (cpu.getName()).c_str());
		attroff(COLOR_PAIR(1));
		mvprintw(i++, 1, (cpu._cpuName).c_str());
		attroff(COLOR_PAIR(1));
		mvprintw(i++, 1, (std::to_string(cpu._ncpu)).c_str());
		mvprintw(i++, 1, (std::to_string(cpu._busFrequency)).c_str());
		mvprintw(i++, 1, (std::to_string(cpu._cpuFrequency)).c_str());
		ram.setAll();
		drawline(date, i++);
		attron(COLOR_PAIR(1));
		mvprintw(i++, 1, ((ram.getName()).c_str()));
		attroff(COLOR_PAIR(1));
		mvprintw(i++, 1, "Total:");
		mvprintw(i++, 1, (std::to_string(ram.total).c_str()));
		mvprintw(i++, 1, "Wired:");
		mvprintw(i++, 1, (std::to_string(ram.wired).c_str()));
		mvprintw(i++, 1, "Active:");
		mvprintw(i++, 1, (std::to_string(ram.active).c_str()));
		mvprintw(i++, 1, "Inactive:");
		mvprintw(i++, 1, (std::to_string(ram.inactive).c_str()));
		mvprintw(i++, 1, "Free:");
		mvprintw(i++, 1, (std::to_string(ram.free).c_str()));
		network.setAll();
		drawline(date, i++);
		attron(COLOR_PAIR(1));
		mvprintw(i++, 1, ((network.getName()).c_str()));
		attroff(COLOR_PAIR(1));
		mvprintw(i++, 1, "Total bytes in:");
		mvprintw(i++, 1, (std::to_string(network.totalibytes).c_str()));
		mvprintw(i++, 1, "Total bytes out:");
		mvprintw(i++, 1, (std::to_string(network.totalobytes).c_str()));
		mvprintw(i++, 1, "Ipv4 address:");
		mvprintw(i++, 1, ((network.ipv4).c_str()));
		mvprintw(i++, 1, "Ipv6 address:");
		mvprintw(i++, 1, network.ipv6.c_str());
		drawborders(date, i);
		refresh();
	}
}



void	sdl_loop(SDL *sdl)
{
	OSinfos infos;
	Hostname host;
	Date date;
	Cpuinfos cpu;
	Ram ram;
	ram.setAll();
	int ramv = (ram.total - 207000)/10000;
	int ram2 = 0;
	int fram = ram.free * 10000;
	int fram2 = 0;
	Network network;
	network.setAll();
	u_int64_t in = network.totalibytes;
	u_int64_t in2 = 0;
	u_int64_t out = network.totalobytes;
	u_int64_t out2 = 0;
	int i = 1;
	//	sdl->putPixel(1, 1, 0x0000FF);
	while (1)
	{
  SDL_SetRenderDrawColor(sdl->_renderer, 0, 0, 0, 255);
          SDL_RenderClear(sdl->_renderer);
		i = 0;
		if (SDL_PollEvent(&sdl->evenements))
		{
			if (sdl->evenements.type)
			{
				if (sdl->evenements.window.event == SDL_WINDOWEVENT_CLOSE)
					exit(-1);
				if (sdl->evenements.window.event == 1)
				{
					if (sdl->evenements.key.keysym.sym == SDLK_ESCAPE)
						exit(-1);
				}
			}
		}
		sdl->ft_write_on_screen(host.getName(), 20, 0, i, 0x00FF00);
		sdl->ft_write_on_screen(host.getHost(), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen("Username:", 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(host.getUsername(), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(date.getName(), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(date.getTime(), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen("OS infos: ", 20, 0, i += 20, 0x00FF00);
		int j = 0;
		while (j < 5)
		{
			if (j != 1)
				sdl->ft_write_on_screen(infos.tab[j], 20, 0, i += 20, 0x00FF00);
			if (j == 3)
				i++;
			j++;
		}
		cpu.getInfos();
		sdl->ft_write_on_screen(cpu.getName(), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(cpu._cpuName, 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(std::to_string(cpu._ncpu), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(std::to_string(cpu._busFrequency), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen(std::to_string(cpu._cpuFrequency), 20, 0, i += 20, 0x00FF00);
		sdl->ft_write_on_screen("Ram: ", 20, 0, i += 20, 0x00FF00);
		ram.setAll();
		sdl->ft_write_on_screen("Total: ", 20, 0, i += 20, 0x00FF00);
		ram2 = (((ram.total - 207000)/10000) - ramv) * 100 + 300;
		sdl->rect(0, i+=20, ram2, 30, 0x0000FF);
		ramv =  (ram.total - 207000)/10000;
		sdl->ft_write_on_screen("Free: ", 20, 0, i += 30, 0x00FF00);
		fram2 = (((ram.free * 10000) - fram)) * 10 + 100;
		sdl->rect(0, i+=20, fram2, 30, 0x0000FF);
		fram = ram.free * 10000;
		sdl->ft_write_on_screen("NETWORK: ", 20, 0, i += 30, 0x00FF00);
		sdl->ft_write_on_screen("IN: ", 20, 0, i += 20, 0x00FF00);
		network.setAll();
		in2 = (network.totalibytes - in);
		sdl->rect(0, i+=20, in2/10 + 50, 30, 0x0000FF);
		in = network.totalibytes;
		sdl->ft_write_on_screen("OUT: ", 20, 0, i += 30, 0x00FF00);
		out2 = (network.totalobytes - out);
		sdl->rect(0, i+=20, out2/10 + 50, 30, 0x0000FF);
		out = network.totalobytes;
		SDL_RenderPresent(sdl->_renderer);
		SDL_RenderClear(sdl->_renderer);
	}
}


std::string	*fillconf(std::string *conf, char **av, int ac)
{
	int i = 2;
	int j = 0;
	conf = new std::string[6];
	while (j < 6)
	{
		if (i < ac)
		{
			std::string str(av[i]);
			conf[j] = str;
		}
		else
			conf[j] = "none";
		i++;
		j++;
	}
	return conf;
}

int main(int ac, char **av) {

	if (ac == 2)
	{
		std::string *conf = NULL;
		conf = fillconf(conf, av, ac);
		std::string str(av[1]);
		if (str == "sdl")
		{
			SDL *sdl = new SDL();
			sdl_loop(sdl);
		}
		else if ( str == "ncurses")
		{
			Screen*	scr = new Screen();
			Frame*	frame = new Frame(*scr);
			game_loop(scr, frame, conf);
		delete scr;
		delete frame;
		}
		else
			std::cout << "Please select between ncurses and sdl !" << std::endl;
	}
	else
			std::cout << "Please select between ncurses and sdl !" << std::endl;


	return 0;
}



