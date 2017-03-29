##
## Makefile for cpp_arcade
##
## Made by Guillaume CAUCHOIS
## Login   <guillaume.cauchois@epitech.eu>
##
## Started on  Fri Mar 24 10:12:03 2017 Guillaume CAUCHOIS
## Last update Fri Mar 24 10:12:03 2017 Guillaume CAUCHOIS
##

include source.mk

ARCADE				=	arcade

LIB_GRAPHIC_NCURSES	=	lib_arcade_ncurses.so

LIB_GRAPHIC_SFML	=	lib_arcade_sfml.so

LIB_GAME_SNAKE		=	lib_arcade_snake.so

LIB_GAME_PACMAN		=	lib_arcade_pacman.so

CC					=	g++

RM					=	@rm -vf

CFLAGS				=	-W -Wall -Wextra -Werror -I./inc/ -fPIC

CXXFLAGS			=	-W -Wall -Wextra -Werror -I./inc/ -fPIC

LDFLAGS				=	-shared

DEBUG				?=	no

ifeq					($(DEBUG), yes)
CFLAGS				=	-g -ggdb3
CXXFLAGS			+=	-g -ggdb3
endif

all:					$(LIB_GRAPHIC_NCURSES) $(LIB_GRAPHIC_SFML) $(LIB_GAME_SNAKE) $(LIB_GAME_PACMAN) $(ARCADE)

$(LIB_GRAPHIC_NCURSES):	$(OBJ_LIB_GRAPHIC_NCURSES)
						$(CC) ${LDFLAGS} -o $(LIBRARY_DIR)$(LIB_GRAPHIC_NCURSES) $(OBJ_LIB_GRAPHIC_NCURSES)

$(LIB_GRAPHIC_SFML):	$(OBJ_LIB_GRAPHIC_SFML)
						$(CC) ${LDFLAGS} -o $(LIBRARY_DIR)$(LIB_GRAPHIC_SFML) $(OBJ_LIB_GRAPHIC_SFML)

$(LIB_GAME_SNAKE):		$(OBJ_LIB_GAME_SNAKE)
						$(CC) ${LDFLAGS} -o $(GAME_DIR)$(LIB_GAME_SNAKE) $(OBJ_LIB_GAME_SNAKE)

$(LIB_GAME_PACMAN):		$(OBJ_LIB_GAME_PACMAN)
						$(CC) ${LDFLAGS} -o $(GAME_DIR)$(LIB_GAME_PACMAN) $(OBJ_LIB_GAME_PACMAN)


$(ARCADE):				$(OBJ_ARCADE)
						$(CC) $(OBJ_ARCADE) -o $(ARCADE)

clean:
						$(RM) $(OBJ_ARCADE)
						$(RM) $(OBJ_LIB_GRAPHIC_NCURSES)
						$(RM) $(OBJ_LIB_GRAPHIC_SFML)

fclean:					clean
						$(RM) $(ARCADE)
						$(RM) $(LIB_GRAPHIC_NCURSES)
						$(RM) $(LIB_GRAPHIC_SFML)

re:						fclean all