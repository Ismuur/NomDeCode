##
## Makefile for NomdeCode in /home/lambol_a/NomDeCode
##
## Made by Lambolez Aymeric
## Login   <lambol_a@epitech.net>
##
## Started on  Mon Apr  7 15:13:39 2014 Lambolez Aymeric
## Last update Mon Apr  7 15:29:11 2014 Eric
##

SRC	=	Class/GameEngine.cpp\
		core/main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	Game

LIBS	=	-lsfml-graphics -lsfml-window -lsfml-system

CC	=	g++

FLAGS	=	-W -Wall

HEADERS	=	-I./headers/

all:		$(NAME)

%.o:		%.cpp
	$(CC) -c $^ -o $@ $(FLAGS) $(HEADERS)

$(NAME):	$(OBJ)
	$(CC) $^ -o $@ $(FLAGS) $(HEADERS) $(LIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all
