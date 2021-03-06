/*
** DLLoader.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Mar 30 16:35:05 2017 Guillaume CAUCHOIS
** Last update Thu Mar 30 16:35:05 2017 Guillaume CAUCHOIS
*/

#include "DLLoader.hpp"

template <class T>
Arcade::DLLoader<T>::DLLoader(const std::string &path_lib)
{
  if (!(this->_handler = dlopen(path_lib.c_str(), RTLD_LAZY)))
    throw Arcade::ArcadeException(dlerror());
}

template <class T>
Arcade::DLLoader<T>::DLLoader(const Arcade::DLLoader<T> &) {}

template <class T>
Arcade::DLLoader<T>::~DLLoader()
{
  if (this->_handler)
    dlclose(this->_handler);
}

template <class T>
Arcade::DLLoader<T>	&Arcade::DLLoader<T>::operator=(const Arcade::DLLoader<T> &)
{
  return (*this);
}

template <class T>
T*	Arcade::DLLoader<T>::getInstance(const std::string &symbname)
{
  void	*symb;
  T	*(*ptr)(void);

  if (!(symb = dlsym(this->_handler, symbname.c_str())))
    throw Arcade::ArcadeException("Cannot find the symbol : " + symbname);
  ptr = reinterpret_cast<T*(*)(void)>(symb);
  return (ptr());
}