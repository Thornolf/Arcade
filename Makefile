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

ARCADE		=	arcade

CC			=	g++

RM			=	@rm -vf

CFLAGS		=	-W -Wall -Wextra -Werror -I./inc/

CXXFLAGS	=	-W -Wall -Wextra -Werror -I./inc/

DEBUG		?=	no

all:			$(ARCADE)

$(ARCADE):		$(OBJ_ARCADE)
				$(CC) $(OBJ_ARCADE) -o $(ARCADE)

clean:
				$(RM) $(OBJ_ARCADE)

fclean:			clean
				$(RM) $(ARCADE)

re:				fclean all