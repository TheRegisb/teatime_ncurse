/*
** messages.c for teatime in /home/regisb/Documents/projets/teatime_ncurse
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Fri Mar 24 17:18:06 2017 Régis Berthelot
** Last update Sat Mar 25 16:43:29 2017 Régis Berthelot
*/

#include "my.h"

void	help(void)
{
  write(1, "Usage: teatime [options]\n"
	"  -m --minutes={XX}\tAdd XX minute(s) to the timer.\n"
	"  -s --seconds={YY]\tAdd YY second(s) to the timer.\n"
	"  -h --help\t\tDisplay this help.\n"
	"  -v --version\t\tDisplay current version\n"
	"   q\t\t\tQuit teatime (during execution).\n", 239);
}

void	version(void)
{
  write(1, "teatime -- A simple ncurses timer\n  Version: 1.0\n  "
	"Made by: Régis Berthelot\n  "
	"NO WARRANTY OF ANY KIND ARE PROVIDED.\n", 117);
}
