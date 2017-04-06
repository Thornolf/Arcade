/*
** SnakePart.hpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/inc/SnakePart.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 11:54:02 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 11:54:02 2017 Guillaume CAUCHOIS
*/

#ifndef		_SNAKE_PART__HPP_
# define	_SNAKE_PART__HPP_

# include "IGame.hpp"

class	SnakePart : public Game::IGame
{
  public:
    /* Canonical functions */
    SnakePart();
    SnakePart(int, int);
    SnakePart(const SnakePart &);
    virtual	~SnakePart();
    SnakePart	&operator=(const SnakePart &);

    /* Inherit from Game::IGame */
    void		startCore(Arcade::DLLoader<Graph::IGraph> &);
    void		movePlayer(std::map<int, std::map<int, int>>);
    void		setState(Game::State);
    void		setSpeed(size_t);
    void		setDirection(Game::Direction);
    void		setLive(bool);
    Game::State		getState(void) const;
    size_t		getSpeed(void) const;
    Game::Direction	getDirection(void) const;
    int			getType(void) const;
    bool		isAlive(void) const;
    void		Dump(void) const;
    int			getScore(void) const;
    void		setScore(int);

    /* Members functions */
    void	setX(int);
    void	setY(int);
    int		getX() const;
    int		getY() const;

  private:
    int		x;
    int		y;
};

#endif		/* !_SNAKE_PART__HPP_ */