/*
** PacmanDisplayerMap.cpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/lib/sfml/PacmanDisplayerMap.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Apr 04 18:00:48 2017 Guillaume CAUCHOIS
** Last update Tue Apr 04 18:00:48 2017 Guillaume CAUCHOIS
*/

#include "PacmanDisplayerMap.hpp"

Graph::PacmanDisplayerMap::PacmanDisplayerMap()
{

}

Graph::PacmanDisplayerMap::PacmanDisplayerMap(const Graph::PacmanDisplayerMap &obj)
{
  (void)obj;
}

Graph::PacmanDisplayerMap::~PacmanDisplayerMap() {}

Graph::PacmanDisplayerMap	&Graph::PacmanDisplayerMap::operator=(const Graph::PacmanDisplayerMap &obj)
{
  (void)obj;
  return (*this);
}

void	Graph::PacmanDisplayerMap::displayMap(int **map)
{
  std::cout << "DISPLAY LA MAP" << std::endl;
  (void)map;
}

extern "C"
{
Graph::IGraph	*getInstancePacmanDisplayerMap()
{
  return ((Graph::IGraph *)new Graph::PacmanDisplayerMap());
}
}
/* Unused Methods from Graph::IGraph */
void	Graph::PacmanDisplayerMap::createMap() {}
void	Graph::PacmanDisplayerMap::Game() {}
void	Graph::PacmanDisplayerMap::SetSprite(int x, int y) {(void)x; (void)y;}
void	Graph::PacmanDisplayerMap::UnsetSprite(int x, int y) {(void)x; (void)y;}
void	Graph::PacmanDisplayerMap::Animation() {}

std::pair<std::string, std::string>	Graph::PacmanDisplayerMap::startMenu(const std::vector<std::string> &title, const std::vector<std::string> &list)
{
  (void)list;
  (void)title;
  return (std::pair<std::string, std::string>("", ""));
}