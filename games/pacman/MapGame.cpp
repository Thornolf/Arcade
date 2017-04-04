/*
** MapGame.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:09:11 2017 Quentin Baudet
** Last update Tue Apr 04 11:58:42 2017 Quentin Baudet
*/

#include "MapGame.hpp"
#include "ParserMap.hpp"

MapGame::MapGame(int newLength, int newHeight)
{
  this->_height = newHeight;
  this->_length = newLength;
}

void	MapGame::setData(int **newData)
{
  this->_data = newData;
}

/* GETTER */
int	MapGame::getMapHeight() const
{
  return(this->_height);
}

int	MapGame::getMapLength() const
{
  return(this->_length);
}

/* SETTER */
void 	MapGame::setMapHeight(int newHeight)
{
  this->_height = newHeight;
}


void 	MapGame::setMapLength(int newLength)
{
  this->_length = newLength;
}