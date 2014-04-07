//
// GameEngine.cpp for TSG in /home/hu_e/Documents/Perso/TheSurvivalGame/src/GameEngine
//
// Made by Eric
// Login   <hu_e@epitech.net>
//
// Started on  Sat Apr  5 19:22:03 2014 Eric
// Last update Sat Apr  5 21:01:26 2014 Eric
//

#include	"GameEngine.hh"

GameEngine::GameEngine() :
  _mWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "The Survival Game"),
  _mPlayer()
{
  _mPlayer.setRadius(40.f);
  _mPlayer.setPosition(100.f, 100.f);
  _mPlayer.setFillColor(sf::Color::Cyan);
  _mIsMovingUp = false;
  _mIsMovingDown = false;
  _mIsMovingLeft = false;
  _mIsMovingRight = false;
  _playerSpeed = PLAYER_SPEED;
  _timePerFrame = sf::seconds(1.f / FRAME);
}

GameEngine::~GameEngine(){};

void		GameEngine::run(void)
{
  sf::Clock	clock;
  sf::Time	lastUpdate = sf::Time::Zero;

  while(_mWindow.isOpen())
    {
      processEvents();
      lastUpdate += clock.restart();
      while (lastUpdate >  _timePerFrame)
	{
	  lastUpdate -= _timePerFrame;
	  processEvents();
	  update(_timePerFrame); // A revoir
	}
      render();
    }
}

void		GameEngine::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
  switch (key)
    {
    case sf::Keyboard::W:
      _mIsMovingUp = isPressed;
      break;

    case sf::Keyboard::S:
      _mIsMovingDown = isPressed;
      break;

    case sf::Keyboard::A:
      _mIsMovingLeft = isPressed;
      break;

    case sf::Keyboard::D:
      _mIsMovingRight = isPressed;
      break;

    default:
      break;
    }
}

void		GameEngine::processEvents(void)
{
  sf::Event	event;

  while (_mWindow.pollEvent(event))
    {
      switch (event.type)
	{
	case sf::Event::KeyPressed:
	  handlePlayerInput(event.key.code, true);
	  break;

	case sf::Event::KeyReleased:
	  handlePlayerInput(event.key.code, false);
	  break;

	case sf::Event::Closed:
	  _mWindow.close();
	  break;

	default:
	  break;
	}
    }
}

void		GameEngine::update(sf::Time dTime)
{
  sf::Vector2f movement(0.f, 0.f);

  if (_mIsMovingUp)
    movement.y -= _playerSpeed;
  if (_mIsMovingDown)
    movement.y += _playerSpeed;
  if (_mIsMovingLeft)
    movement.x -= _playerSpeed;
  if (_mIsMovingRight)
    movement.x += _playerSpeed;
  _mPlayer.move(movement * dTime.asSeconds());
}

void		GameEngine::render(void)
{
  _mWindow.clear();
  _mWindow.draw(_mPlayer);
  _mWindow.display();
}
