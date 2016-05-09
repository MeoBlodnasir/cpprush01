NAME = ft_gkrellm

SRC = Frame.cpp \
	Hostname.cpp \
	IMonitorDisplay.cpp \
	IMonitorModule.cpp \
	SDL.class.cpp \
	Screen.cpp \
	cpuinfos.cpp \
	date.cpp \
	network.cpp \
	osinfos.cpp \
	ram.cpp \
	main.cpp

SRCO = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	@clang++ -Wall -Wextra -Werror -c $(SRC) -I -lncurses -I ~/Library/Frameworks/SDL2.framework/Headers -I ~/Library/Frameworks/SDL2_ttf.framework/Headers
	@clang++  -lncurses  -F ~/Library/Frameworks/ -framework SDL2 -framework SDL2_ttf -o  $(NAME) $(SRCO)

clean:
	@/bin/rm -f $(SRCO)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
