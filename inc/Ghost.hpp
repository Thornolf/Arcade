/*
** Ghost.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Thu Apr 06 15:49:32 2017 Quentin Baudet
** Last update Thu Apr 06 16:08:41 2017 Quentin Baudet
*/

#ifndef GHOST_HPP
#define GHOST_HPP

#include "APCharacter.hpp"

class Ghost : public APCharacter {
private:

public:
	Ghost ();
	/* Name | ID | HP (Dead or Alvie) | State (Eatable or Eater) | DIrection | PosX | PosY */
	Ghost (std::string, int, APCharacter::Hp, Game::State, Game::Direction, int, int);
	virtual ~Ghost ();
};
#endif	/* !GHOST_HPP */
