/*
** Pacman.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Thu Apr 06 15:49:38 2017 Quentin Baudet
** Last update Thu Apr 06 22:23:21 2017 Quentin Baudet
*/

#ifndef PACMAN_HPP
# define PACMAN_HPP

#include "APCharacter.hpp"

class Pacman : public APCharacter
{
	private:
		int		_score;

	public:
		Pacman ();
		/* Name | ID | HP (Dead or Alvie) | State (Eatable or Eater) | DIrection | PosX | PosY | Score */
		Pacman (std::string, int, APCharacter::Hp, Game::State, Game::Direction, int, int, int);
		virtual ~Pacman ();
};

#endif	/* !PACMAN_HPP */
