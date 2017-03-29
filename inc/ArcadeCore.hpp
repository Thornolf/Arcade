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

# define	LIBRARY_GAME_DIRECTORY "games/"
# define	LIBRARY_GRAPHIC_DIRECTORY "lib/"

# include <iostream>
# include <string>
# include <vector>
# include <dirent.h>
# include <regex>
# include <sstream>
# include "ArcadeException.hpp"

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
      void				startCore(void);
      const std::vector<std::string>	getListDynamicLibrary(const std::string &);
    public:
      /* Member Functions */
      bool	isDynamicLibraryFilename(const std::string &);
  };
}

#endif		/* !_ARCADE_CORE__HPP_ */
