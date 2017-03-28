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
# include	"ArcadeException.hpp"

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
      void		startCore(void);
  };
}

#endif		/* !_ARCADE_CORE__HPP_ */
