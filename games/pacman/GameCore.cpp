/*
** GameCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:34:25 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 14:26:07 2017 Quentin Baudet
*/

#include "PacmanDisplayerMap.hpp"
#include "ParserMap.hpp"
#include "MapGame.hpp"
#include "GameCore.hpp"

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
  ParserMap		*parser;
  Graph::IGraph		*LibGraphic;
  int				**tmp;

  parser = new ParserMap(std::string("games/pacman/assets/map.pacman"));
  parser->generateMap();
  LibGraphic = LoaderGraphicLib.getInstance("getInstancePacmanDisplayerMap");
  LibGraphic->displayMap(NULL);
  tmp = parser->getMap()->getData();
  (void)tmp;
  delete parser;
}

/* Unused function pure form IGame */
void		GameCore::move() {}
void		GameCore::setX(int pos) {(void)pos;}
void		GameCore::setY(int pos) {(void)pos;}
void		GameCore::setState(Game::State state) {(void)state;}
void		GameCore::setSpeed(size_t speed) {{(void)speed;}}
int		GameCore::getX() const {return (0);}
int		GameCore::getY() const {return (0);}
Game::State	GameCore::getState() const {return (Game::INVUNERABLE);}
size_t		GameCore::getSpeed() const {return (0);}
bool		GameCore::isAlive() const {return (false);}
void		GameCore::Dump(void) const {}

extern "C"
{
  Game::IGame	*getInstanceGame()
  {
    return ((Game::IGame *)new GameCore());
  }
}
