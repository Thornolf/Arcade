/*
** main.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Mar 24 09:55:14 2017 Guillaume CAUCHOIS
** Last update Fri Mar 24 09:55:14 2017 Guillaume CAUCHOIS
*/

#include <iostream>
#include "ArcadeCore.hpp"

int		main()
{
  Arcade::ArcadeCore	Core;

  try
  {
    Core.startCore();
  }
  catch (Arcade::ArcadeException &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return (84);
  }
}