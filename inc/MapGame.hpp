/*
** MapGame.hpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/inc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 18:06:09 2017 Quentin Baudet
** Last update Thu Apr 06 22:19:16 2017 Quentin Baudet
*/

#ifndef		MAPGAME_HPP
# define	MAPGAME_HPP

# include <iostream>
# include <fstream>
# include "Pacman.hpp"
# include "Ghost.hpp"

class MapGame
{
  public:
    /* Canonical functions */

    MapGame(int, int);
    MapGame(const MapGame &);
    virtual ~MapGame () {}
    MapGame		&operator=(const MapGame &);

    /* Member functions */
    int		getMapHeight() const;
    int		getMapLength() const;
    void	setData(int **newData);
    int**	getData() const;
	void	fillUpData(int, const std::string &);
	void 	displayMap(int**) const;
	int 	**modifyMap(int**, int, int, Pacman* );
	int 	**modifyMap(int**, int, int, Ghost* );

  private:
    void	setMapHeight(int);
    void	setMapLength(int);

  private:
    int**		_data;
    int			_height;
    int			_length;
};

#endif /* !MapGame_HPP */
