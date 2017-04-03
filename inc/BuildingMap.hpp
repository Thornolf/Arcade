/*
** BuildingMap.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:06:09 2017 Quentin Baudet
** Last update Mon Apr 03 22:51:29 2017 Quentin Baudet
*/

#ifndef BUILDINGMAP_HPP
# define BUILDINGMAP_HPP

#include <iostream>
#include <fstream>

class BuildingMap {
	private:
		int**		_map;

	public:
		BuildingMap ();
		void setMap(int, int);
		void addDataInMap(std::string);
		virtual ~BuildingMap () {}
	};

#endif /* !BUILDINGMAP_HPP */
