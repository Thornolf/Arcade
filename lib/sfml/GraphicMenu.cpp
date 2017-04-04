/*
** GraphicMenu.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
*/

#include <cstring>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <menu.h>
#include "GraphicMenu.hpp"

Graph::GraphicMenu::GraphicMenu() {}

Graph::GraphicMenu::GraphicMenu(const Graph::GraphicMenu &obj)
{
  (void)obj;
}

Graph::GraphicMenu::~GraphicMenu() {}

Graph::GraphicMenu	&Graph::GraphicMenu::operator=(const Graph::GraphicMenu &obj)
{
  (void)obj;
  return (*this);
}

void	Graph::GraphicMenu::SetLibraryChoices(const std::vector<std::string> &ListGraphics)
{
  this->_choicesLibraries = ListGraphics;
}

void	Graph::GraphicMenu::displayRulesMenu(void) const
{
  /**
   mvprintw(6, 3, "1- Select the graphic library to use for the display");
  mvprintw(7, 3, "2- Select the game to play");
  mvprintw(8, 3, "3- Play!");
  mvprintw(LINES - 2, 0, "Press ESC to exit");
   */
}

std::pair<std::string, std::string>	Graph::GraphicMenu::startMenu(const std::vector<std::string> &listGraphics, const std::vector<std::string> &listGames) const{
  (void)listGraphics;
  (void)listGames;
  sf::RenderWindow	window(sf::VideoMode(1280, 720), "ARCADE - C++ 2020");
  sf::Texture		texture_bg;
  sf::Sprite		sprite_bg;
  sf::Texture		texture_logo;
  sf::Sprite		sprite_logo;
  int			alpha = 170;
  int			cursorSpeedFadeEffect = 0;
  int			cursorFadeEffect = 1;

  if (!texture_bg.loadFromFile("assets/img/bg_menu.png"))
    throw Arcade::ArcadeException("Cannot load the background");
  else if (!texture_logo.loadFromFile("assets/img/logo.png"))
    throw Arcade::ArcadeException("Cannot load the logo");
  texture_logo.setSmooth(true);
  sprite_bg.setTexture(texture_bg);
  sprite_logo.setTexture(texture_logo);
  sprite_bg.setScale(0.6667, 0.6667);
  sprite_logo.setScale(0.8, 0.8);
  sprite_logo.setPosition(50, 100);
  while (window.isOpen())
  {
    sprite_logo.setColor(sf::Color(255, 255, 255, alpha)); // à moitié transparent
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    window.clear();
    window.draw(sprite_bg);
    window.draw(sprite_logo);
    window.display();
    if (cursorSpeedFadeEffect >= SFML_LOGO_FADE_EFFECT_SPEED)
    {
      cursorSpeedFadeEffect = 0;
      alpha += cursorFadeEffect;
      cursorFadeEffect = (alpha == 255) ? -1 : cursorFadeEffect;
      cursorFadeEffect = (alpha == 150) ? 1 : cursorFadeEffect;
    }
    cursorSpeedFadeEffect++;
  }
  return (std::make_pair("lib_arcade_ncurses.so", "lib_arcade_pacman.so"));
}

extern "C"
{
Graph::IGraph	*getInstanceGraphicMenu()
{
  return (new Graph::GraphicMenu());
}
}

/* Unused pure methods */
void	Graph::GraphicMenu::createMap(void) {}
void	Graph::GraphicMenu::Game(void)  {}
void	Graph::GraphicMenu::SetSprite(int x, int y)  {(void)x; (void)y;}
void	Graph::GraphicMenu::UnsetSprite(int x, int y) {(void)x; (void)y;}
void	Graph::GraphicMenu::Animation() {}