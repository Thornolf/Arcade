/*
** DLLoader.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Mar 30 16:31:23 2017 Guillaume CAUCHOIS
** Last update Thu Mar 30 16:31:23 2017 Guillaume CAUCHOIS
*/

#ifndef		_CPP_ARCADE_DLLOADER__HPP_
#define		_CPP_ARCADE_DLLOADER__HPP_

# include <string>
# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif /* !_GNU_SOURCE */
# include <dlfcn.h>
# include "IGraph.hpp"
# include "GraphicMenu.hpp"
# include "ArcadeException.hpp"

namespace Arcade
{
  template <class T>
  class DLLoader
  {
    public:
      /* Canonical Functions */
      DLLoader(char *);
      virtual ~DLLoader();
      DLLoader(const DLLoader<T> &);
      DLLoader<T>	&operator=(const DLLoader<T> &);

      /* Member functions */
      T*	getInstance(const std::string &);
    private:
      T*			_instance;
      void*			_handler;
  };
}

#endif		/* !_CPP_ARCADE_DLLOADER_HPP_ */
