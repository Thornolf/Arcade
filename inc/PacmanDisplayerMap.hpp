/*
** PacmanDisplayerMap.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Apr 04 16:13:06 2017 Guillaume CAUCHOIS
** Last update Tue Apr 04 16:13:06 2017 Guillaume CAUCHOIS
*/

#ifndef		_PACMAN_DISPLAYER_MAP__HPP_
# define	_PACMAN_DISPLAYER_MAP__HPP_

# include "IGraph.hpp"
# include "ArcadeException.hpp"

namespace Graph
{
  class PacmanDisplayerMap : public Graph::IGraph
  {
    public:
      /* Canonical Functions */
      PacmanDisplayerMap();
      virtual ~PacmanDisplayerMap();
      PacmanDisplayerMap(const PacmanDisplayerMap &);
      PacmanDisplayerMap	&operator=(const PacmanDisplayerMap &);

      /* Unused Methods from Graph::IGraph */
      void					createMap();
      void					Game();
      void					SetSprite(int x, int y, Game::IGame *);
      void					UnsetSprite(int x, int y, Game::IGame *);
      void					Animation();
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);

      void	displayMap(int **);
  };
}

#endif		/* !_PACMAN_DISPLAYER_MAP__HPP_ */