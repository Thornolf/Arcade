/*
** APCharacter.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed Apr 05 18:55:13 2017 Quentin Baudet
** Last update Thu Apr 06 22:19:53 2017 Quentin Baudet
*/

#ifndef		APCHARACTER_HPP
# define	APCHARACTER_HPP

# include <iostream>
# include <functional>
# include "IGame.hpp"

enum Score {
 	PACGUM = 10,
	GHOST = 200,
};

enum BlockType { /* !! */
  VOID = -1,
  BLOCK = 0,
  WAY = 1,
  TEL_LEFT = 2,
  TEL_RIGHT = 3
};

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
    std::string			_name;
    int				_id;
    int 			_X;
    int 			_Y;
	int 			_score;

public:
	APCharacter ();
	/* Name | ID | HP (Dead or Alvie) | State (Eatable or Eater) | DIrection | PosX | PosY */
	APCharacter (std::string, int, APCharacter::Hp, Game::State, Game::Direction, int, int);
	APCharacter (std::string, int, int, int);
	virtual ~APCharacter ();

    void			startCore(Arcade::DLLoader<Graph::IGraph> &lib);

    /* MOVING PLAYER */
    void	movePlayer(int **map, Game::Direction);
    void	movePlayerUp(int **);
    void	movePlayerRight(int **);
    void	movePlayerLeft(int **);
    void	movePlayerDown(int **);
    bool 	isWalkable(int) const;

    /* SETTER */
    void	setX(int);
    void	setY(int);
    void	setState(Game::State);
    void	setSpeed(size_t);
    void	setDirection(Game::Direction);
    void	setLive(bool);

    /* GETTER */
    int			getX(void) const;
    int			getY(void) const;
    Game::State		getState(void) const;
    size_t		getSpeed(void) const;
    Game::Direction	getDirection(void) const;
    BlockType		getType(int) const;
	int 		getId(void) const;

    /* Unused member function from Game::IGame */
    void	movePlayer(std::map<int, std::map<int, int>>);
    int		getType(void) const;
    bool	isAlive(void) const;
    void	Dump(void) const;
    void	setScore(int);
	int		getScore(void) const;
	void 	increaseScore(int);

};

#endif		/* !APCHARACTER_HPP */
