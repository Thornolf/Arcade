/*
** SnakeGraph.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Apr 06 12:34:11 2017 Guillaume CAUCHOIS
** Last update Fri Apr 07 17:12:40 2017 Robin Grattepanche
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
	mvprintw(y, 5, "               .M\"\"\"bgd `7MN.   `7MF'     db      `7MMF' `YMM' `7MM\"\"\"YMM");
	mvprintw(y + 1, 5, "`\\\\.          ,MI    \"Y   MMN.    M      ;MM:       MM   .M'     MM    `7           ,;//'");
	mvprintw(y + 2, 5, "   `\\\\:.      `MMb.       M YMb   M     ,V^MM.      MM .d\"       MM   d          ,;//'");
	mvprintw(y + 3, 5, "      `\\\\.      `YMMNq.   M  `MN. M    ,M  `MM      MMMMM.       MMmmMM        ,//'");
	mvprintw(y + 4, 5, "     ,;//'    .     `MM   M   `MM.M    AbmmmqMA     MM  VMA      MM   Y  ,     `\\\\.");
	mvprintw(y + 5, 5, "  ,;//'       Mb     dM   M     YMM   A'     VML    MM   `MM.    MM     ,M        `\\\\:.");
	mvprintw(y + 6, 5, ",//'          P\"Ybmmd\"  .JML.    YM .AMA.   .AMMA..JMML.   MMb..JMMmmmmMMM           `\\\\.");
	attroff(COLOR_PAIR(3));
}

/* Unused function inherit from IGraph */
void	Graph::SnakeGraph::createMap(void) {}
void	Graph::SnakeGraph::Game(void)  {}
void	Graph::SnakeGraph::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::SnakeGraph::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::SnakeGraph::Animation() {}
void	Graph::SnakeGraph::displayMap(int **ptr){(void)ptr;}
void	Graph::SnakeGraph::displayMap(int **, int, int) {}

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
    return (reinterpret_cast<Graph::IGraph*>(new Graph::SnakeGraph()));
  }
}
