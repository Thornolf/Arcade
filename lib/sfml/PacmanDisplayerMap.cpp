/*
** PacmanDisplayerMap.cpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/lib/sfml/PacmanDisplayerMap.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Apr 04 18:00:48 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 14:49:04 2017 Quentin Baudet
*/

#include "sfml/GraphicInit.hpp"
#include "PacmanDisplayerMap.hpp"

Graph::PacmanDisplayerMap::PacmanDisplayerMap()
{
  throw Arcade::ArcadeException("Pacman not implemented for lib-sfml");
  this->_init	= new Graph::GraphicInit("GAME-OVER ARCADE | PACMAN");
}

Graph::PacmanDisplayerMap::PacmanDisplayerMap(const Graph::PacmanDisplayerMap &) {}

Graph::PacmanDisplayerMap::~PacmanDisplayerMap()
{
  delete this->_init;
}

Graph::PacmanDisplayerMap	&Graph::PacmanDisplayerMap::operator=(const Graph::PacmanDisplayerMap &)
{
  return (*this);
}

void	Graph::PacmanDisplayerMap::displayMap(int **) {}

extern "C"
{
  Graph::IGraph	*getInstancePacmanDisplayerMap()
  {
    return (new Graph::PacmanDisplayerMap());
  }
}

/* Unused Methods from Graph::IGraph */
void	Graph::PacmanDisplayerMap::createMap() {}
void	Graph::PacmanDisplayerMap::Game() {}
void	Graph::PacmanDisplayerMap::SetSprite(int, int, Game::IGame *)  {}
void	Graph::PacmanDisplayerMap::UnsetSprite(int, int, Game::IGame *)  {}
void	Graph::PacmanDisplayerMap::Animation() {}
void	Graph::PacmanDisplayerMap::drawMap(int, int, char) {}
void	Graph::PacmanDisplayerMap::displayMap(int **, int, int, int) {}
void	Graph::PacmanDisplayerMap::drawPlayer(std::vector<Game::IGame*>, char) {}
void	Graph::PacmanDisplayerMap::drawScore(int, int) {};
void	Graph::PacmanDisplayerMap::drawFood(int, int, char) {};
void	Graph::PacmanDisplayerMap::drawLoose(void) {};
int	Graph::PacmanDisplayerMap::recoverKey(void) {return (0);};
bool	Graph::PacmanDisplayerMap::checkSizeWindow(int, int) {return (false);}
std::pair<std::string, std::string>	Graph::PacmanDisplayerMap::startMenu(const std::vector<std::string> &, const std::vector<std::string> &)
{
  return (std::pair<std::string, std::string>("", ""));
}
