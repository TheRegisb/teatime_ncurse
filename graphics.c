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
** graphics.c for teatime in /home/regisb/Documents/projets/teatime_ncurse
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Sat Mar 25 10:01:50 2017 Régis Berthelot
** Last update Tue Mar 28 19:25:31 2017 Régis Berthelot
*/

#include "my.h"

static void	set_display(void)
{
  initscr();
  raw();
  noecho();
  curs_set(0);
  timeout(0);
  keypad(stdscr, TRUE);
  start_color();
  use_default_colors();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
}

static void	draw_hub(int row,int col)
{
  attron(COLOR_PAIR(1));
  move(0, 0);
  for (int i = 0; i != col; i++)
    printw(" ");
  mvprintw(0, 0, "Teatime -- version 1.03");
  move(row - 1, 0);
  for (int i = 0; i != col; i++)
    printw(" ");
  mvprintw(row - 1, 0, "Commands: 'q' to quit | 'p' to pause the timer");
  attroff(COLOR_PAIR(1));
}

static void	update_timer(int current_time, int *time_array, int row, int col)
{
  mvprintw(row / 2 - 2, col / 2 - 11, "Infusion time:\t%02d:%02d",
	 time_array[0], time_array[1]);
  mvprintw((row / 2) - 1, col / 2 - 11, "Time elapsed: \t%02d:%02d",
	   current_time / 60, current_time % 60);
  if (time_array[3] == -1)
    mvprintw((row / 2) + 1, col / 2 - 11, "Status:       \t  ...");
  else
    mvprintw((row / 2) + 1, col / 2 - 11, "Status:       \tPause");
}

static void	end_teatime(int row, int col)
{
  flash();
  move((row / 2) + 1, (col / 2) - 11);
  printw("Status:       \tDone!");
  attron(COLOR_PAIR(1));
  for (int i = 0; i != col; i++)
    mvprintw(row - 1, i, " ");
  mvprintw(row - 1, 0, "Press any key to quit Teatime");
  attroff(COLOR_PAIR(1));
  timeout(-1);
  getch();
}

void	teatime_core(int *time_array)
{
  int	start_time;
  int	current_time;
  int	row;
  int	col;
  int	i;

  start_time = time(NULL);
  current_time = 0;
  set_display();
  while (current_time < (time_array[2]))
    {
      clear();
      i = getch();
      if (i == 'q')
	{
	  endwin();
	  exit(0);
	}
      else if (i == 'p')
	time_array[3] *= -1;
      getmaxyx(stdscr, row, col);
      if (col < 46 || row < 6)
	{
	  endwin();
	  write(2, "Error: The terminal must be at least 46x6! --ended\n", 51);
	  exit(1);
	}
      draw_hub(row, col);
      if (time_array[3] == -1)
	current_time = time(NULL) - start_time;
      else
	start_time = time(NULL) - current_time;
      update_timer(current_time, time_array, row, col);
      refresh();
      usleep(250000);
    }
  end_teatime(row, col);
  endwin();
}
