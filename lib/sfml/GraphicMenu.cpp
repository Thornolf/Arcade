/*
** GraphicMenu.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 14:53:23 2017 Quentin Baudet
*/

#include "GraphicMenu.hpp"
#include "sfml/GraphicInit.hpp"

Graph::GraphicMenu::GraphicMenu() {}

Graph::GraphicMenu::GraphicMenu(const Graph::GraphicMenu &obj)
{
  (void)obj;
}

Graph::GraphicMenu::~GraphicMenu() {}

Graph::GraphicMenu	&Graph::GraphicMenu::operator=(const Graph::GraphicMenu &)
{
  return (*this);
}

void	Graph::GraphicMenu::SetLibraryChoices(const std::vector<std::string> &ListGraphics)
{
  this->_choicesLibraries = ListGraphics;
}

void	Graph::GraphicMenu::displayRulesMenu(void) const
{
  /**
   mvprintw(6, 3, "1- Select the graphic library to use for the display");
  mvprintw(7, 3, "2- Select the game to play");
  mvprintw(8, 3, "3- Play!");
  mvprintw(LINES - 2, 0, "Press ESC to exit");
   */
}

void	Graph::GraphicMenu::LaunchMenuSound(sf::Music &music, const std::string &filepath) const
{
  sf::Time	offset_music = sf::seconds(15.8f);

  if (!music.openFromFile(filepath))
    throw Arcade::ArcadeException("Cannot load the music : " + filepath);
  music.setLoop(true);
  music.play();
  music.setPlayingOffset(offset_music);
  music.setVolume(100);
}

sf::Sprite	Graph::GraphicMenu::createSpriteFromFile(sf::Texture &texture, const std::string &filepath, bool smooth) const
{
  sf::Sprite	sprite;

  if (!texture.loadFromFile(filepath))
    throw Arcade::ArcadeException("Cannot load the background");
  if (smooth)
    texture.setSmooth(true);
  sprite.setTexture(texture);
  return (sprite);
}

void		displayTitle(sf::RenderWindow &window, const std::string &title)
{
  sf::Font	font;
  sf::Text	text;

  if (!font.loadFromFile("assets/fonts/basic-regular.ttf"))
    throw Arcade::ArcadeException("Cannot load a font");
  text.setFont(font);
  text.setString(title);
  text.setCharacterSize(37);
  text.setPosition(715, 70);
  window.draw(text);
}

std::vector<Graph::GraphicMenu::t_menu_item>	displayListItems(sf::RenderWindow &window,
								     const std::vector<std::string> &listItems)
{
  sf::RectangleShape				rectangle(sf::Vector2f(500, 50));
  sf::Font					font;
  sf::Text					text;
  int						pos_y;
  std::vector<Graph::GraphicMenu::t_menu_item>	drawList;
  Graph::GraphicMenu::t_menu_item		itemMenu;

  if (!font.loadFromFile("assets/fonts/basic-regular.ttf"))
    throw Arcade::ArcadeException("Cannot load a font");
  text.setFont(font);
  pos_y = 200;
  rectangle.setFillColor(sf::Color(26, 188, 156));
  for (auto it = listItems.begin(); it != listItems.end(); ++it)
  {

    text.setString(*it);
    text.setPosition(720, pos_y + 5);
    rectangle.setPosition(700, pos_y);
    window.draw(rectangle);
    window.draw(text);
    pos_y += rectangle.getSize().y + 30;
    itemMenu.shape_menu = rectangle;
    itemMenu.value = *it;
    drawList.push_back(itemMenu);
  }
  return (drawList);
}

std::string	getItemClicked(sf::Vector2i mousePosition,
				  std::vector<Graph::GraphicMenu::t_menu_item> drawList)
{
  (void)drawList;
  (void)mousePosition;
  for (auto it = drawList.begin(); it != drawList.end(); ++it)
  {
    if ((mousePosition.x < it->shape_menu.getPosition().x) ||
	(mousePosition.x > (it->shape_menu.getPosition().x + it->shape_menu.getSize().x)))
      continue;
    else if ((mousePosition.y < it->shape_menu.getPosition().y) ||
	     (mousePosition.y > (it->shape_menu.getPosition().y + it->shape_menu.getSize().y)))
      continue;
    else
      return (it->value);
  }
  return ("");
}

std::string	Graph::GraphicMenu::MenuLoop(sf::RenderWindow &window,
						sf::Sprite &sprite_bg,
						sf::Sprite &sprite_logo,
						const std::string &title,
						std::vector<std::string> listItems)
{
  int				alpha = 190;
  int				cursorSpeedFadeEffect = 0;
  int				cursorFadeEffect = 1;
  std::string			choice;
  std::vector<t_menu_item>	drawListMenu;

  while (window.isOpen())
  {
    sprite_logo.setColor(sf::Color(255, 255, 255, alpha)); // à moitié transparent
    window.clear();
    window.draw(sprite_bg);
    window.draw(sprite_logo);
    displayTitle(window, title);
    drawListMenu = displayListItems(window, listItems);
    sf::Event		event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
	case sf::Event::Closed:
	  window.close();
	  break;
	case sf::Event::KeyPressed:
	  if (event.key.code == sf::Keyboard::Escape)
	    window.close();
	  break;
	default:
	  break;
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
	choice = getItemClicked(sf::Mouse::getPosition(window), drawListMenu);
	if (!choice.empty())
	  return (choice);
      }
    }
    window.display();
    if (cursorSpeedFadeEffect >= SFML_LOGO_FADE_EFFECT_SPEED)
    {
      cursorSpeedFadeEffect = 0;
      alpha += cursorFadeEffect;
      cursorFadeEffect = (alpha == 255) ? -1 : cursorFadeEffect;
      cursorFadeEffect = (alpha == 110) ? 1 : cursorFadeEffect;
    }
    cursorSpeedFadeEffect++;
  }
  return ("");
}

std::pair<std::string, std::string>	Graph::GraphicMenu::startMenu(const std::vector<std::string> &listGraphics, const std::vector<std::string> &listGames)
{
  sf::Sprite				sprite_bg;
  sf::Sprite				sprite_logo;
  sf::Texture				texture_bg;
  sf::Texture				texture_logo;
  sf::Music				music;
  std::string				library_graphic_chosen;
  std::string				library_games_chosen;
  Graph::GraphicInit			initGraphic("ARCADE - C++ 2020");

  try
  {
    sprite_bg	= this->createSpriteFromFile(texture_bg, "assets/img/bg_menu.png", false);
    sprite_logo	= this->createSpriteFromFile(texture_logo, "assets/img/logo.png", true);
  }
  catch (Arcade::ArcadeException &e)
  {
    throw e;
  }
  sprite_bg.setScale(0.6667, 0.6667);
  sprite_logo.setScale(0.8, 0.8);
  sprite_logo.setPosition(50, 100);
  this->LaunchMenuSound(music, "assets/music/menu.ogg");
  library_graphic_chosen = this->MenuLoop(*(initGraphic.getWindow()), sprite_bg, sprite_logo, "Please select a graphic library", listGraphics);
  if (!library_graphic_chosen.empty())
    library_games_chosen = this->MenuLoop(*(initGraphic.getWindow()), sprite_bg, sprite_logo, "Please select a game library", listGames);
  return (std::make_pair(library_graphic_chosen, library_games_chosen));
}

extern "C"
{
Graph::IGraph	*getInstanceGraphicMenu()
{
  return (new Graph::GraphicMenu());
}
}

/* Unused pure methods */
void	Graph::GraphicMenu::createMap(void) {}
void	Graph::GraphicMenu::Game(void)  {}
void	Graph::GraphicMenu::SetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicMenu::UnsetSprite(int x, int y, Game::IGame *entry)  {(void)x; (void)y;(void)entry;}
void	Graph::GraphicMenu::Animation() {}
void	Graph::GraphicMenu::displayMap(int **ptr){(void)ptr;};
void	Graph::GraphicMenu::displayMap(int **, int, int, int) {}
void	Graph::GraphicMenu::drawMap(int, int, char) {}
void	Graph::GraphicMenu::drawPlayer(std::vector<Game::IGame*>, char) {};
void	Graph::GraphicMenu::drawScore(int, int) {};
void	Graph::GraphicMenu::drawFood(int, int, char) {};
void	Graph::GraphicMenu::drawLoose(void) {};
int	Graph::GraphicMenu::recoverKey(void) {return (0);};
bool	Graph::GraphicMenu::checkSizeWindow(int, int) {return (false);}
