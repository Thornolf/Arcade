/*
** IGhost.hpp for cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Thu Mar 09 17:01:36 2017 Thomas Fossaert
** Last update Tue Mar 14 09:09:30 2017 Thomas Fossaert
*/

#ifndef		__IGAME_HPP__
# define	__IGAME_HPP__

# include <iostream>
# include "IGraph.hpp"
# include "ArcadeCore.hpp"

namespace Game
{
  enum State
  {
    INVUNERABLE = 0,
    VULNERABLE = 1
  };

  class IGame
  {
    public:
      virtual ~IGame(void) { };

      virtual void startCore(Arcade::DLLoader<Graph::IGraph> &) = 0;
      virtual void movePlayer() = 0;
      virtual void setX(int) = 0;
      virtual void setY(int) = 0;
      virtual void setState(Game::State state) = 0;
      virtual void setSpeed(size_t speed) = 0;
      virtual int getX() const = 0;
      virtual int getY() const = 0;
      virtual Game::State getState() const = 0;
      virtual size_t getSpeed() const = 0;
      virtual bool isAlive() const = 0;
      virtual void Dump(void) const = 0;
  };
}

#endif		/* __IGAME_HPP__ */
