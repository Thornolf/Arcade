/*
** PacmanDisplayerMap.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Apr 04 16:10:01 2017 Guillaume CAUCHOIS
** Last update Fri Apr 07 12:10:55 2017 Quentin Baudet
*/

#include "PacmanDisplayerMap.hpp"

Graph::PacmanDisplayerMap::PacmanDisplayerMap()
{
  std::cout << "PASSE ICI" << std::endl;
  this->_key = 3;
  this->_init = new Graph::GraphicInit();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}

Graph::PacmanDisplayerMap::PacmanDisplayerMap(const Graph::PacmanDisplayerMap &obj)
{
  (void)obj;
}

Graph::PacmanDisplayerMap::~PacmanDisplayerMap()
{
  delete this->_init;
}

Graph::PacmanDisplayerMap	&Graph::PacmanDisplayerMap::operator=(const Graph::PacmanDisplayerMap &obj)
{
  (void)obj;
  return (*this);
}

void	Graph::PacmanDisplayerMap::displayMap(int **map)
{
  int	i = 0;
  int	j = 0;
  (void)i;
  (void)j;
  (void)map;
}

void 	Graph::PacmanDisplayerMap::drawElem(char printChar, int x, int y)
{
  (void)x;
  (void)y;
  if (printChar == 'c')
  {
    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "TOTO");
    attroff(COLOR_PAIR(1));
  }
}

void	Graph::PacmanDisplayerMap::displayMap(int **map, int length, int height)
{
  int	i = 0;
  int	j = 0;

  while (i < height)
  {
    j = 0;
    while (j < length)
    {
      if (map[i][j] == 0)
	drawElem('c', i, j);
      j++;
    }
    i++;
  }
}

int		Graph::PacmanDisplayerMap::recoverKey(void)
{
  int	tmp = getch();

  switch(tmp)
  {
    case KEY_UP:
      if (this->_key != 2)
	this->_key = 0;
      break;
    case KEY_RIGHT:
      if (this->_key != 3)
	this->_key = 1;
      break;
    case KEY_DOWN:
      if (this->_key != 0)
	this->_key = 2;
      break;
    case KEY_LEFT:
      if (this->_key != 1)
	this->_key = 3;
      break;
    case 27:
      this->_key = 5;
      break;
  }
  return (this->_key);
}

bool	Graph::PacmanDisplayerMap::checkSizeWindow(int minX, int minY)
{
  int	x = 0;
  int	y = 0;

  getmaxyx(stdscr, y, x);
  if (x <= minX + 15 || y <= minY)
    return (false);
  return (true);
}

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
void	Graph::PacmanDisplayerMap::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::PacmanDisplayerMap::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::PacmanDisplayerMap::Animation() {}
void	Graph::PacmanDisplayerMap::drawMap(int, int, char) {}
void	Graph::PacmanDisplayerMap::drawPlayer(std::vector<Game::IGame*>, char) {};
void	Graph::PacmanDisplayerMap::drawScore(int, int) {};
void	Graph::PacmanDisplayerMap::drawFood(int, int, char) {};
void	Graph::PacmanDisplayerMap::drawLoose(void) {};

std::pair<std::string, std::string>	Graph::PacmanDisplayerMap::startMenu(const std::vector<std::string> &title, const std::vector<std::string> &list)
{
  (void)list;
  (void)title;
  return (std::pair<std::string, std::string>("", ""));
}
