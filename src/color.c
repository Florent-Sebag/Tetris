/*
** color.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar 20 14:33:52 2016 Florent Sebag
** Last update Sun Mar 20 19:10:37 2016 Florent Sebag
*/

#include "header.h"

void		color_init()
{
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_YELLOW, COLOR_BLACK);
}
