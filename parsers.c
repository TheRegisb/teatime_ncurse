/*
** parsers.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu Mar 23 19:50:46 2017 Régis Berthelot
** Last update Fri Mar 24 16:18:14 2017 Régis Berthelot
*/

#include "my.h"

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
	      printf("Wrong time input. "
		     "Expected a whole number greater or equal to 0\n");
	      exit(1);
	    }
	}
      else if ((strcmp(short_option, av[i]) == 0) && av[i + 1])
	{
	  if (nbr != 0)
	    {
	      printf("Conflicting setup. "
		     "No more than one option of the same type can be used.\n");
	      exit(1);
	    }
	  if (is_numeric(av[i + 1]) == 1)
	    nbr = get_time_option(av[i + 1]);
	  else
	    {
	      printf("Wrong time input. "
		     "Expected a whole number greater or equal to 0\n");
	      exit(1);
	    }
	}
    }
  return (nbr);
}

void	parser(char **av, int *time_array)
{
  time_array[0] = parse_time(av, "-m", "--minutes=");
  time_array[1] = parse_time(av, "-s", "--seconds=");
  time_array[0] += time_array[1] / 60;
  time_array[1] %= 60;
  time_array[2] = time_array[1] + (time_array[0] * 60);
}
