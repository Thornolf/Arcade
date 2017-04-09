/*
** MapGame.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:09:11 2017 Quentin Baudet
** Last update Sun Apr 09 19:10:41 2017 Quentin Baudet
*/

#include "ParserMap.hpp"
#include "MapGame.hpp"
#include "APCharacter.hpp"

MapGame::MapGame(int newLength, int newHeight)
{
  this->_amountPacGum = 0;
  this->_height = newHeight;
  this->_length = newLength;
  this->_data = new int*[this->_height + 1];
  for (int i = 0; i != this->_height + 1; i++)
    this->_data[i] = new int[this->_length + 1];
}

MapGame::MapGame(const MapGame &obj)
{
  this->_amountPacGum = obj._amountPacGum;
  this->_height = obj._height;
  this->_length = obj._length;
  this->_data = obj._data;
}

MapGame::~MapGame()
{
  for (int i = 0; i != this->_height + 1; i++)
  {
    delete[] this->_data[i];
  }
  delete[] this->_data;
}

MapGame		&MapGame::operator=(const MapGame &obj)
{
  this->_amountPacGum = obj._amountPacGum;
  this->_height = obj._height;
  this->_length = obj._length;
  this->_data = obj._data;
  return (*this);
}

void 	MapGame::setAmountPacGum(int newAmountPacGum) {
	this->_amountPacGum = newAmountPacGum;
}

int 	MapGame::getAmountPacGum(void) const {
	return (this->_amountPacGum);
}

void	MapGame::fillUpData(int index_line, const std::string &line)
{
  for (size_t index_char = 0; index_char != line.length(); ++index_char)
  {
    if ( line.c_str()[index_char] - '0' == 9)
      this->_data[index_line][index_char] = -1;
    else
      this->_data[index_line][index_char] = (line.c_str())[index_char] - '0';
	 if ( line.c_str()[index_char] - '0' == 1)
	 {
		 int tmp = this->getAmountPacGum() + 1;
		 this->setAmountPacGum(tmp);
	}
  }
  for (int i = 0; i <= this->_height; i++) {
	  if (i == 0 || i == this->_height - 1) {
		  for (int j = 0; j <= this->_length; j++) {
			  if (this->_data[i][j] != 0)
			  	throw Arcade::ArcadeException("Bad map format");
		  }
	  }
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

void 	MapGame::displayMap(int** newMap) const
{
  for (int i = 0; i < this->getMapHeight(); i++)
  {
    for (int j = 0; j < this->getMapLength(); j++)
      std::cout << newMap[i][j] << "  ";
    std::cout << std::endl;
  }
}
int 	**MapGame::getData() const
{
  if (this->_data == NULL)
    throw Arcade::ArcadeException("Cannot get non-generated map");
  return (this->_data);
}

int 	**MapGame::modifyMap(int **newMap, int newPosY, int newPosX, Pacman *pacman)
{
  if (newMap[newPosY][newPosX] == 1 && pacman->getId() == 1)
  {}
  return (newMap);
}

int 	**MapGame::modifyMap(int **newMap, int newPosY, int newPosX, Ghost *ghost)
{
  if ((newMap[newPosY][newPosX] == BlockType::VOID || newMap[newPosY][newPosX] == BlockType::WAY )&& ghost->getId() == 2)
    newMap[newPosY][newPosX] = 9;
  return (newMap);
}
