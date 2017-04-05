/*
** SnakeGame.hpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/inc/SnakeGame.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 12:02:27 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 12:02:27 2017 Guillaume CAUCHOIS
*/

#ifndef		_SNAKE_GAME__HPP_
# define	_SNAKE_GAME__HPP_

class SnakeGame
{
  public:
    /* Canonical Functions */
    SnakeGame();
    virtual ~SnakeGame();
    SnakeGame(const SnakeGame &);
    SnakeGame	&operator=(const SnakeGame &);

    /**
     * Member functions
     */
    /* SETTERS */
    void	setDel(int);
    void	setWidth(int);
    void	setHeight(int);
    void	setPoints(int);
    void	setPartChar(char);
    void	setOldalChar(char);
    void	setFoodChar(char);

    /* GETTERS */
    int		getDel(void) const;
    int		getWidth(void) const;
    int		getHeight(void) const;
    int		getPoints(void) const;
    char	getPartChar(void) const;
    char	getOldalChar(void) const;
    char	getFoodChar(void) const;

  private:
    int		del;
    int		points;
    int		maxWidth;
    int		maxHeight;
    char	partChar;
    char	oldalChar;
    char	foodChar;
};

#endif		/* !_SNAKE_GAME_HPP_ */