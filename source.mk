##
## source.mk for cpp_arcade
##
## Made by Guillaume CAUCHOIS
## Login   <guillaume.cauchois@epitech.eu>
##
## Started on  Fri Mar 24 10:19:35 2017 Guillaume CAUCHOIS
## Last update Fri Mar 24 10:19:35 2017 Guillaume CAUCHOIS
##

#########################
##                     ##
##    ARACADE CORE     ##
##                     ##
#########################
SRC_ARCADE_DIR	=	./src/
SRC_ARCADE		=	$(SRC_ARCADE_DIR)main.cpp				\
					$(SRC_ARCADE_DIR)ArcadeException.cpp	\
					$(SRC_ARCADE_DIR)ArcadeCore.cpp
OBJ_ARCADE		=	$(SRC_ARCADE:.cpp=.o)

#########################
##                     ##
##  GRAPHIC LIBRARIES  ##
##                     ##
#########################
LIBRARY_DIR					=	./lib/
SRC_LIB_GRAPHIC_NCURSES_DIR	=	./lib/ncurses/
SRC_LIB_GRAPHIC_NCURSES		=	$(SRC_LIB_GRAPHIC_NCURSES_DIR)GraphicMenu.cpp			\
								$(SRC_LIB_GRAPHIC_NCURSES_DIR)PacmanDisplayerMap.cpp
OBJ_LIB_GRAPHIC_NCURSES		=	$(SRC_LIB_GRAPHIC_NCURSES:.cpp=.o)

SRC_LIB_GRAPHIC_SFML_DIR	=	./lib/sfml/
SRC_LIB_GRAPHIC_SFML		=	$(SRC_LIB_GRAPHIC_SFML_DIR)GraphicMenu.cpp				\
								$(SRC_LIB_GRAPHIC_NCURSES_DIR)PacmanDisplayerMap.cpp
OBJ_LIB_GRAPHIC_SFML		=	$(SRC_LIB_GRAPHIC_SFML:.cpp=.o)

#########################
##                     ##
##   GAME LIBRARIES    ##
##                     ##
#########################
GAME_DIR				=	./games/

SRC_LIB_GAME_SNAKE_DIR	=	./games/snake/
SRC_LIB_GAME_SNAKE		=	$(SRC_LIB_GAME_SNAKE_DIR)GameCore.cpp
OBJ_LIB_GAME_SNAKE		=	$(SRC_LIB_GAME_SNAKE:.cpp=.o)

SRC_LIB_GAME_PACMAN_DIR	=	./games/pacman/
SRC_LIB_GAME_PACMAN		=	$(SRC_LIB_GAME_PACMAN_DIR)GameCore.cpp		\
							$(SRC_LIB_GAME_PACMAN_DIR)MapGame.cpp		\
							$(SRC_LIB_GAME_PACMAN_DIR)ParserMap.cpp
OBJ_LIB_GAME_PACMAN		=	$(SRC_LIB_GAME_PACMAN:.cpp=.o)
