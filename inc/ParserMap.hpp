/*
** PaRserMap.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 17:48:29 2017 Quentin Baudet
** Last update Mon Apr 03 22:51:26 2017 Quentin Baudet
*/

#ifndef 	PARSERMAP_HPP
# define 	PARSERMAP_HPP

# include "ArcadeException.hpp"
# include "MapGame.hpp"
# include <iostream>
# include <fstream>
# include <vector>

class ParserMap
{
  public:
    /**
     * Canonical functions
     */
    ParserMap (const std::string &);
    ParserMap (const ParserMap &);
    virtual ~ParserMap ();
    ParserMap	&operator=(const ParserMap &);

    /**
     * Member functions
     */
    void	generateMap(void);
    MapGame	*getMap(void) const;

  private:
    int				_height;
    int				_length;
    std::vector<std::string>	_buffer;
    MapGame			*_map;
};

#endif	/* !PARSERMAP_HPP */
