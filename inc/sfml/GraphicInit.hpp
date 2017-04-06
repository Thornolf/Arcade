/*
** GraphicInit.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 16:41:34 2017 Guillaume CAUCHOIS
** Last update Wed Apr 05 16:41:34 2017 Guillaume CAUCHOIS
*/

#ifndef		_GRAPHIC_INIT__HPP_
# define	_GRAPHIC_INIT__HPP_

# include "IGraph.hpp"
# include "ArcadeException.hpp"
# include <string>
# include <ncurses.h>
# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>

namespace Graph
{
  class GraphicInit : public Graph::IGraph
  {
    public:
      /* Canonical form */
      GraphicInit(const std::string &);
      GraphicInit(const GraphicInit &);
      virtual ~GraphicInit();
      GraphicInit	&operator=(const GraphicInit &);

      /* Membre Function */
      sf::RenderWindow	*getWindow(void);


      /* Unused pure methods */
      void	createMap();
      void	Game();
      void	SetSprite(int, int, Game::IGame *);
      void	UnsetSprite(int, int, Game::IGame *);
      void	Animation();
      void	displayMap(int **);
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);

    private:
      sf::RenderWindow	*_window;
  };
}

#endif		/* !_GRAPHIC_INIT__HPP_ */