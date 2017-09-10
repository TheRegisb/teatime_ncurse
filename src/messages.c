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
** messages.c for teatime in /home/regisb/Documents/projets/teatime_ncurse
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Fri Mar 24 17:18:06 2017 Régis Berthelot
** Last update Sun Sep 10 18:36:44 2017 Régis Berthelot
*/

#include "teatime.h"

void	help(void)
{
  printf("Usage: teatime [options]\n"
	 "  -m --minutes={XX}\tAdd XX minute(s) to the timer.\n"
	 "  -s --seconds={YY]\tAdd YY second(s) to the timer.\n"
	 "  -p --pause\t\tStart with the timer paused.\n"
	 "  -h --help\t\tDisplay this help.\n"
	 "  -v --version\t\tDisplay current version\n"
	 "   q\t\t\tQuit teatime (during execution).\n"
	 "   p\t\t\tPause the timer (during execution).\n");
}

void	version(void)
{
  printf("Teatime -- A simple ncurses timer\n  Version: 1.21.2\n  "
	"Made by: Régis Berthelot\n  "
	"License GPLv3+: GNU GPL version 3 or later "
	"<http://gnu.org/licences/gpl.htlm>\n  "
	"This software is free, and you are welcome to redistribute it "
	"under certain conditions.\n  "
	"This program comes with ABSOLUTELY NO WARRANTY.\n");
}
