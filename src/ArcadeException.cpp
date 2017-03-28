/*
** ArcadeException.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Mar 24 10:07:44 2017 Guillaume CAUCHOIS
** Last update Fri Mar 24 10:07:47 2017 Guillaume CAUCHOIS
*/

#include "ArcadeException.hpp"

Arcade::ArcadeException::ArcadeException(std::string errorMsg) throw() : _errorMessage(errorMsg) {}

const char	*Arcade::ArcadeException::what() const throw()
{
  return (this->_errorMessage.c_str());
}