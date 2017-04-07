/*
** SnakeGraph.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Apr 06 12:34:11 2017 Guillaume CAUCHOIS
** Last update Thu Apr 06 22:59:23 2017 Robin Grattepanche
*/

#include "ncurses/GraphicInit.hpp"
#include "SnakeGraph.hpp"

Graph::SnakeGraph::SnakeGraph()
{
  this->_key	= 3;
  this->_init	= new Graph::GraphicInit();
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
  init_pair(1, COLOR_RED, COLOR_RED);
  attron(COLOR_PAIR(1));
  for(int i = 0; i < width - 1; i++)
  {
    move(0, i);
    addch(wallChar);
  }
  //left-vertical
  for(int i = 0; i < height - 1; i++)
  {
    move(i, 0);
    addch(wallChar);
  }
  //down-horizontal
  for(int i = 0; i < width - 1; i++)
  {
    move(height - 2, i);
    addch(wallChar);
  }
  //right-vertical
  for(int i = 0; i < height - 1; i++)
  {
    move(i, width - 2);
    addch(wallChar);
  }
  attroff(COLOR_PAIR(1));
  this->drawTitle(height);
}

void	Graph::SnakeGraph::drawScore(int score, int width)
{
  move(10, width + 3);
  printw(" Score : %d", score);
}

void	Graph::SnakeGraph::drawPlayer(std::vector<Game::IGame *> snake, char partChar)
{
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(2));
  for (size_t i = 0; i < snake.size(); i++)
  {
    move(snake[i]->getY(), snake[i]->getX());
    addch(partChar);
  }
  attroff(COLOR_PAIR(2));
  move(snake[snake.size() - 1]->getY(), snake[snake.size() - 1]->getX());
  printw(" ");
  refresh();
}

void	Graph::SnakeGraph::drawFood(int height, int width, char foodChar)
{
  move(height, width);
  addch(foodChar);
  refresh();
}

int	Graph::SnakeGraph::recoverKey(void)
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

void	Graph::SnakeGraph::drawLoose(void)
{
  move(12,36);
  printw("Game over !!");
}

bool	Graph::SnakeGraph::checkSizeWindow(int minX, int minY)
{
  int	x = 0;
  int	y = 0;

  getmaxyx(stdscr, y, x);
  if (x <= minX + 15 || y <= minY + 11)
    return (false);
  return (true);
}

void	Graph::SnakeGraph::drawTitle(int y)
{
	init_color(COLOR_YELLOW, 105, 520, 300);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	mvprintw(y, 1, "               ____  ___      ___       _     ___    __ __________             ");
	mvprintw(y + 1, 1, "              6MMMMb\\`MM\\     `M'      dM.    `MM    d'  `MMMMMMMMM            ");
	mvprintw(y + 2, 1, "             6M'    ` MMM\\     M      ,MMb     MM   d'   MM      \\             ");
	mvprintw(y + 3, 1, "\\M\\          MM       M\\MM\\    M      d'YM.    MM  d'    MM                 /M/");
	mvprintw(y + 4, 1, " \\M\\         YM.      M \\MM\\   M     ,P `Mb    MM d'     MM    ,           /M/");
	mvprintw(y + 5, 1, "  \\M\\         YMMMMb  M  \\MM\\  M     d'  YM.   MMd'      MMMMMMM          /M/  ");
	mvprintw(y + 6, 1, "   \\M\\            `Mb M   \\MM\\ M    ,P   `Mb   MMYM.     MM    `         /M/   ");
	mvprintw(y + 7, 1, "   /M/             MM M    \\MM\\M    d'    YM.  MM YM.    MM              \\M\\   ");
	mvprintw(y + 8, 1, "  /M/              MM M     \\MMM   ,MMMMMMMMb  MM  YM.   MM               \\M\\  ");
	mvprintw(y + 9, 1, " /M/         L    ,M9 M      \\MM   d'      YM. MM   YM.  MM      /         \\M\\ ");
	mvprintw(y + 10, 1, "/M/          MYMMMM9 _M_      \\M _dM_     _dMM_MM_   YM._MMMMMMMMM          \\M\\");
	attroff(COLOR_PAIR(3));
}

/* Unused function inherit from IGraph */
void	Graph::SnakeGraph::createMap(void) {}
void	Graph::SnakeGraph::Game(void)  {}
void	Graph::SnakeGraph::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::SnakeGraph::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::SnakeGraph::Animation() {}
void	Graph::SnakeGraph::displayMap(int **ptr){(void)ptr;}

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
