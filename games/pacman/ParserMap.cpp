/*
** ParserMap.cpp for pacman in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 17:45:24 2017 Quentin Baudet
** Last update Mon Apr 03 22:51:23 2017 Quentin Baudet
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
  int		**data;

  /* Malloc */
  data = new int*[this->_height + 1];
  for (int i = 0; i != this->_height + 1; i++)
    data[i] = new int[this->_length + 1];

  /* Fill up data */
  index_line = 0;
  for (auto it = this->_buffer.begin(); it != this->_buffer.end(); ++it)
  {
    for (size_t index_char = 0; index_char != it->length(); ++index_char)
      data[index_line][index_char] = (it->c_str())[index_char] - '0';
  }
  map.setData(data);
  this->_map = &map;
}