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

# include	<iostream>

namespace game
{
  enum State
  {
    INVUNERABLE = 0,
    VULNERABLE = 1
  };

  class IGame
  {
    public:
      virtual void move() = 0;
      virtual void setX(int pos) = 0;
      virtual void setY(int pos) = 0;
      virtual void setState(game::State state) = 0;
      virtual void setSpeed(size_t speed) = 0;
      //virtual void setPoint(size_t point) = 0;
      virtual int getX() const = 0;
      virtual int getY() const = 0;
      virtual game::State getState() const = 0;
      virtual size_t getSpeed() const = 0;
      //virtual size_t getPoint() const = 0;
      virtual bool isAlive() const = 0;
      virtual void Dump(void) const = 0;
      virtual ~IGame(void) { };
  };
}

#endif		/* __IGAME_HPP__ */
