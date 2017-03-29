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

class GameCore
{
  public:
    /* Canonical Methods */
    GameCore();
    virtual ~GameCore();
    GameCore(const GameCore &);
    GameCore	&operator=(const GameCore &);
};

#endif		/* !_GAME_CORE__HPP_ */