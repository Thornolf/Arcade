/*
** SnakeCore.hpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/inc/SnakeCore.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 11:02:48 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 16:27:23 2017 Robin Grattepanche
*/

#ifndef		_SNAKE_CORE__HPP_
# define	_SNAKE_CORE__HPP_

# include <unistd.h>
# include <vector>
# include "SnakePart.hpp"
# include "SnakePart.hpp"
# include "SnakeGame.hpp"
# include "ncurses/SnakeGraph.hpp"
# include "sfml/SnakeGraph.hpp"
# include "GameCore.hpp"

class SnakeCore : public GameCore
{
  public:
    /* Canonical Functions */
    SnakeCore();
    virtual ~SnakeCore();
    SnakeCore(const SnakeCore &);
    SnakeCore        &operator=(const SnakeCore &);

    /* CoreGame */
    void	startCore(Arcade::DLLoader<Graph::IGraph> &);

    /* Getters */
    std::vector<Game::IGame*>	getSnakeBody(void) const;

    /* Snake Event */
    void	putFood(Graph::IGraph *);
    bool	collision(Graph::IGraph *);
    void	moveSnake(Graph::IGraph *);

  private:
    bool			get;
    char			direction;
    Game::IGame			*food;
    SnakeGame			*game;
    std::vector<Game::IGame *>	snake;
};

#endif		/* !_SNAKE_CORE_HPP_ */
