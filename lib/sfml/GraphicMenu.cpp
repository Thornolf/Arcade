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

GraphicMenu::GraphicMenu() {}

GraphicMenu::GraphicMenu(const GraphicMenu &obj)
{
  (void)obj;
}
GraphicMenu::~GraphicMenu() {}

GraphicMenu	&GraphicMenu::operator=(const GraphicMenu &obj)
{
  (void)obj;
  return (*this);
}