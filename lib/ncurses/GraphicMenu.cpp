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
#include "ncurses/GraphicInit.hpp"

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
  unsigned int	i;
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

std::string	Graph::GraphicMenu::MenuLoop(const std::string &title, WINDOW *win, MENU *menu) const
{
  int			pkey;
  ITEM			*cur;
  std::stringstream	ss;

  this->postMenuInWindow(win, menu, title);
  while ((pkey = wgetch(win)) != 10 && pkey != KEY_RIGHT)
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
  unpost_menu(menu);
  free_menu(menu);
  return (ss.str());
}

void		Graph::GraphicMenu::displayAofARCADE(void) const
{
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  if (has_colors())
    attron(COLOR_PAIR(1));
  mvprintw(0, 3, "AAAAAA");
  mvprintw(1, 3, "AA  AA");
  mvprintw(2, 3, "AAAAAA");
  mvprintw(3, 3, "AA  AA");
  mvprintw(4, 3, "AA  AA");
  if (has_colors())
    attroff(COLOR_PAIR(3));
}

void		Graph::GraphicMenu::displayRofARCADE(void) const
{
  init_pair(2, COLOR_RED, COLOR_BLACK);
  if (has_colors())
    attron(COLOR_PAIR(2));
  mvprintw(0, 11, "RRRRRR");
  mvprintw(1, 11, "RR  RR");
  mvprintw(2, 11, "RR RRR");
  mvprintw(3, 11, "RRRR");
  mvprintw(4, 11, "RR  RR");
  if (has_colors())
    attroff(COLOR_PAIR(2));
}

void		Graph::GraphicMenu::displayCofARCADE(void) const
{
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  if (has_colors())
    attron(COLOR_PAIR(3));
  mvprintw(0, 19, "CCCCCC  ");
  mvprintw(1, 19, "CC      ");
  mvprintw(2, 19, "CC      ");
  mvprintw(3, 19, "CC      ");
  mvprintw(4, 19, "CCCCCC  ");
  if (has_colors())
    attroff(COLOR_PAIR(3));
}

void		Graph::GraphicMenu::displayA_BIS_ofARCADE(void) const
{
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  if (has_colors())
    attron(COLOR_PAIR(4));
  mvprintw(0, 27, "AAAAAA");
  mvprintw(1, 27, "AA  AA");
  mvprintw(2, 27, "AAAAAA");
  mvprintw(3, 27, "AA  AA");
  mvprintw(4, 27, "AA  AA");
  if (has_colors())
    attroff(COLOR_PAIR(4));
}

void		Graph::GraphicMenu::displayDofARCADE(void) const
{
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  if (has_colors())
    attron(COLOR_PAIR(5));
  mvprintw(0, 35, "DDDDE");
  mvprintw(1, 35, "DD DD");
  mvprintw(2, 35, "DD  DD");
  mvprintw(3, 35, "DD DD");
  mvprintw(4, 35, "DDDD");
  if (has_colors())
    attroff(COLOR_PAIR(5));
}

void		Graph::GraphicMenu::displayEofARCADE(void) const
{
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);
  if (has_colors())
    attron(COLOR_PAIR(6));
  mvprintw(0, 43, "EEEEEE");
  mvprintw(1, 43, "EE");
  mvprintw(2, 43, "EEEE");
  mvprintw(3, 43, "EE");
  mvprintw(4, 43, "EEEEEE");
  if (has_colors())
    attroff(COLOR_PAIR(6));
}

void		Graph::GraphicMenu::displayArcadeTitle(void) const
{
  this->displayAofARCADE();
  this->displayRofARCADE();
  this->displayCofARCADE();
  this->displayA_BIS_ofARCADE();
  this->displayDofARCADE();
  this->displayEofARCADE();
}

void	Graph::GraphicMenu::displayRulesMenu(void) const
{
  mvprintw(6, 3, "1- Select the graphic library to use for the display");
  mvprintw(7, 3, "2- Select the game to play");
  mvprintw(8, 3, "3- Play!");
  mvprintw(LINES - 2, 0, "Press ESC to exit");
}

void	Graph::GraphicMenu::postMenuInWindow(WINDOW *window, MENU* menu, const std::string &title) const
{
  set_menu_win(menu, window);
  set_menu_sub(menu, derwin(window, 6, 38, 3, 1));
  set_menu_mark(menu, " | ");
  box(window, 0, 0);
  mvwprintw(window, 1, 10, "%s", title.c_str());
  mvwaddch(window, 2, 0, ACS_LTEE);
  mvwaddch(window, 2, 39, ACS_RTEE);
  mvwhline(window, 2, 1, ACS_HLINE, 38);
  wattroff(window, COLOR_PAIR(1));
  refresh();
  post_menu(menu);
  wrefresh(window);
}

std::pair<std::string, std::string>	Graph::GraphicMenu::startMenu(const std::vector<std::string> &listGraphics, const std::vector<std::string> &listGames)
{
  ITEM		**items_graphics;
  ITEM		**items_games;
  MENU		*menu_graphics;
  MENU		*menu_games;
  std::string	name_library_graphic;
  std::string	name_library_game;
  WINDOW	*window;
  Graph::GraphicInit	initGraphic;

  window = newwin(10, 40, 10, 5);
  keypad(window, TRUE);
  items_graphics	= getItemsList(listGraphics);
  menu_graphics		= new_menu(items_graphics);
  items_games		= getItemsList(listGames);
  menu_games		= new_menu(items_games);
  this->displayArcadeTitle();
  this->displayRulesMenu();
  try
  {
    name_library_graphic	= this->MenuLoop("GRAPHIC LIBRARY", window, menu_graphics);
    name_library_game		= this->MenuLoop("GAME LIBRARY", window, menu_games);
  }
  catch (const Arcade::ArcadeException &e)
  {
    throw Arcade::ArcadeException(e.what());
  }
  for (unsigned int i = 0; i != listGraphics.size(); i++)
    free_item(items_graphics[i]);
  for (unsigned int i = 0; i != listGames.size(); i++)
    free_item(items_games[i]);
  delete[] items_graphics;
  delete[] items_games;
  return (std::make_pair(name_library_graphic, name_library_game));
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
void	Graph::GraphicMenu::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicMenu::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicMenu::Animation() {}
void	Graph::GraphicMenu::displayMap(int **){};
void	Graph::GraphicMenu::displayMap(int **, int, int) {}
void	Graph::GraphicMenu::LaunchMenuSound(sf::Music &, const std::string &filepath) const {(void)filepath;}
void	Graph::GraphicMenu::drawMap(int, int, char) {}
void	Graph::GraphicMenu::drawPlayer(std::vector<Game::IGame*>, char) {};
void	Graph::GraphicMenu::drawScore(int, int) {};
void	Graph::GraphicMenu::drawFood(int, int, char) {};
void	Graph::GraphicMenu::drawLoose(void) {};
int	Graph::GraphicMenu::recoverKey(void) {return (0);};
bool	Graph::GraphicMenu::checkSizeWindow(int, int) {return (false);}

sf::Sprite	Graph::GraphicMenu::createSpriteFromFile(sf::Texture &texture, const std::string &filepath, bool smooth) const
{
  (void)texture;
  (void)filepath;
  (void)smooth;
  return (sf::Sprite());
}

std::string	Graph::GraphicMenu::MenuLoop(sf::RenderWindow &window,
						sf::Sprite &sprite_bg,
						sf::Sprite &sprite_logo,
						const std::string &title,
						std::vector<std::string> listItems)
{
  (void)window;
  (void)sprite_bg;
  (void)sprite_logo;
  (void)title;
  (void)listItems;
  return ("");
}