/*
** GraphicMenu.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
*/

#include <cstring>
#include <ncurses.h>
#include <menu.h>
#include "GraphicMenu.hpp"
# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

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

void	Graph::GraphicMenu::SetLibraryChoices(const std::vector<std::string> &ListGraphics)
{
  this->_choicesLibraries = ListGraphics;
}

void	Graph::GraphicMenu::startMenu(const std::vector<std::string> listGraphics, const std::vector<std::string> listGames) const
{
  int	i;
  std::vector<std::string>::const_iterator	it;

  (void)listGames;
  (void)listGraphics;
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  erase();
  timeout(-1);
  mvprintw(0, 0, "AVAIBLE LIBRARIES:\n");
  i = 5;
  it = listGraphics.begin();
  while (it != listGraphics.end())
  {
    mvprintw(i, 0, it->c_str());
    i++;
    it++;
  }
  i++;
  it = listGames.begin();
  while (it != listGames.end())
  {
    mvprintw(i, 0, it->c_str());
    i++;
    it++;
  }
  mvprintw(10, 0, "Press any key to exit...\n");
  getch();
  endwin();
}

extern "C"
{
  Graph::IGraph	*getInstanceGraphicMenu()
  {
    return (new Graph::GraphicMenu());
  }
}

/* Unused pure methods */
void	Graph::GraphicMenu::createMap(void) {}
void	Graph::GraphicMenu::Game(void)  {}
void	Graph::GraphicMenu::SetSprite(int x, int y)  {(void)x; (void)y;}
void	Graph::GraphicMenu::UnsetSprite(int x, int y) {(void)x; (void)y;}
void	Graph::GraphicMenu::Animation() {}
