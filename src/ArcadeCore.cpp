/*
** ArcadeCore.cpp for cpp_arcade
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

bool	Arcade::ArcadeCore::isDynamicLibraryFilename(const std::string &filename)
{
  if (std::regex_match(filename, std::regex(".*(.so)$")))
    return true;
  return false;
}

std::string	ctostring(const char *c_str)
{
  std::stringstream	sstream;

  sstream << c_str;
  return (sstream.str());
}

const std::vector<std::string>	Arcade::ArcadeCore::getListDynamicLibrary(const std::string &path)
{
  std::vector<std::string>	list;
  DIR				*directory;
  struct dirent			*file_dirent;
  std::string			filename;

  if (!(directory = opendir(path.c_str())))
    throw Arcade::ArcadeException("Cannot access to the library directory");
  while ((file_dirent = readdir(directory)))
  {
    filename = ctostring(file_dirent->d_name);
    if (this->isDynamicLibraryFilename(filename.c_str()))
      list.push_back(filename);
  }
  if (closedir(directory) == -1)
    throw Arcade::ArcadeException("Cannot close the library directory");
  return (list);
}

void	Arcade::ArcadeCore::FindLibraries(void)
{
  try
  {
    this->_listGames = this->getListDynamicLibrary(LIBRARY_GAME_DIRECTORY);
    this->_listGraphic = this->getListDynamicLibrary(LIBRARY_GRAPHIC_DIRECTORY);
  }
  catch (const Arcade::ArcadeException &e)
  {
    std::cerr << e.what() << std::endl;
    return;
  }
}

void	Arcade::ArcadeCore::startCore(const char *library_menu_path)
{
  Arcade::DLLoader<Graph::IGraph>	*LibraryLoader;
  Graph::IGraph				*GraphicLib;
  std::string				libpath;

  LibraryLoader = new Arcade::DLLoader<Graph::IGraph>(library_menu_path);
  libpath = ctostring(library_menu_path);
  this->FindLibraries();
  GraphicLib = LibraryLoader->getInstance("instanceGraphicMenu");
  if (GraphicLib == NULL)
    throw (Arcade::ArcadeException("Cannot make instance of ncurses from this library"));
  GraphicLib->startMenu();
  delete LibraryLoader;
}