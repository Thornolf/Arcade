/*
** SnakeGraph.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Apr 06 12:34:11 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 14:49:11 2017 Quentin Baudet
*/

#include "sfml/GraphicInit.hpp"
#include "sfml/SnakeGraph.hpp"

Graph::SnakeGraph::SnakeGraph()
{
  this->_key	= 3;
  this->_init	= new Graph::GraphicInit("GAME-OVER ARCADE | SNAKE");
}

Graph::SnakeGraph::SnakeGraph(const Graph::SnakeGraph &obj)
{
	(void)obj;
}

Graph::SnakeGraph::~SnakeGraph()
{
  delete this->_init;
}

Graph::SnakeGraph	&Graph::SnakeGraph::operator=(const Graph::SnakeGraph &obj)
{
  this->_key = obj._key;
  return (*this);
}

void	Graph::SnakeGraph::drawMap(int width, int height, char wallChar)
{
	// sf::CircleShape shape(50);
	// shape.setFillColor(sf::Color(100, 250, 50));
  (void)width;
  (void)height;
  (void)wallChar;
}

/* Need be implemented */
void	Graph::SnakeGraph::drawScore(int, int) {}
void	Graph::SnakeGraph::drawPlayer(std::vector<Game::IGame*>, char) {}
void	Graph::SnakeGraph::drawFood(int, int, char) {}
int	Graph::SnakeGraph::recoverKey(void) { return (this->_key); }
void	Graph::SnakeGraph::drawLoose(void) {}

/* Unused function inherit from IGraph */
void	Graph::SnakeGraph::createMap(void) {}
void	Graph::SnakeGraph::Game(void)  {}
void	Graph::SnakeGraph::SetSprite(int, int, Game::IGame *)  {}
void	Graph::SnakeGraph::UnsetSprite(int, int, Game::IGame *)  {}
void	Graph::SnakeGraph::Animation() {}
void	Graph::SnakeGraph::displayMap(int **){}
void	Graph::SnakeGraph::displayMap(int **, int, int, int) {}
bool	Graph::SnakeGraph::checkSizeWindow(int, int) {return (false);}

std::pair<std::string, std::string>	Graph::SnakeGraph::startMenu(const std::vector<std::string> &, const std::vector<std::string> &)
{
  return (std::make_pair("", ""));
}

extern "C"
{
  Graph::IGraph*	getInstanceSnakeGraph()
  {
    return (reinterpret_cast<Graph::IGraph*>(new Graph::SnakeGraph()));
  }
}
