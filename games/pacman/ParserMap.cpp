/*
** ParserMap.cpp for pacman in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 17:45:24 2017 Quentin Baudet
** Last update Wed Apr 05 14:17:19 2017 Quentin Baudet
*/

#include "ParserMap.hpp"

/*       this->_map[height - 2][i] = (line.c_str())[i];
 */

/*Constructor */
ParserMap::ParserMap(const std::string &filepath)
{
  std::ifstream	myfile (filepath);
  std::string	line;
  size_t	i = 0;

  if (!myfile.is_open())
    throw Arcade::ArcadeException("Cannot read the map file");
  while (getline(myfile,line))
  {
    if (i == 0)
      this->_height = std::stoi(line);
    else if (i == 1)
      this->_length = std::stoi(line);
    if (i >= 2)
      this->_buffer.push_back(line);
    i++;
  }
  this->_map = new MapGame(this->_length, this->_height);
  myfile.close();
}

/* Destructor */
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
