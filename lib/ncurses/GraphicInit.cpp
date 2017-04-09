/*
** GraphicInit.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 16:35:23 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 14:53:11 2017 Quentin Baudet
*/

#include "ncurses/GraphicInit.hpp"

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

/* Unused function inherit from IGraph */
void	Graph::GraphicInit::createMap(void) {}
void	Graph::GraphicInit::Game(void)  {}
void	Graph::GraphicInit::SetSprite(int, int, Game::IGame *)  {}
void	Graph::GraphicInit::UnsetSprite(int, int, Game::IGame *)  {}
void	Graph::GraphicInit::Animation() {}
void	Graph::GraphicInit::displayMap(int **ptr){(void)ptr;}
void	Graph::GraphicInit::displayMap(int **, int, int, int) {}
void	Graph::GraphicInit::drawMap(int, int, char) {}
void	Graph::GraphicInit::drawPlayer(std::vector<Game::IGame*>, char) {}
void	Graph::GraphicInit::drawScore(int, int) {}
void	Graph::GraphicInit::drawFood(int, int, char) {}
void	Graph::GraphicInit::drawLoose(void) {}
int	Graph::GraphicInit::recoverKey(void) {return (0);}
bool	Graph::GraphicInit::checkSizeWindow(int, int) {return (false);}

std::pair<std::string, std::string>	Graph::GraphicInit::startMenu(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
  (void)v1;
  (void)v2;
  return (std::make_pair("", ""));
}
