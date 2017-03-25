/*
** graphics.c for teatime in /home/regisb/Documents/projets/teatime_ncurse
** 
** Made by Régis Berthelot
** Login   <berthelot.regis@gmail.com>
** 
** Started on  Sat Mar 25 10:01:50 2017 Régis Berthelot
** Last update Sat Mar 25 14:08:32 2017 Régis Berthelot
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
  mvprintw(0, 0, "teatime -- version 0.9");
  move(row - 1, 0);
  for (int i = 0; i != col; i++)
    printw(" ");
  mvprintw(row - 1, 0, "Press 'q' to quit teatime at any time");
  attroff(COLOR_PAIR(1));
}

static void	update_timer(int current_time, int *time_array, int row, int col)
{
  mvprintw(row / 2, col / 2 - 11, "Infusion time:\t%02d:%02d",
	 time_array[0], time_array[1]);
  mvprintw((row / 2) + 1, col / 2 - 11, "Time elapsed:\t%02d:%02d",
	   current_time / 60, current_time % 60);
}

void	teatime_core(int *time_array)
{
  int	start_time;
  int	row;
  int	col;
  int	i;

  start_time = time(NULL);
  set_display();
  while ((time(NULL) - start_time) != (time_array[2]))
    {
      clear();
      i = getch();
      if (i == 'q')
	break ;
      getmaxyx(stdscr, row, col);
      draw_hub(row, col);
      update_timer((time(NULL) - start_time), time_array, row, col);
      refresh();
      usleep(250000);
    }
  endwin();
}
