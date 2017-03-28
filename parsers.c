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
** parsers.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Thu Mar 23 19:50:46 2017 Régis Berthelot
** Last update Tue Mar 28 19:26:38 2017 Régis Berthelot
*/

#include "my.h"

static void	are_details_asked(char **av)
{
  for (int i = 1; av[i] != NULL; i++)
    {
      if ((strcmp(av[i], "-h") == 0)
	  || (strcmp(av[i], "--help") == 0))
	{
	  help();
	  exit(0);
	}
      if ((strcmp(av[i], "-v") == 0)
	  || (strcmp(av[i], "--version") == 0))
	{
	  version();
	  exit(0);
	}
    }
}

static int	start_paused(char **av)
{
  int		pause;

  pause = -1;
  for (int i = 1; av[i] != NULL; i++)
    {
      if ((strcmp(av[i], "-p") == 0)
	  || (strcmp(av[i], "--pause") == 0))
	{
	  if (pause != -1)
	    {
	      write(2, "Error: Conflicting setup. "
		    "No more than one option of the same type"
		    " can be used.\n", 80);
	      exit(1);
	    }
	  pause = 1;
	}
    }
  return (pause);
}

static int	parse_time(char  **av, char *short_option, char *long_option)
{
  int	nbr = 0;

  for (int i = 0; av[i] != NULL; i++)
    {
      if (((strncmp(long_option, av[i], 10) == 0)
	   && strlen(av[i]) > 10 && strlen(av[i]) <= 12))
	{
	  if (nbr != 0)
	    {
	      write(2, "Error: Conflicting setup. "
		    "No more than one option of the same type"
		    " can be used.\n", 80);
	      exit(1);
	    }
	  nbr = get_time_option(av[i]);
	  if (nbr == -1)
	    {
	      write(1, "Wrong time input. "
		    "Expected a whole number greater or equal to 0\n", 64);
	      exit(1);
	    }
	}
      else if ((strcmp(short_option, av[i]) == 0) && av[i + 1])
	{
	  if (nbr != 0)
	    {
	      write(2, "Error: Conflicting setup. "
		    "No more than one option of the same type"
		    " can be used.\n", 80);
	      exit(1);
	    }
	  if (is_numeric(av[i + 1]) == 1)
	    nbr = get_time_option(av[i + 1]);
	  else
	    {
	      write(1, "Wrong time input. "
		    "Expected a whole number greater or equal to 0\n", 64);
	      exit(1);
	    }
	}
    }
  return (nbr);
}

void	parser(char **av, int *time_array)
{
  are_details_asked(av);
  time_array[0] = parse_time(av, "-m", "--minutes=");
  time_array[1] = parse_time(av, "-s", "--seconds=");
  time_array[0] += time_array[1] / 60;
  time_array[1] %= 60;
  time_array[2] = time_array[1] + (time_array[0] * 60);
  if (time_array[2] > 5999)
    {
      write(2, "Error: "
	    "Cannot set a timer greater than 99:59 (or 5999 seconds)\n", 63);
      exit(1);
    }
  time_array[3] = start_paused(av);
}
