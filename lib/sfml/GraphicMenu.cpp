/*
** GraphicMenu.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
*/

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

const char*	Graph::GraphicMenu::startMenu(const std::string &title, const std::vector<std::string> &listItems) const
{
  (void)title;
  (void)listItems;
  return (NULL);
}

