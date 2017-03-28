##
## source.mk for cpp_arcade
##
## Made by Guillaume CAUCHOIS
## Login   <guillaume.cauchois@epitech.eu>
##
## Started on  Fri Mar 24 10:19:35 2017 Guillaume CAUCHOIS
## Last update Fri Mar 24 10:19:35 2017 Guillaume CAUCHOIS
##

SRC_ARCADE_DIR		=	./src/

SRC_ARCADE			=	$(SRC_ARCADE_DIR)main.cpp				\
						$(SRC_ARCADE_DIR)ArcadeException.cpp	\
						$(SRC_ARCADE_DIR)ArcadeCore.cpp

OBJ_ARCADE			=	$(SRC_ARCADE:.cpp=.o)