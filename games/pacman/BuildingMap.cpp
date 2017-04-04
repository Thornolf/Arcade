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

BuildingMap::BuildingMap() {
  // this->_map = new int*[0];
  // for (int i = 0; i < 1; i++) {
  // 	this->_map[i] = new int[0];
  // }
  std::cout << "Construction" << std::endl;
}

/* SETTER */

void 	BuildingMap::setMap(int newLength, int newHeight) {
  this->_map = new int*[newHeight];
  for (int i = 0; i < newHeight; i++) {
    this->_map[i] = new int[newLength];
  }
}

/* GETTER */

int		**BuildingMap::getMap() const {
	return (this->_map);
}

void 	BuildingMap::addDataInMap(std::string fileName)
{
  size_t height = 0;
  size_t width = 0;
  std::string line;
  std::ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      if (height > 1) {
		  for (size_t i = 0; i < line.length(); i++) {
			  this->_map[height][width] = line[width];
		  }
	  }
	height++;
    }
    myfile.close();
  }
  else
    std::cerr << "Unable to open file" << std::endl;
}


int main(void) {
  ParserMap *i = new ParserMap();
  BuildingMap *mapy = new BuildingMap();

  i->setMapIntel("./assets/map.cnf");
  std::cout << "Height -> " <<  i->getMapHeight() << "Length -> " << i->getMapLength() << '\n';
  mapy->setMap(i->getMapLength(), i->getMapHeight());

}
