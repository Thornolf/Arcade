/*
** SnakeGraph.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Apr 06 12:34:11 2017 Guillaume CAUCHOIS
** Last update Sun Apr 09 11:29:41 2017 Robin Grattepanche
*/

#include "sfml/GraphicInit.hpp"
#include "sfml/SnakeGraph.hpp"

Graph::SnakeGraph::SnakeGraph()
{
  this->_key	= 3;
  this->_init	= new Graph::GraphicInit("GAME-OVER ARCADE | SNAKE");
}

Graph::SnakeGraph::SnakeGraph(const Graph::SnakeGraph &obj)
{
	(void)obj;
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
	(void)height;
	(void)width;
	(void)wallChar;
	sf::RectangleShape rectUp(sf::Vector2f(1000, 20));
	rectUp.setFillColor(sf::Color(255, 10, 10));
	this->_init->getWindow()->draw(rectUp);

	sf::RectangleShape rectLeft(sf::Vector2f(20, 400));
	rectLeft.setFillColor(sf::Color(255, 10, 10));
	this->_init->getWindow()->draw(rectLeft);

	sf::RectangleShape rectDown(sf::Vector2f(1000, 20));
	rectDown.setFillColor(sf::Color(255, 10, 10));
	rectDown.setPosition(0, 400);
	this->_init->getWindow()->draw(rectDown);

	sf::RectangleShape rectRight(sf::Vector2f(20, 400));
	rectRight.setFillColor(sf::Color(255, 10, 10));
	rectRight.setPosition(1000, 0);
	this->_init->getWindow()->draw(rectRight);

	// this->_init->getWindow()->display();
}
void	Graph::SnakeGraph::drawPlayer(std::vector<Game::IGame*> snake, char partChar)
{
	(void)partChar;
	for (size_t i = 0; i < snake.size(); i++)
	{
		sf::RectangleShape part(sf::Vector2f(20, 20));
		part.setFillColor(sf::Color(15, 250, 10));
		part.move(snake[i]->getX() * 10, snake[i]->getY() * 10);
		this->_init->getWindow()->draw(part);
	}
	sf::RectangleShape partEnd(sf::Vector2f(20, 20));
	partEnd.move(snake[snake.size() - 1]->getX() * 10, snake[snake.size() - 1]->getY() * 10);
	partEnd.setFillColor(sf::Color(0, 0, 0));
	this->_init->getWindow()->draw(partEnd);
	this->_init->getWindow()->display();
}

void	Graph::SnakeGraph::drawFood(int y, int x, char foodChar)
{
	(void)foodChar;
	sf::RectangleShape food(sf::Vector2f(20, 20));
	food.setFillColor(sf::Color(150, 150, 20));
	food.setPosition(x * 10, y * 10);
	this->_init->getWindow()->draw(food);
	this->_init->getWindow()->display();
}

int		Graph::SnakeGraph::recoverKey(void)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (this->_key != 2)
			this->_key = 0;
		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (this->_key != 3)
				this->_key = 1;
		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (this->_key != 0)
				this->_key = 2;
		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (this->_key != 1)
				this->_key = 3;
		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->_key = 5;
	return (this->_key);
}
/* Need be implemented */
void	Graph::SnakeGraph::drawScore(int, int) {}
void	Graph::SnakeGraph::drawLoose(void) {}

/* Unused function inherit from IGraph */
void	Graph::SnakeGraph::createMap(void) {}
void	Graph::SnakeGraph::Game(void)  {}
void	Graph::SnakeGraph::SetSprite(int, int, Game::IGame *)  {}
void	Graph::SnakeGraph::UnsetSprite(int, int, Game::IGame *)  {}
void	Graph::SnakeGraph::Animation() {}
void	Graph::SnakeGraph::displayMap(int **){}
void	Graph::SnakeGraph::displayMap(int **, int, int, int) {}
bool	Graph::SnakeGraph::checkSizeWindow(int, int) {return (true);}

std::pair<std::string, std::string>	Graph::SnakeGraph::startMenu(const std::vector<std::string> &, const std::vector<std::string> &)
{
  return (std::make_pair("", ""));
}

extern "C"
{
  Graph::IGraph*	getInstanceSnakeGraph()
  {
    return (reinterpret_cast<Graph::IGraph*>(new Graph::SnakeGraph()));
  }
}
