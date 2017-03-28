/*
** ArcadeException.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Mar 24 10:04:35 2017 Guillaume CAUCHOIS
** Last update Fri Mar 24 10:04:35 2017 Guillaume CAUCHOIS
*/

#ifndef		_ARCADE_EXCEPTION__HPP_
# define	_ARCADE_EXCEPTION__HPP_

#include <exception>
#include <string>

namespace Arcade
{
  class ArcadeException : public std::exception
  {
    public:
      ArcadeException(std::string error) throw();
      virtual ~ArcadeException() throw() {};
      virtual const char *what() const throw();

    private:
      const std::string	_errorMessage;
  };
}



#endif /* !CPP_ARCADE_ARCADEEXCEPTION_HPP_ */
