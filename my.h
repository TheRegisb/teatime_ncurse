/*
** my.h for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Thu Mar 23 16:38:31 2017 Régis Berthelot
** Last update Sat Mar 25 17:14:51 2017 Régis Berthelot
*/

#ifndef MY_H_
# define MY_H_

#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

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

/*
** Ncurses related functions
*/

void	teatime_core(int *);

#endif /* !MY_H_ */
