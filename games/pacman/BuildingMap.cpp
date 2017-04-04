/*
** BuildingMap.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:09:11 2017 Quentin Baudet
** Last update Tue Apr 04 11:58:42 2017 Quentin Baudet
*/

#include "BuildingMap.hpp"
#include "ParserMap.hpp"

BuildingMap::BuildingMap(int length, int height) {
  this->setMap(length, height);
}

void 	BuildingMap::setMap(int newLength, int newHeight)
{
  this->_map = new int*[newHeight + 1];
  for (int i = 0; i <= newHeight + 1; i++)
    this->_map[i] = new int[newLength + 1];
}

/* GETTER */

int	**BuildingMap::getMap() const
{
  return (this->_map);
}

void 	BuildingMap::addDataInMap(std::string fileName)
{
  size_t height = 0;
  size_t width = 0;
  std::string line;
  std::ifstream myfile (fileName);
  if (!myfile.is_open())
  	return ;
  while (getline(myfile,line))
  {
    if (height <= 1)
    {
      height++;
      continue;
    }
    for (int i = 0; i != width ; ++i)
    {
      this->_map[height - 2][i] = (line.c_str())[i];
    }
    std::cout << std::endl;
    height++;
  }
  myfile.close();
}


int main(void) {
  ParserMap *i = new ParserMap();
  BuildingMap *mapy;

  i->setMapIntel("./assets/map.cnf");
  mapy = new BuildingMap(i->getMapLength(), i->getMapHeight());
  std::cout << "Height -> " <<  i->getMapHeight() << "Length -> " << i->getMapLength() << '\n';
  mapy->addDataInMap("./assets/map.cnf");
}
