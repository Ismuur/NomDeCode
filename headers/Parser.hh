//
// Parser.hh for NomdeCode in /home/lambol_a/NomDeCode
//
// Made by Lambolez Aymeric
// Login   <lambol_a@epitech.net>
//
// Started on  Wed Apr  9 10:50:30 2014 Lambolez Aymeric
// Last update Sat Apr 12 13:45:32 2014 Lambolez Aymeric
//

#ifndef		PARSER_HH_
# define	PARSER_HH_

# include	<fstream>
# include	<vector>
# include	<string>
# include	<iostream>

class Parser
{
public:
  Parser();
  ~Parser();

private:
  std::vector<std::vector<int> >	_map;
  unsigned int				_width;
  unsigned int				_height;

public:
  int					getWidth()const;
  int					getHeight()const;
  std::vector<std::vector<int> > const	&getMap()const;
  void					pars(std::string const &path);
};

#endif
