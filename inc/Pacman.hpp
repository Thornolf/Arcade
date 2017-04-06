/*
** Pacman.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Thu Apr 06 15:49:38 2017 Quentin Baudet
** Last update Thu Apr 06 18:01:19 2017 Quentin Baudet
*/

#ifndef PACMAN_HPP
# define PACMAN_HPP

#include "APCharacter.hpp"

enum Score {
 	PACGUM = 10,
	GHOST = 200,
};

class Pacman : public APCharacter {
	private:
		int		_score;

	public:
		Pacman ();
		/* Name | ID | HP (Dead or Alvie) | State (Eatable or Eater) | DIrection | PosX | PosY | Score */
		Pacman (std::string, int, APCharacter::Hp, Game::State, Game::Direction, int, int, int);
		virtual ~Pacman ();
		void 	increaseScore(int);
		int 	getScore();
};

#endif	/* !PACMAN_HPP */
