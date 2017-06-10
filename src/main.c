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
** main.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Thu Mar 23 16:39:12 2017 Régis Berthelot
** Last update Sat Jun 10 10:40:55 2017 Régis Berthelot
*/

#include "teatime.h"

/*
** Time_array represent {Min; Sec; Total time in sec; Start paused y/N}
*/

int	main(int ac, char **av)
{
  int	time_array[4];
  
  if (ac < 2)
    {
      write(2, "Teatime: at least one time option is required.\n", 48);
      help();
      return (1);
    }
  time_array[3] = -1;
  parser(av, time_array);
  if (time_array[2] == 0)
    {
      write(2, "Teatime: Time must be greater than 0\n", 37);
      return (1);
    }
  teatime_core(time_array);
  return (0);
}
