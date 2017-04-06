/*
** SnakeGraph.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Apr 06 12:34:11 2017 Guillaume CAUCHOIS
** Last update Thu Apr 06 12:34:11 2017 Guillaume CAUCHOIS
*/

#include "sfml/GraphicInit.hpp"
#include "SnakeGraph.hpp"

Graph::SnakeGraph::SnakeGraph()
{
  this->_key	= 3;
  this->_init	= new Graph::GraphicInit("GAME-OVER ARCADE | SNAKE");
}

Graph::SnakeGraph::SnakeGraph(const Graph::SnakeGraph &obj)
{
  this->_key = obj._key;
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
  (void)width;
  (void)height;
  (void)wallChar;
}

void	Graph::SnakeGraph::drawScore(int score, int width)
{
  (void)score;
  (void)width;
}

void	Graph::SnakeGraph::drawPlayer(std::vector<Game::IGame *> snake, char partChar)
{
  (void)snake;
  (void)partChar;
}

void	Graph::SnakeGraph::drawFood(int height, int width, char foodChar)
{
  (void)height;
  (void)width;
  (void)foodChar;
}

int	Graph::SnakeGraph::recoverKey(void)
{
  return (this->_key);
}

void	Graph::SnakeGraph::drawLoose(void) {}

/* Unused function inherit from IGraph */
void	Graph::SnakeGraph::createMap(void) {}
void	Graph::SnakeGraph::Game(void)  {}
void	Graph::SnakeGraph::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::SnakeGraph::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::SnakeGraph::Animation() {}
void	Graph::SnakeGraph::displayMap(int **ptr){(void)ptr;}
bool	Graph::SnakeGraph::checkSizeWindow(int, int) {return (false);}

std::pair<std::string, std::string>	Graph::SnakeGraph::startMenu(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
  (void)v1;
  (void)v2;
  return (std::make_pair("", ""));
}

extern "C"
{
  Graph::IGraph*	getInstanceSnakeGraph()
  {
    return ((Graph::IGraph *)new Graph::SnakeGraph());
  }
}