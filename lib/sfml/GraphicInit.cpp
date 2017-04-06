/*
** GraphicInit.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 16:35:23 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 16:35:23 2017 Guillaume CAUCHOIS
*/

#include "sfml/GraphicInit.hpp"

Graph::GraphicInit::GraphicInit(const std::string &title)
{
  this->_window = new sf::RenderWindow(sf::VideoMode(1280, 720), title);
}

Graph::GraphicInit::GraphicInit(const Graph::GraphicInit &obj)
{
  (void)obj;
}

Graph::GraphicInit::~GraphicInit()
{
  delete this->_window;
}

Graph::GraphicInit	&Graph::GraphicInit::operator=(const Graph::GraphicInit &obj)
{
  (void)obj;
  return (*this);
}

sf::RenderWindow	*Graph::GraphicInit::getWindow(void)
{
  return (this->_window);
}

/* Unused function inherit from IGraph */
void	Graph::GraphicInit::createMap(void) {}
void	Graph::GraphicInit::Game(void)  {}
void	Graph::GraphicInit::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicInit::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicInit::Animation() {}
void	Graph::GraphicInit::displayMap(int **ptr){(void)ptr;}
void	Graph::GraphicInit::drawMap(int, int, char) {}
void	Graph::GraphicInit::drawPlayer(std::vector<Game::IGame*>, char) {};
void	Graph::GraphicInit::drawScore(int, int) {};
void	Graph::GraphicInit::drawFood(int, int, char) {};
void	Graph::GraphicInit::drawLoose(void) {};
int	Graph::GraphicInit::recoverKey(void) {return (0);};

std::pair<std::string, std::string>	Graph::GraphicInit::startMenu(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
  (void)v1;
  (void)v2;
  return (std::make_pair("", ""));
}