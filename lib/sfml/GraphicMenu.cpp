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

std::string	Graph::GraphicMenu::startMenu(const std::string &title, const std::vector<std::string> &listItems) const
{
  (void)title;
  (void)listItems;
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	window.close();
    }
    window.clear();
    window.display();
  }
  return (std::string());
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