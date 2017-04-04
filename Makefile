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

CFLAGS				=	-fPIC -W -Wall -Wextra -Werror -I./inc/

CXXFLAGS			=	-fPIC -W -Wall -Wextra -Werror -I./inc/

LDFLAGS				=	-shared

DEBUG				?=	no

ifeq					($(DEBUG), yes)
CFLAGS				=	-g -ggdb3
CXXFLAGS			+=	-g -ggdb3
endif

all:					$(LIB_GRAPHIC_NCURSES) $(LIB_GRAPHIC_SFML) $(LIB_GAME_SNAKE) $(LIB_GAME_PACMAN) $(ARCADE)

#########################
##                     ##
##  GRAPHIC LIBRARIES  ##
##                     ##
#########################

$(LIB_GRAPHIC_NCURSES):	$(OBJ_LIB_GRAPHIC_NCURSES)
						$(CC) ${LDFLAGS} -o $(LIBRARY_DIR)$(LIB_GRAPHIC_NCURSES) $(OBJ_LIB_GRAPHIC_NCURSES) -lncurses -lmenu

$(LIB_GRAPHIC_SFML):	$(OBJ_LIB_GRAPHIC_SFML)
						$(CC) ${LDFLAGS} -o $(LIBRARY_DIR)$(LIB_GRAPHIC_SFML) $(OBJ_LIB_GRAPHIC_SFML) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#########################
##                     ##
##   GAME LIBRARIES    ##
##                     ##
#########################

$(LIB_GAME_SNAKE):		$(OBJ_LIB_GAME_SNAKE)
						$(CC) ${LDFLAGS} -o $(GAME_DIR)$(LIB_GAME_SNAKE) $(OBJ_LIB_GAME_SNAKE)

$(LIB_GAME_PACMAN):		$(OBJ_LIB_GAME_PACMAN)
						$(CC) ${LDFLAGS} -o $(GAME_DIR)$(LIB_GAME_PACMAN) $(OBJ_LIB_GAME_PACMAN)

#########################
##                     ##
##       ARCADE        ##
##                     ##
#########################

$(ARCADE):				$(OBJ_ARCADE)
						$(CC) $(OBJ_ARCADE) -o $(ARCADE) -ldl -rdynamic

clean:
						$(RM) $(OBJ_ARCADE)
						$(RM) $(OBJ_LIB_GRAPHIC_NCURSES)
						$(RM) $(OBJ_LIB_GRAPHIC_SFML)
						$(RM) $(OBJ_LIB_GAME_SNAKE)
						$(RM) $(OBJ_LIB_GAME_PACMAN)

fclean:					clean
						$(RM) $(ARCADE)
						$(RM) $(LIBRARY_DIR)$(LIB_GRAPHIC_NCURSES)
						$(RM) $(LIBRARY_DIR)$(LIB_GRAPHIC_SFML)
						$(RM) $(GAME_DIR)$(LIB_GAME_SNAKE)
						$(RM) $(GAME_DIR)$(LIB_GAME_PACMAN)

re:						fclean all