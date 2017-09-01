/*
**  Teatime - A simple ncurses-based timer
**  Copyright (C) 2017 Régis BERTHELOT
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
** my.h for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Thu Mar 23 16:38:31 2017 Régis Berthelot
** Last update Fri Sep  1 18:27:47 2017 Régis Berthelot
*/

#ifndef TEA_H_
# define TEA_H_

#include <ncurses.h>
#include <string.h>
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

#endif /* !TEA_H_ */
