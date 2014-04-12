//
// main.cpp for  in /home/hu_e/Documents/Perso/TheSurvivalGame
//
// Made by Eric
// Login   <hu_e@epitech.net>
//
// Started on  Sat Apr  5 19:04:41 2014 Eric
// Last update Sat Apr 12 13:33:29 2014 Lambolez Aymeric
//

#include	"GameEngine.hh"
#include	"Parser.hh"

int		main(void)
{
  // GameEngine	game;

  // game.run();
  Parser	p;

  p.pars("map.txt");
  return 0;
}
