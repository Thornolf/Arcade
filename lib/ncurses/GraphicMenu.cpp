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

char**	vectorStringToArrayArrayChar(const std::vector<std::string> &vector)
{
  char	**array;
  int	i;

  array = new char*[vector.size() + 1];
  i = 0;
  for (auto it = vector.begin(); it != vector.end(); ++it)
  {
    array[i] = new char[strlen(it->c_str()) + 1];
    strcpy(array[i], it->c_str());
    i++;
  }
  array[i] = NULL;
  return (array);
}

ITEM	**getItemsList(std::vector<std::string> listChoices)
{
  ITEM**	itemsList;
  unsigned int		i;
  char**	CItemList;

  itemsList = new ITEM*[listChoices.size() + 1];
  CItemList = vectorStringToArrayArrayChar(listChoices);
  i = 0;
  while (i != listChoices.size())
  {
    itemsList[i] = new_item(CItemList[i], CItemList[i]);
    i++;
  }
  itemsList[i] = NULL;
  return (itemsList);
}

std::string	Graph::GraphicMenu::MenuLoop(MENU *menu) const
{
  int			pkey;
  ITEM			*cur;
  std::stringstream	ss;

  while ((pkey = getch()) != 10 && pkey != KEY_RIGHT)
  {
    switch (pkey)
    {
      case KEY_DOWN:
	menu_driver(menu, REQ_DOWN_ITEM);
	break;
      case KEY_UP:
	menu_driver(menu, REQ_UP_ITEM);
	break;
    }
  }
  if (!(cur = current_item(menu)))
    throw Arcade::ArcadeException("You have to select a library");
  if (!(item_name(cur)))
    throw Arcade::ArcadeException("You have to select a library");
  ss << item_name(cur);
  return (ss.str());
}

std::string	Graph::GraphicMenu::startMenu(const std::string &title, const std::vector<std::string> &listItems) const
{
  ITEM		**items;
  MENU		*menu;
  std::string	name_library_chosen;

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  refresh();
  erase();
  timeout(-1);

  items	= getItemsList(listItems);
  menu	= new_menu(items);
  /* Menu */
  mvprintw(listItems.size() + 2, 0, title.c_str());
  post_menu(menu);
  try
  {
    name_library_chosen = this->MenuLoop(menu);
  }
  catch (const Arcade::ArcadeException &e)
  {
    throw Arcade::ArcadeException(e.what());
  }
  endwin();
  for (unsigned int i = 0; i != listItems.size(); i++)
  {
   free_item(items[i]);
  }
  free_menu(menu);
  delete[] items;
  return (name_library_chosen);
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