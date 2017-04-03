/*
** BuildingMap.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:09:11 2017 Quentin Baudet
** Last update Mon Apr 03 19:24:34 2017 Quentin Baudet
*/

#include "/home/baudet_q/rendu/CPP/cpp_arcade/inc/BuildingMap.hpp"
#include "/home/baudet_q/rendu/CPP/cpp_arcade/inc/ParserMap.hpp"

BuildingMap::BuildingMap() {
	// this->_map = new int*[0];
	// for (int i = 0; i < 1; i++) {
	// 	this->_map[i] = new int[0];
	// }
	std::cout << "Construction" << std::endl;
}

void 	BuildingMap::setMap(int newLength, int newHeight) {
	this->_map = new int*[newHeight];
	for (int i = 0; i < newHeight; i++) {
		this->_map[i] = new int[newLength];
	}
}
int main(void) {
	ParserMap *i = new ParserMap();
	BuildingMap *mapy = new BuildingMap();

	i->setMapIntel("./assets/map.cnf");
	std::cout << "Height -> " <<  i->getMapHeight() << "Length -> " << i->getMapLength() << '\n';
	mapy->setMap(i->getMapLength(), i->getMapHeight());
}
