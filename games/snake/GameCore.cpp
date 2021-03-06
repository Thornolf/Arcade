/*
** GameCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:34:25 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 18:34:25 2017 Guillaume CAUCHOIS
*/

#include "GameCore.hpp"
#include "SnakeCore.hpp"

GameCore::GameCore() {}

GameCore::GameCore(const GameCore &obj)
{
  (void)obj;
}

GameCore::~GameCore() {}

GameCore	&GameCore::operator=(const GameCore &obj)
{
  (void)obj;
  return (*this);
}

void		GameCore::startCore(Arcade::DLLoader<Graph::IGraph> &LoaderGraphicLib)
{
  SnakeCore	SnakeCore;

  try
  {
    SnakeCore.startCore(LoaderGraphicLib);
  }
  catch (const Arcade::ArcadeException &e)
  {
    throw e;
  }

}

/* Unused function pure form IGame */
void		GameCore::movePlayer(std::map<int, std::map<int, int>>) {}
void		GameCore::setX(int) {}
void		GameCore::setY(int) {}
void		GameCore::setState(Game::State) {}
void		GameCore::setSpeed(size_t) {}
void		GameCore::setDirection(Game::Direction) {}
void		GameCore::setLive(bool) {}
int		GameCore::getX(void) const {return (0);}
int		GameCore::getY(void) const {return (0);}
Game::State	GameCore::getState(void) const {return (Game::INVUNERABLE);}
size_t		GameCore::getSpeed(void) const {return (0);}
Game::Direction	GameCore::getDirection(void) const {return (Game::UP);}
int		GameCore::getType(void) const {return (0);}
bool		GameCore::isAlive(void) const {return (false);}
void		GameCore::Dump(void) const {}
int		GameCore::getScore(void) const {return (0);}
void		GameCore::setScore(int) {}

extern "C"
{
  Game::IGame	*getInstanceGame()
  {
    return (new GameCore());
  }
}