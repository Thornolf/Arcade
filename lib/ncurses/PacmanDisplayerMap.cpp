/*
** PacmanDisplayerMap.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Apr 04 16:10:01 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 16:48:57 2017 Quentin Baudet
*/

#include "PacmanDisplayerMap.hpp"

Graph::PacmanDisplayerMap::PacmanDisplayerMap()
{
  this->_key = 3;
  this->_init = new Graph::GraphicInit();
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
}

Graph::PacmanDisplayerMap::PacmanDisplayerMap(const Graph::PacmanDisplayerMap &) {}

Graph::PacmanDisplayerMap::~PacmanDisplayerMap()
{
  delete this->_init;
}

Graph::PacmanDisplayerMap	&Graph::PacmanDisplayerMap::operator=(const Graph::PacmanDisplayerMap &)
{
  return (*this);
}

void	Graph::PacmanDisplayerMap::displayMap(int **) {}

void 	Graph::PacmanDisplayerMap::drawElem(char printChar, int x, int y)
{
  if (printChar == 'c')
  {
    attron(COLOR_PAIR(1));
    mvprintw(x, y, "c");
    attroff(COLOR_PAIR(1));
  }
  else if (printChar == '.')
  {
    attron(COLOR_PAIR(2));
    mvprintw(x, y, ".");
    attroff(COLOR_PAIR(2));
  }
  else if (printChar == 'C')
  {
    attron(COLOR_PAIR(2));
    mvprintw(x, y, "C");
    attroff(COLOR_PAIR(2));
  }
  else if (printChar == ' ')
  {
    mvprintw(x, y, " ");
  }
}

void	Graph::PacmanDisplayerMap::displayMap(int **map, int length, int height, int newScore)
{
  int	i = 0;
  int	j = 0;

  while (i < length)
  {
    while (j < height)
    {
      if (map[i][j] == 0)
	drawElem('c', i, j);
      else if (map[i][j] == 1)
	drawElem('.', i, j);
      else if (map[i][j] == 7)
	drawElem('C', i, j);
      else if (map[i][j] == -1)
	drawElem(' ', i, j);
      j++;
    }
    j = 0;
    i++;
  }
  mvprintw(30, 5, "Score : %d", newScore);
  refresh();
}

int		Graph::PacmanDisplayerMap::recoverKey(void)
{
  int	tmp = getch();

  switch(tmp)
  {
    case KEY_UP:
      this->_key = 0;
      break;
    case KEY_RIGHT:
      this->_key = 1;
      break;
    case KEY_DOWN:
      this->_key = 2;
      break;
    case KEY_LEFT:
      this->_key = 3;
      break;
    case 27:
      this->_key = 4;
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

std::pair<std::string, std::string>	Graph::PacmanDisplayerMap::startMenu(const std::vector<std::string> &, const std::vector<std::string> &)
{
  return (std::pair<std::string, std::string>("", ""));
}
