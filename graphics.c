/*
** graphics.c for teatime in /home/regisb/Documents/projets/teatime_ncurse
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Sat Mar 25 10:01:50 2017 Régis Berthelot
** Last update Sat Mar 25 10:39:24 2017 Régis Berthelot
*/

#include "my.h"

static void	set_display(void)
{
  initscr();
  raw();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
}

static void	draw_hub(void)
{
  mvprintw(0, 0, "teatime -- version 0.03");
}

static void	update_timer(int current_time, int max_time)
{
  int	row;
  int	col;

  getmaxyx(stdscr, row, col);
  move(row / 2, col / 2);
  printw("%d | %d\n", max_time, current_time);
}

void	teatime_core(int *time_array)
{
  int	start_time;

  start_time = time(NULL);
  set_display();
  while (time(NULL) - start_time != time_array[2])
    {
      clear();
      draw_hub();
      update_timer((time(NULL) - start_time), time_array[2]);
      refresh();
      usleep(500000);
    }
  endwin();
}
