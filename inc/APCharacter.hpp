/*
** APCharacter.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed Apr 05 18:55:13 2017 Quentin Baudet
** Last update Thu Apr 06 11:45:35 2017 Quentin Baudet
*/

#ifndef APCHARACTER_HPP
# define APCHARACTER_HPP

# include <iostream>
# include <functional>
#include "MapGame.hpp"
# include "IGame.hpp"

class APCharacter : public Game::IGame {
public:

enum Hp {
	DEAD = -1,
	ALIVE = 0
};

/* Vulnerable = Se faire manger | Invulnerable = Manger */

private:
	Game::Direction		_direction;
	Game::State 		_state;
	APCharacter::Hp		_hp;
	std::string		_name;
	int			_id;
	int 			_X;
	int 			_Y;

public:
	APCharacter ();
	/* Name | ID | HP (Dead or Alvie) | State (Eatable or Eater) | DIrection | PosX | PosY */
	APCharacter (std::string, int, APCharacter::Hp, Game::State, Game::Direction, int, int);
	virtual ~APCharacter ();

	void			startCore(Arcade::DLLoader<Graph::IGraph> &lib);

	/* MOVING PLAYER */
	void			movePlayer(int **map, Game::Direction);
	void			movePlayerUp(int **);
	void			movePlayerRight(int **);
	void			movePlayerLeft(int **);
	void			movePlayerDown(int **);
	bool 			isWalkable(int) const;

	/* SETTER */
	void			setX(int);
	void			setY(int);
	void			setState(Game::State);
	void			setSpeed(size_t);
	void			setDirection(Game::Direction);
	void			setLive(bool);

	/* GETTER */
	int			getX(void) const;
	int			getY(void) const;
	Game::State		getState(void) const;
	size_t			getSpeed(void) const;
	Game::Direction		getDirection(void) const;
	BlockType		getType(int) const;

	/* fossae_t */
	void		movePlayer(std::map<int, std::map<int, int>>);
	int			getType(void) const;
	bool		isAlive(void) const;
	void		Dump(void) const;
	int			getScore(void) const;
	void		setScore(int);
};

#endif
