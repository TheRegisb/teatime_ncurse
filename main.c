/*
** main.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu Mar 23 16:39:12 2017 Régis Berthelot
** Last update Fri Mar 24 16:32:30 2017 Régis Berthelot
*/

#include "my.h"
#include <stdio.h>

void	help(void)
{
  write(1, "Usage: teatime [option]\n"
	 "  -m --minutes={XX}\tAdd XX minute(s) to the timer.\n"
	 "  -s --seconds={YY]\tAdd YY second(s) to the timer.\n"
	 "  -h --help\t\tDisplay this help.\n"
	"  -v --version\tDisplay current version\n", 197);
}

/*
** Time_array represent {Min; Sec; Total time in sec}
*/

int	main(int ac, char **av)
{
  static int	time_array[3];

  if (ac < 2)
    {
      write(2, "Error: at least one time option is required.\n", 46);
      help();
      return (1);
    }
  time_array[0] = 0;
  time_array[1] = 0;
  parser(av, time_array);
  if (time_array[0] == 0 && time_array[1] == 0)
    {
      write(2, "Error: time must be greater than 0\n", 35);
      return (1);
    }
  return (0);
}
