/*
** my.h for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu Mar 23 16:38:31 2017 Régis Berthelot
** Last update Fri Mar 24 17:20:04 2017 Régis Berthelot
*/

#ifndef MY_H_
# define MY_H_

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*
** Parsing related functions
*/

int	is_numeric(char *);
int	get_time_option(char *);
void	parser(char **, int *);

/*
** Text related functions
*/

void	help(void);
void	version(void);

#endif /* !MY_H_ */
