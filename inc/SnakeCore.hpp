/*
** SnakeCore.hpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/inc/SnakeCore.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 11:02:48 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 11:02:48 2017 Guillaume CAUCHOIS
*/

#ifndef		_SNAKE_CORE__HPP_
# define	_SNAKE_CORE__HPP_

# include <unistd.h>
# include <vector>
# include "SnakePart.hpp"
# include "SnakeGame.hpp"
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

    /* Snake Event */
    void	putfood(void);
    bool	collision(void);
    void	movesnake(void);

  private:
    bool			get;
    char			direction;
    SnakePart			food;
    SnakeGame			*game;
    std::vector<SnakePart>	snake;
};

#endif		/* !_SNAKE_CORE_HPP_ */