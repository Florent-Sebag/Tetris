/*
** print_elem.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar 20 23:05:08 2016 Florent Sebag
** Last update Sun Mar 20 23:08:24 2016 Florent Sebag
*/

#include "header.h"

void	print_with_color(int x, int color, WINDOW *plat, int y)
{
  wattron(plat, COLOR_PAIR(color));
  mvwprintw(plat, y, x, "*");
  wattroff(plat, COLOR_PAIR(color));
}
