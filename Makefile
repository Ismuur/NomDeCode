##
## Makefile for NomdeCode in /home/lambol_a/NomDeCode
##
## Made by Lambolez Aymeric
## Login   <lambol_a@epitech.net>
##
## Started on  Mon Apr  7 15:13:39 2014 Lambolez Aymeric
## Last update Mon Apr  7 15:19:17 2014 Lambolez Aymeric
##

SRC	=	mot_graph.cpp

OBJ	=	$(SRC:.c=.o)

NAME	=	Game

CC	=	g++

FLAGS	=	-W -Wall

all:		$(NAME)

%.o:		%.cpp
	$(CC) -c $^ -o $@ $(FLAGS)

$(NAME):	$(OBJ)
	$(CC) $^ -o $@ $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean:		$(OBJ)
	$(RM) $(NAME)

re:		fclean all
