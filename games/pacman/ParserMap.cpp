/*
** ParserMap.cpp for pacman in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 17:45:24 2017 Quentin Baudet
** Last update Sun Apr 09 18:18:21 2017 Quentin Baudet
*/

#include "ParserMap.hpp"

ParserMap::ParserMap(const std::string &filepath)
{
  std::ifstream	myFile (filepath);
  std::string	line;
  int	i = 0;
  int 	tmp_length = 0;
  this->_height = 0;
  this->_length = 0;

  if (!myFile.is_open())
  	throw Arcade::ArcadeException("Cannot read the map file");
  while (getline(myFile,line))
  {
    if (i == 0)
      this->_height = std::stoi(line);
    else if (i == 1)
      this->_length = std::stoi(line);
    if (i >= 2)
	{
		if (i > 2) {
			int tmp = line.length();
			if ((tmp_length != tmp))
				throw Arcade::ArcadeException("Bad map format");
		}
		tmp_length = line.length();
      this->_buffer.push_back(line);
  	}
    i++;
  }
  if ((i - 2) != this->_height)
  	throw Arcade::ArcadeException("Bad map format");
  if (tmp_length != this->_length)
  	throw Arcade::ArcadeException("Bad map format");
  this->_map = new MapGame(this->_length, this->_height);
  myFile.close();
}

ParserMap::~ParserMap() {}

MapGame		*ParserMap::getMap() const
{
  return (this->_map);
}

void 	ParserMap::generateMap(void)
{
  int		index_line;
  MapGame	map(this->_length, this->_height);

  /* Fill up data */
  index_line = 0;
  for (auto it = this->_buffer.begin(); it != this->_buffer.end(); ++it)
    this->_map->fillUpData(index_line++, *it);
}
