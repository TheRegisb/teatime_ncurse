/*
** parsers.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu Mar 23 19:50:46 2017 Régis Berthelot
** Last update Fri Mar 24 17:31:04 2017 Régis Berthelot
*/

#include "my.h"

static void	are_details_asked(char **av)
{
  for (int i = 0; av[i] != NULL; i++)
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
		    "Expected a whole number greater or equal to 0\n", 61);
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
		    "Expected a whole number greater or equal to 0\n", 61);
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
}
