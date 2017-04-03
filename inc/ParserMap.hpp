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

# include <iostream>
# include <fstream>

class ParserMap
{
  public:
    /**
     * Canonical function
     */
    ParserMap ();
    ParserMap (const ParserMap &);
    virtual ~ParserMap ();
    ParserMap	&operator=(const ParserMap &);

    /**
     * Member Functions
     */
     /* GETTER */
    int		getMapHeight() const;
    int		getMapLength() const;

    /* SETTER */
    void	setMapHeight(int);
    void	setMapLength(int);

    /* Get Info from cnf */
    void 	setMapIntel(std::string);

  private:
    int		_mapHeight;
    int		_mapLength;
};

#endif	/* !PARSERMAP_HPP */
