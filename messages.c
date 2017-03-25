/*
** messages.c for teatime in /home/regisb/Documents/projets/teatime_ncurse
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Fri Mar 24 17:18:06 2017 Régis Berthelot
** Last update Sat Mar 25 10:02:50 2017 Régis Berthelot
*/

#include "my.h"

void	help(void)
{
  write(1, "Usage: teatime [option]\n"
	 "  -m --minutes={XX}\tAdd XX minute(s) to the timer.\n"
	 "  -s --seconds={YY]\tAdd YY second(s) to the timer.\n"
	 "  -h --help\t\tDisplay this help.\n"
	"  -v --version\tDisplay current version\n", 197);
}

void	version(void)
{
  write(1, "teatime -- A simple ncurse timer\n  Version 0.02\n  "
	"Made by Régis Berthelot WITHOUT WARRANTY OF ANY KIND.\n", 105);
}
