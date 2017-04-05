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

class	SnakePart
{
  public:
    /* Canonical functions */
    SnakePart();
    SnakePart(int, int);
    SnakePart(const SnakePart &);
    virtual	~SnakePart();
    SnakePart	&operator=(const SnakePart &);

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