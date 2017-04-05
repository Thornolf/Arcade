/*
** SnakeCore.cpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/inc/SnakeCore.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 10:59:53 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 10:59:53 2017 Guillaume CAUCHOIS
*/

#include "SnakeCore.hpp"

SnakeCore::SnakeCore(void) : GameCore()
{
  initscr();
  nodelay(stdscr,true);
  keypad(stdscr,true);
  noecho();
  start_color();
  curs_set(0);
  this->game = new SnakeGame();
  this->game->setHeight(40);
  this->game->setWidth(100);
  food.setX(0);
  food.setY(0);
  for (int i = 0; i < 3; i++)
    snake.push_back(SnakePart(40 + i, 10));
  get=0;
  direction='l';
  srand(time(NULL));
  putfood();
  //up-horizontal
  init_pair(1, COLOR_RED, COLOR_RED);
  attron(COLOR_PAIR(1));
  for(int i = 0; i < this->game->getWidth() - 1; i++)
  {
    move(0, i);
    addch(this->game->getOldalChar());
  }
  //left-vertical
  for(int i = 0; i < this->game->getHeight() - 1; i++)
  {
    move(i, 0);
    addch(this->game->getOldalChar());
    // addch('b');
  }
  //down-horizontal
  for(int i = 0; i < this->game->getWidth() - 1; i++)
  {
    move(this->game->getHeight() - 2, i);
    addch(this->game->getOldalChar());
    // addch('c');
  }
  //right-vertical
  for(int i = 0; i < this->game->getHeight() - 1; i++)
  {
    move(i, this->game->getWidth() - 2);
    addch(this->game->getOldalChar());
  }
  attroff(COLOR_PAIR(1));
  // draw the snake
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  attron(COLOR_PAIR(2));
  for(size_t i = 0; i < snake.size(); i++)
  {
    move(snake[i].getY(), snake[i].getX());
    addch(this->game->getOldalChar());
  }
  attroff(COLOR_PAIR(2));
  move(20, this->game->getWidth() + 3);
  printw(" Score : %d", this->game->getPoints());
  move(food.getY(), food.getX());
  addch(this->game->getFoodChar());
  refresh();
}

SnakeCore::SnakeCore(const SnakeCore &obj) : GameCore(obj)
{
  (void)obj;
}

SnakeCore::~SnakeCore(void)
{
  nodelay(stdscr, false);
  getch();
  endwin();
}

SnakeCore	&SnakeCore::operator=(const SnakeCore &obj)
{
  (void)obj;
  return (*this);
}

void		SnakeCore::startCore(Arcade::DLLoader<Graph::IGraph> &)
{
  while(1)
  {
    if(collision())
    {
      move(12,36);
      printw("game_over");
      break;
    }
    movesnake();
    if(direction=='q')
      break;
    usleep(this->game->getDel());
  }
}


void		SnakeCore::movesnake(void)
{
  int tmp = getch();
  switch(tmp)
  {
    case KEY_LEFT:
      if(direction!='r')
	direction='l';
      break;
    case KEY_UP:
      if(direction!='d')
	direction='u';
      break;
    case KEY_DOWN:
      if(direction!='u')
	direction='d';
      break;
    case KEY_RIGHT:
      if(direction!='l')
	direction='r';
      break;
    case 27:
      direction='q';
      break;
  }
  attron(COLOR_PAIR(2));
  if(!get)
  {
    move(snake[snake.size() - 1].getY(), snake[snake.size() - 1].getX());
    printw(" ");
    refresh();
    snake.pop_back();
  }
  if(direction=='l')
  {
    snake.insert(snake.begin(),SnakePart(snake[0].getX() - 1, snake[0].getY()));
  }else if(direction=='r'){
    snake.insert(snake.begin(),SnakePart(snake[0].getX() + 1, snake[0].getY()));

  }else if(direction=='u'){
    snake.insert(snake.begin(),SnakePart(snake[0].getX(), snake[0].getY() - 1));
  }else if(direction=='d'){
    snake.insert(snake.begin(),SnakePart(snake[0].getX(), snake[0].getY() + 1));
  }
  move(snake[0].getY(), snake[0].getX());
  addch(this->game->getPartChar());
  attroff(COLOR_PAIR(2));
  refresh();
}

bool	SnakeCore::collision()
{
  if(snake[0].getX() == 0 || snake[0].getX() == this->game->getWidth() - 1 || snake[0].getY() == 0 || snake[0].getY() == this->game->getHeight() - 2)
    return true;
  for(size_t i = 2; i < snake.size(); i++)
  {
    if(snake[0].getX() == snake[i].getX() && snake[0].getY() == snake[i].getY())
      return true;
  }
  //collision with the food
  if(snake[0].getX() == food.getX() && snake[0].getY() == food.getY())
  {
    get = true;
    putfood();
    this->game->setPoints(this->game->getPoints() + 10);
    move(this->game->getHeight() - 1, 0);
    printw("Score : %d", this->game->getPoints());
    if((this->game->getPoints() % 50) == 0)
      // del -= 10000;
      this->game->setDel(this->game->getDel() - 10000);
  }
  else
    get=false;
  return false;
}

void	SnakeCore::putfood()
{
  while(1)
  {
    int tmpx = rand() % this->game->getWidth() + 1;
    int tmpy = rand() % this->game->getHeight() + 1;
    for (size_t i = 0; i < snake.size(); i++)
      if (snake[i].getX() == tmpx && snake[i].getY() == tmpy)
	continue;
    if (tmpx >= this->game->getWidth() - 2 || tmpy >= this->game->getHeight() - 3)
      continue;
    food.setX(tmpx);
    food.setY(tmpy);
    break;
  }
  move(food.getY(), food.getX());
  addch(this->game->getFoodChar());
  refresh();
}
