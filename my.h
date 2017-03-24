/*
** my.h for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu Mar 23 16:38:31 2017 Régis Berthelot
** Last update Thu Mar 23 19:03:30 2017 Régis Berthelot
*/

#ifndef MY_H_
# define MY_H_

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	is_numeric(char *);
int	get_time_option(char *);
void	parser(char **, int *);

#endif /* !MY_H_ */
