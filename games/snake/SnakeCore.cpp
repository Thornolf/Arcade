/*
** SnakeCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 10:59:53 2017 Guillaume CAUCHOIS
** Last update Sun Apr 09 11:28:57 2017 Robin Grattepanche
*/

# include "SnakeCore.hpp"
# include "ncurses/SnakeGraph.hpp"
# include "sfml/SnakeGraph.hpp"

SnakeCore::SnakeCore(void)
{
  this->game = new SnakeGame();
  this->game->setHeight(40);
  this->game->setWidth(100);
  this->food = new SnakePart();
  this->food->setX(0);
  this->food->setY(0);
  for (int i = 0; i < 4; i++)
    this->snake.push_back(new SnakePart(40 + i, 10));
  get = 0;
  direction = 3;
  srand(time(NULL));
}

SnakeCore::SnakeCore(const SnakeCore &obj) : GameCore(obj)
{
  (void)obj;
}

SnakeCore::~SnakeCore(void)
{
  delete this->game;
  delete this->food;
  for (auto it = this->snake.begin(); it != this->snake.end(); ++it)
  {
    delete *it;
  }
}

SnakeCore	&SnakeCore::operator=(const SnakeCore &obj)
{
  (void)obj;
  return (*this);
}

void		SnakeCore::startCore(Arcade::DLLoader<Graph::IGraph> &libraryGraph)
{
  Graph::IGraph	*graph;

  graph = libraryGraph.getInstance("getInstanceSnakeGraph");
  if (!graph->checkSizeWindow(this->game->getWidth(), this->game->getHeight()))
  {
    delete graph;
    throw Arcade::ArcadeException("The window is too small to be displayed correctly");
  }
  (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawScore(this->game->getPoints(), this->game->getWidth());
  (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawMap(this->game->getWidth(), this->game->getHeight(), this->game->getOldalChar());
  this->putFood(graph);
  while(1)
  {
	//   (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawMap(this->game->getWidth(), this->game->getHeight(), this->game->getOldalChar());
	  (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawPlayer(this->getSnakeBody(), this->game->getPartChar());
    if (collision(graph))
    {
      (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawLoose();
      break;
    }
    moveSnake(graph);
    if (direction == 5)
      break;
    usleep(this->game->getDel());
  }
  delete graph;
}

std::vector<Game::IGame *>	SnakeCore::getSnakeBody(void) const
{
  return (this->snake);
}

void		SnakeCore::moveSnake(Graph::IGraph *graph)
{
  direction = (reinterpret_cast<Graph::SnakeGraph*>(graph))->recoverKey();
  if(!get)
    snake.pop_back();
  if(direction == 3)
    snake.insert(snake.begin(), new SnakePart(snake[0]->getX() - 1, snake[0]->getY()));
  else if(direction == 1)
    snake.insert(snake.begin(), new SnakePart(snake[0]->getX() + 1, snake[0]->getY()));
  else if(direction == 0)
    snake.insert(snake.begin(), new SnakePart(snake[0]->getX(), snake[0]->getY() - 1));
  else if(direction == 2)
    snake.insert(snake.begin(), new SnakePart(snake[0]->getX(), snake[0]->getY() + 1));
  (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawPlayer(this->getSnakeBody(), this->game->getPartChar());
}

bool	SnakeCore::collision(Graph::IGraph *graph)
{
  if (snake[0]->getX() == 0 || snake[0]->getX() == this->game->getWidth() - 1 || snake[0]->getY() == 0 || snake[0]->getY() == this->game->getHeight() - 2)
	return true;
  for (size_t i = 2; i < snake.size(); i++)
  {
    if (snake[0]->getX() == snake[i]->getX() && snake[0]->getY() == snake[i]->getY())
	  return true;
  }
  if (snake[0]->getX() == this->food->getX() && snake[0]->getY() == this->food->getY())
  {
    get = true;
    putFood(graph);
    this->game->setPoints(this->game->getPoints() + 10);
    (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawScore(this->game->getPoints(), this->game->getWidth());
    if((this->game->getPoints() % 20) == 0)
      this->game->setDel(this->game->getDel() - 2000);
  }
  else
    get=false;
  return false;
}

void	SnakeCore::putFood(Graph::IGraph *graph)
{
  while(1)
  {
    int tmpx = rand() % this->game->getWidth() + 1;
    int tmpy = rand() % this->game->getHeight() + 1;
    for (size_t i = 0; i < snake.size(); i++)
      if (snake[i]->getX() == tmpx && snake[i]->getY() == tmpy)
	continue;
    if (tmpx >= this->game->getWidth() - 2 || tmpy >= this->game->getHeight() - 3)
      continue;
    this->food->setX(tmpx);
    this->food->setY(tmpy);
    break;
  }
  (reinterpret_cast<Graph::SnakeGraph*>(graph))->drawFood(this->food->getY(), this->food->getX(), this->game->getFoodChar());
}
