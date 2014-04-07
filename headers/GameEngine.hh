//
// GameEngine.hh for TSG in /home/hu_e/Documents/Perso/TheSurvivalGame/src/GameEngine
//
// Made by Eric
// Login   <hu_e@epitech.net>
//
// Started on  Sat Apr  5 19:16:10 2014 Eric
// Last update Sat Apr  5 20:56:22 2014 Eric
//

#ifndef			GAMEENGINE_HH_
# define		GAMEENGINE_HH_

# define		WIN_WIDTH	640
# define		WIN_HEIGHT	480
# define		PLAYER_SPEED	100.0
# define		FRAME		60

# include		<SFML/Graphics.hpp>

class			GameEngine
{
private:
  sf::RenderWindow	_mWindow;
  sf::CircleShape	_mPlayer;
  bool			_mIsMovingUp;
  bool			_mIsMovingDown;
  bool			_mIsMovingLeft;
  bool			_mIsMovingRight;
  float			_playerSpeed;
  sf::Time		_timePerFrame;

  void			processEvents(void);
  void			update(sf::Time);
  void			render(void);
  void			handlePlayerInput(sf::Keyboard::Key, bool);

public:
  GameEngine();
  ~GameEngine();

  void			run(void);
};

#endif
