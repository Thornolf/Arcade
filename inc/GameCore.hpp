/*
** GameCore.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:30:28 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 18:30:28 2017 Guillaume CAUCHOIS
*/

#ifndef		_GAME_CORE__HPP_
# define	_GAME_CORE__HPP_

# include <ncurses.h>
# include "IGame.hpp"
# include "IGraph.hpp"
# include "ArcadeException.hpp"
# include "ArcadeCore.hpp"

class GameCore : public Game::IGame
{
  public:
    /* Canonical Methods */
    GameCore();
    virtual ~GameCore();
    GameCore(const GameCore &);
    GameCore	&operator=(const GameCore &);

    /* Pures Methods from IGames */
    virtual void	startCore(Arcade::DLLoader<Graph::IGraph> &);
    void	movePlayer();
    void	setX(int pos);
    void	setY(int pos);
    void	setState(Game::State state);
    void	setSpeed(size_t speed);
    int		getX() const;
    int		getY() const;
    Game::State	getState() const;
    size_t	getSpeed() const;
    bool	isAlive() const;
    void	Dump(void) const;
};

#endif		/* !_GAME_CORE__HPP_ */