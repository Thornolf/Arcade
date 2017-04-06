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
    void		startCore(Arcade::DLLoader<Graph::IGraph> &);
    void		movePlayer(std::map<int, std::map<int, int>>);
    void		setX(int);
    void		setY(int);
    void		setState(Game::State);
    void		setSpeed(size_t);
    void		setDirection(Game::Direction);
    void		setLive(bool);
    int			getX(void) const;
    int			getY(void) const;
    Game::State		getState(void) const;
    size_t		getSpeed(void) const;
    Game::Direction	getDirection(void) const;
    int			getType(void) const;
    bool		isAlive(void) const;
    void		Dump(void) const;
    int			getScore(void) const;
    void		setScore(int);
};

#endif		/* !_GAME_CORE__HPP_ */