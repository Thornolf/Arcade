/*
** AracadeCore.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Mar 24 10:28:34 2017 Guillaume CAUCHOIS
** Last update Fri Mar 24 10:28:34 2017 Guillaume CAUCHOIS
*/

#ifndef		_ARCADE_CORE__HPP_
# define	_ARCADE_CORE__HPP_

# define	MAX_GET_LIBRARY (5)

# define	LIBRARY_GAME_DIRECTORY "games/"
# define	LIBRARY_GRAPHIC_DIRECTORY "lib/"

# include <iostream>
# include <string>
# include <vector>
# include <dirent.h>
# include <regex>
# include <sstream>
# include <dlfcn.h>

# include "ArcadeException.hpp"
# include "DLLoader.hpp"
# include "../src/DLLoader.cpp"
# include "IGraph.hpp"
# include "IGame.hpp"
# include "GameCore.hpp"

namespace Arcade
{
  class ArcadeCore
  {
    public:
      /* Canonical functions */
      ArcadeCore();
      ArcadeCore(const ArcadeCore &);
      virtual ~ArcadeCore();
      ArcadeCore	&operator=(const ArcadeCore &);

      /* Member functions */
      void				startCore(const std::string &);
      void				FindLibraries(void);
      const std::vector<std::string>	getListDynamicLibrary(const std::string &);

    private:
      /* Member Functions */
      bool	isDynamicLibraryFilename(const std::string &);

    private:
      std::vector<std::string>	_listGames;
      std::vector<std::string>	_listGraphic;
  };
}

#endif		/* !_ARCADE_CORE__HPP_ */
