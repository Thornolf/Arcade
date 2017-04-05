/*
** MapGame.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:09:11 2017 Quentin Baudet
** Last update Wed Apr 05 14:20:51 2017 Quentin Baudet
*/

#include "MapGame.hpp"
#include "ParserMap.hpp"

MapGame::MapGame(int newLength, int newHeight)
{
  this->_height = newHeight;
  this->_length = newLength;
  this->_data = new int*[this->_height + 1]; /* !! */
  for (int i = 0; i != this->_height + 1; i++)
    this->_data[i] = new int[this->_length + 1]; /* !! */
}

void	MapGame::fillUpData(int index_line, const std::string &line)
{
	for (size_t index_char = 0; index_char != line.length(); ++index_char) {
      this->_data[index_line][index_char] = (line.c_str())[index_char] - '0';
  }
}

/* NO USED */
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

/* GETTER */

int 	**MapGame::getData() const
{
	if (this->_data == NULL)
		throw Arcade::ArcadeException("Cannot get non-generated map");
	return (this->_data);
}
