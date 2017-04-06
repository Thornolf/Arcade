/*
** Ghost.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Thu Apr 06 15:49:36 2017 Quentin Baudet
** Last update Thu Apr 06 20:38:37 2017 Quentin Baudet
*/

#include "Ghost.hpp"

Ghost::Ghost() : APCharacter() {
}

Ghost::Ghost(	std::string newName,
			  	int newId,
			  	APCharacter::Hp newHp,
			  	Game::State newState,
			  	Game::Direction newDirection,
			  	int newX,
			  	int newY) :
				APCharacter(newName,
							newId,
							newHp,
							newState,
							newDirection,
							newX,
							newY) {
}

Ghost::Ghost (	std::string newName,
				  			int newId,
				  			int newX,
				  			int newY) : APCharacter (
  newName,
  newId,
  APCharacter::ALIVE,
  Game::INVUNERABLE,
  Game::UP,
  newX,
  newY
)
{}

Ghost::~Ghost () {}
