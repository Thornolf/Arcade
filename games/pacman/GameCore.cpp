/*
** GameCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:34:25 2017 Guillaume CAUCHOIS
** Last update Sun Apr 09 17:11:59 2017 Quentin Baudet
*/

#include "PacmanDisplayerMap.hpp"
#include "ParserMap.hpp"
#include "MapGame.hpp"
#include "GameCore.hpp"
#include "APCharacter.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include <unistd.h>

GameCore::GameCore() {}

GameCore::GameCore(const GameCore &) {}

GameCore::~GameCore() {}

GameCore	&GameCore::operator=(const GameCore &)
{
  return (*this);
}

void		GameCore::startCore(Arcade::DLLoader<Graph::IGraph> &LoaderGraphicLib)
{
  Pacman	*pacman = new Pacman("Pacman", 1, 10, 15);
  Ghost	*blinky = new Ghost("Blinky", 2, 9, 12);
  ParserMap			*parser;
  Graph::IGraph		*LibGraphic;
  Game::Direction 	dir = Game::UP;
  int				**map;

  parser = new ParserMap(std::string("games/pacman/assets/map.pacman"));
  parser->generateMap();
  LibGraphic = LoaderGraphicLib.getInstance("getInstancePacmanDisplayerMap");
  map = parser->getMap()->getData();
  LibGraphic->displayMap(map, parser->getMap()->getMapHeight(), parser->getMap()->getMapLength(), pacman->getScore());
  pacman->setPacgum(parser->getMap()->getAmountPacGum() - 1);
  while (1)
  {
    if (pacman->getPacgum() == 0)
      break;
    if (LibGraphic->recoverKey() == 0)
      dir = Game::UP;
    else if (LibGraphic->recoverKey() == 1)
      dir = Game::RIGHT;
    else if (LibGraphic->recoverKey() == 2)
      dir = Game::DOWN;
    else if (LibGraphic->recoverKey() == 3)
      dir = Game::LEFT;
    else if (LibGraphic->recoverKey() == 4)
      break;
    pacman->movePlayer(map, dir);

	blinky->movePlayer(map, Game::UP);
    map = parser->getMap()->modifyMap(map, pacman->getY(), pacman->getX(), pacman);
    LibGraphic->displayMap(map, parser->getMap()->getMapHeight(), parser->getMap()->getMapLength(), pacman->getScore());
    usleep(120000);
  }
  delete blinky;
  delete parser;
  delete pacman;
  delete LibGraphic;
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
