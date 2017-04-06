/*
** Ghost.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Thu Apr 06 15:49:36 2017 Quentin Baudet
** Last update Thu Apr 06 15:59:03 2017 Quentin Baudet
*/

#ifndef GHOST_HPP
#define GHOST_HPP

#include "Ghost.hpp"
#include "APCharacter.hpp"

class Ghost : public APCharacter {
private:
	/* data */

public:
	Ghost ();
	virtual ~Ghost ();
};

#endif
