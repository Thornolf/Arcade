/*
** SnakeGame.cpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/games/snake/SnakeGame.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 12:08:29 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 12:08:29 2017 Guillaume CAUCHOIS
*/

#include "SnakeGame.hpp"

SnakeGame::SnakeGame()
{
  this->del = 70000;
  this->points = 0;
  this->maxWidth = 100;
  this->maxHeight = 100;
  this->partChar = 'O';
  this->oldalChar = ' ';
  this->foodChar = 'F';
}

SnakeGame::SnakeGame(const SnakeGame &obj)
{
  this->del = obj.del;
  this->points = obj.points;
  this->maxWidth = obj.maxWidth;
  this->maxHeight = obj.maxHeight;
}

SnakeGame::~SnakeGame() {}

SnakeGame &SnakeGame::operator=(const SnakeGame &obj)
{
  this->del = obj.del;
  this->points = obj.points;
  this->maxWidth = obj.maxWidth;
  this->maxHeight = obj.maxHeight;
  return (*this);
}

void	SnakeGame::setWidth(int newWidth)
{
  this->maxWidth = newWidth;
}

void	SnakeGame::setHeight(int newHeight)
{
  this->maxHeight = newHeight;
}

void	SnakeGame::setPoints(int newPoints)
{
  this->points = newPoints;
}

void	SnakeGame::setDel(int newDel)
{
  this->del = newDel;
}

void	SnakeGame::setPartChar(char newChar)
{
  this->partChar = newChar;
}

void	SnakeGame::setOldalChar(char newChar)
{
  this->oldalChar = newChar;
}

void	SnakeGame::setFoodChar(char newChar)
{
  this->foodChar = newChar;
}

int	SnakeGame::getWidth(void) const
{
  return (this->maxWidth);
}

int	SnakeGame::getHeight(void) const
{
  return (this->maxHeight);
}

int	SnakeGame::getPoints(void) const
{
  return (this->points);
}

int	SnakeGame::getDel(void) const
{
  return (this->del);
}

char	SnakeGame::getPartChar(void) const
{
  return (this->partChar);
}

char	SnakeGame::getOldalChar(void) const
{
  return (this->oldalChar);
}

char	SnakeGame::getFoodChar(void) const
{
  return (this->foodChar);
}