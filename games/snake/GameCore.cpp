/*
** GameCore.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 18:28:26 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 18:28:26 2017 Guillaume CAUCHOIS
*/

#include "GameCore.hpp"

GameCore::GameCore()
{

}

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
