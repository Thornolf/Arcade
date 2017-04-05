/*
** SnakePart.cpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/games/snake/SnakePart.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 11:57:24 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 11:57:24 2017 Guillaume CAUCHOIS
*/

#include "SnakePart.hpp"

SnakePart::SnakePart()
{
  this->x = 0;
  this->y = 0;
}

SnakePart::SnakePart(int newX, int newY)
{
  this->x = newX;
  this->y = newY;
}

SnakePart::SnakePart(const SnakePart &obj)
{
  this->x = obj.x;
  this->y = obj.y;
}

SnakePart::~SnakePart() {}

SnakePart	&SnakePart::operator=(const SnakePart &obj)
{
  this->x = obj.x;
  this->y = obj.y;
  return (*this);
}

void	SnakePart::setX(int newX)
{
  this->x = newX;
}

void	SnakePart::setY(int newY)
{
  this->y = newY;
}

int	SnakePart::getX(void) const
{
  return (this->x);
}

int	SnakePart::getY(void) const
{
  return (this->y);
}