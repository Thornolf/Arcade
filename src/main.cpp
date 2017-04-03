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

void		show_usage(const char *binaryName)
{
  std::cerr << "USAGE:" << std::endl;
  std::cerr << "\t" << binaryName << " path_to_graphic_lib" << std::endl;
  std::cerr << "DESCRIPTION:" << std::endl;
  std::cerr << "\t" << "path_to_graphic_lib" << "\t";
  std::cerr << "path to a compatible graphic library" << std::endl;
}

int		main(int argc, char **argv)
{
  Arcade::ArcadeCore	Core;

  if (argc < 2)
  {
    show_usage(argv[0]);
    return (84);
  }
  try
  {
    Core.startCore(std::string(argv[1]));
  }
  catch (Arcade::ArcadeException &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return (84);
  }
}