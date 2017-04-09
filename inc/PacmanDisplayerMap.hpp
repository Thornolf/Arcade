/*
** PacmanDisplayerMap.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Tue Apr 04 16:13:06 2017 Guillaume CAUCHOIS
** Last update Fri Apr 07 13:09:46 2017 Quentin Baudet
*/

#ifndef		_PACMAN_DISPLAYER_MAP__HPP_
# define	_PACMAN_DISPLAYER_MAP__HPP_

# include "IGraph.hpp"
# include "ArcadeException.hpp"
# include "ncurses/GraphicInit.hpp"

namespace Graph
{
  class PacmanDisplayerMap : public Graph::IGraph
  {
    private:
      int					_key;
      Graph::GraphicInit	*_init;
    public:
      /* Canonical Functions */
      PacmanDisplayerMap();
      virtual ~PacmanDisplayerMap();
      PacmanDisplayerMap(const PacmanDisplayerMap &);
      PacmanDisplayerMap	&operator=(const PacmanDisplayerMap &);

      int					recoverKey(void);
      bool					checkSizeWindow(int x, int y);
      void					displayMap(int **);
      void					displayMap(int **, int, int);
      void 					drawElem(char, int, int);

      /* Unused Methods from Graph::IGraph */
      void					createMap();
      void					Game();
      void					SetSprite(int x, int y, Game::IGame *);
      void					UnsetSprite(int x, int y, Game::IGame *);
      void					Animation();
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
      void					drawMap(int, int, char);
      void					drawPlayer(std::vector<Game::IGame*>, char);
      void					drawScore(int, int);
      void					drawFood(int, int, char);
      void					drawLoose(void);
  };
}

#endif		/* !_PACMAN_DISPLAYER_MAP__HPP_ */
