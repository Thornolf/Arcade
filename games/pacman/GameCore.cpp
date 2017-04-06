/*
** GameCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:34:25 2017 Guillaume CAUCHOIS
** Last update Thu Apr 06 18:40:59 2017 Quentin Baudet
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
	Pacman	*pacman = new Pacman();
  ParserMap			*parser;
  Graph::IGraph		*LibGraphic;
  Game::Direction 	dir = Game::UP;
  int				**map;

  parser = new ParserMap(std::string("games/pacman/assets/map.pacman"));
  parser->generateMap();
  LibGraphic = LoaderGraphicLib.getInstance("getInstancePacmanDisplayerMap");
  LibGraphic->displayMap(NULL);
  map = parser->getMap()->getData();
 for (std::string line; std::getline(std::cin, line);) {
 	if (line == "UP")
 		dir = Game::UP;
 	if (line == "DOWN")
 		dir = Game::DOWN;
 	if (line == "LEFT")
 		dir = Game::LEFT;
 	if (line == "RIGHT")
 		dir = Game::RIGHT;
	if (line == "exit")
		break;
   std::cout << "Y: "<< pacman->getY() << " X: " << pacman->getX() << std::endl;
   pacman->movePlayer(map, dir);
   map = parser->getMap()->modifyMap(map, pacman->getY(), pacman->getX(), pacman);
   std::cout << "New score : " << pacman->getScore() << std::endl;
   parser->getMap()->displayMap(map);
   sleep(1); /* !! */
  	}
  /* DISPLAY THE MAP */
  std::cout << pacman->getScore()  << std::endl;
  delete parser;
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
    return ((Game::IGame *)new GameCore());
  }
}
