/*
** AracadeCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Mar 24 10:39:17 2017 Guillaume CAUCHOIS
** Last update Fri Mar 24 10:39:17 2017 Guillaume CAUCHOIS
*/

#include "ArcadeCore.hpp"

Arcade::ArcadeCore::ArcadeCore() {}

Arcade::ArcadeCore::ArcadeCore(const Arcade::ArcadeCore &obj)
{
  (void)obj;
}

Arcade::ArcadeCore::~ArcadeCore() {}

Arcade::ArcadeCore	&Arcade::ArcadeCore::operator=(const Arcade::ArcadeCore &obj)
{
  (void)obj;
  return (*this);
}

void		Arcade::ArcadeCore::startCore(void)
{

}