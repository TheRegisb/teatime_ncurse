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
** analysts.c for teatime in /home/regisb/Documents/projets/teatime
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Thu Mar 23 18:37:33 2017 Régis Berthelot
** Last update Sun Mar 26 14:17:54 2017 Régis Berthelot
*/

int	get_time_option(char *str)
{
  int	i;
  int	res;

  i = 0;
  while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (-1);
  res = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (-1);
      res = (res * 10) + (str[i] - 48);
      i++;
    }
  return (res);
}

int	is_numeric(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i++;
    }
  return (1);
}
