/*
** GraphicInit.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 16:35:23 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 16:35:23 2017 Guillaume CAUCHOIS
*/

#include "GraphicInit.hpp"

Graph::GraphicInit::GraphicInit()
{
  initscr();
  clear();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  nodelay(stdscr, TRUE);
}

Graph::GraphicInit::GraphicInit(const Graph::GraphicInit &obj)
{
  (void)obj;
}

Graph::GraphicInit::~GraphicInit()
{
  clear();
  nodelay(stdscr, FALSE);
  endwin();
}

Graph::GraphicInit	&Graph::GraphicInit::operator=(const Graph::GraphicInit &obj)
{
  (void)obj;
  return (*this);
}


/* Unused function herit from IGraph */
void	Graph::GraphicInit::createMap(void) {}
void	Graph::GraphicInit::Game(void)  {}
void	Graph::GraphicInit::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicInit::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicInit::Animation() {}
void	Graph::GraphicInit::displayMap(int **ptr){(void)ptr;}

std::pair<std::string, std::string>	Graph::GraphicInit::startMenu(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
  (void)v1;
  (void)v2;
  return (std::make_pair("", ""));
}