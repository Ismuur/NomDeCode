//
// Parser.cpp for lama in /home/lambol_a/NomDeCode
//
// Made by Lambolez Aymeric
// Login   <lambol_a@epitech.net>
//
// Started on  Wed Apr  9 10:57:44 2014 Lambolez Aymeric
// Last update Sat Apr 26 14:42:34 2014 Lambolez Aymeric
//

#include		"Parser.hh"

Parser::Parser()
{
}

Parser::~Parser()
{
  while (_height)
    {
      while (_map[_height].size())
	_map[_height].pop_back();
      _map.pop_back();
      --_height;
    }
}

int					Parser::getWidth()const{return _width;}
int					Parser::getHeight()const{return _height;}
std::vector<std::vector<int> > const	&Parser::getMap()const{return _map;}

void				Parser::pars(std::string const &path)
{
  std::fstream			file;
  int				val;
  unsigned int			x;
  unsigned int			y = 0;

  file.open(path.c_str(), std::ios_base::in);
  file >> _width;
  file >> _height;
  while (file.peek() != EOF && y < _height)
    {
      std::vector<int>		tmp;

      _map.push_back(tmp);
      x = 0;
      while (file.peek() != EOF && x < _width)
	{
	  file >> val;
	  _map[y].push_back(val);
	  ++x;
	}
      y++;
    }
  std::cout << "Parsing finish successfully\nwidth -> "
	    << _width << "\nheight -> " << _height << std::endl;
  for (y = 0; y < _height; y++)
    {
      for (x = 0; x < _width; x++)
	std::cout << _map[y][x] << " ";
      std::cout << std::endl;
    }
}
