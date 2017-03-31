/*
** GraphicMenu.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
*/

#include <ncurses.h>
#include "GraphicMenu.hpp"

Graph::GraphicMenu::GraphicMenu() {}

Graph::GraphicMenu::GraphicMenu(const Graph::GraphicMenu &obj)
{
  (void)obj;
}

Graph::GraphicMenu::~GraphicMenu() {}

Graph::GraphicMenu	&Graph::GraphicMenu::operator=(const Graph::GraphicMenu &obj)
{
  (void)obj;
  return (*this);
}

void	Graph::GraphicMenu::startMenu(void)
{
  erase();
  timeout(-1);
  mvprintw(0, 0, "Press any key to exit...\n");
  getch();
  endwin();
}

void	Graph::GraphicMenu::Game(void)  {}

void	Graph::GraphicMenu::SetSprite(int x, int y)
{
  (void)x;
  (void)y;
}
void	Graph::GraphicMenu::UnsetSprite(int x, int y)
{
  (void)x;
  (void)y;
}

void	Graph::GraphicMenu::Animation() {}

extern "C"
{
  Graph::IGraph	*instanceGraphicMenu()
  {
    return (new Graph::GraphicMenu());
  }
}