/*
** GameCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:34:25 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 17:36:52 2017 Quentin Baudet
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
  Pacman	*pacman = new Pacman();
  // Ghost	*blinky = new Ghost("Blinky", 2, 11, 12);
  // Ghost	*pinky = new Ghost("Pinky", 2, 12, 12);
  // Ghost	*clyde = new Ghost("Clyde", 2, 11, 13);
  // Ghost	*inky = new Ghost("Inky", 2, 10, 13);

  ParserMap			*parser;
  Graph::IGraph		*LibGraphic;
  Game::Direction 	dir = Game::UP;
  int				**map;
  // (void)blinky;
  // (void)pinky;
  // (void)clyde;
  // (void)inky;

  parser = new ParserMap(std::string("games/pacman/assets/map.pacman"));
  parser->generateMap();

  LibGraphic = LoaderGraphicLib.getInstance("getInstancePacmanDisplayerMap");
  // LibGraphic->displayMap(parser->getMap()->getData());

  map = parser->getMap()->getData();

  // for (std::string line; std::getline(std::cin, line);) {
  // 	if (line == "UP")
  // 		dir = Game::UP;
  // 	if (line == "DOWN")
  // 		dir = Game::DOWN;
  // 	if (line == "LEFT")
  // 		dir = Game::LEFT;
  // 	if (line == "RIGHT")
  // 		dir = Game::RIGHT;
  // if (line == "exit")
  // 	break;


  /* DISPLAY in TERMINAL */
  	LibGraphic->displayMap(map, parser->getMap()->getMapHeight(), parser->getMap()->getMapLength(), pacman->getScore());
	// for (int i = 0; i < 10; i++)
	pacman->setPacgum(parser->getMap()->getAmountPacGum() - 1);
	while (1)
	{
		if (pacman->getPacgum() == 0) {
			break;
		}
		if (LibGraphic->recoverKey() == 0)
		dir = Game::UP;
		else if (LibGraphic->recoverKey() == 1)
		dir = Game::RIGHT;
		else if (LibGraphic->recoverKey() == 2)
		dir = Game::DOWN;
		else if (LibGraphic->recoverKey() == 3)
		dir = Game::LEFT;
		pacman->movePlayer(map, dir);
		map = parser->getMap()->modifyMap(map, pacman->getY(), pacman->getX(), pacman);
	    LibGraphic->displayMap(map, parser->getMap()->getMapHeight(), parser->getMap()->getMapLength(), pacman->getScore());
 		usleep(120000);

 	}
  /* DISPLAY THE MAP */
  // delete blinky;
  // delete pinky;
  // delete clyde;
  // delete inky;
  // delete parser;
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
