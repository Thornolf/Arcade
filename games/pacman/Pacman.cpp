/*
** Pacman.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Thu Apr 06 15:49:40 2017 Quentin Baudet
** Last update Thu Apr 06 17:41:11 2017 Quentin Baudet
*/

#include "Pacman.hpp"

Pacman::Pacman() : APCharacter() {}

Pacman::Pacman(	std::string newName,
			  	int newId,
			  	APCharacter::Hp newHp,
			  	Game::State newState,
			  	Game::Direction newDirection,
			  	int newX,
			  	int newY,
				int newScore) :
				APCharacter(newName,
							newId,
							newHp,
							newState,
							newDirection,
							newX,
							newY) {
	this->_score = newScore;
}

void 	Pacman::increaseScore(int newScore) {
	this->_score += newScore;
}

int 	Pacman::getScore(void) {
	return (this->_score);
}
Pacman::~Pacman() {}
