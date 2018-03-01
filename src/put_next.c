/*
** put_next.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Tue Mar  8 15:36:49 2016 Florent Sebag
** Last update Sun Mar 20 23:31:50 2016 Florent Sebag
*/

#include "header.h"

char		*convert_char(char c)
{
  char		*result;

  result = malloc(sizeof(char) * 2);
  result[0] = c;
  result[1] = '\0';
  return (result);
}

void		normal_print(WINDOW *next, t_size max_size)
{
  wclear(next);
  wattron(next, COLOR_PAIR(3));
  mvwprintw(next, 1, (max_size.width / 2) - 1, "NEXT");
  box(next, ACS_VLINE, ACS_HLINE);
  wattroff(next, COLOR_PAIR(3));
}

void		put_next(WINDOW *next, int indic, t_tetrimino *tab)
{
  t_counter	k;
  t_size	max_size;

  max_size = find_max_size(tab);
  k.x = (max_size.width / 2) - tab[indic].width + 2;
  k.y = 3;
  k.i = 0;
  normal_print(next, max_size);
  while (tab[indic].tetri[k.i] != '\0')
    {
      while (tab[indic].tetri[k.i] != '\n' && tab[indic].tetri[k.i] != '\0')
	{
	  wattron(next, COLOR_PAIR(tab[indic].color));
	  mvwprintw(next, k.y, k.x, convert_char(tab[indic].tetri[k.i]));
	  wattroff(next, COLOR_PAIR(tab[indic].color));
	  k.i = k.i + 1;
	  k.x = k.x + 1;
	}
      k.y = k.y + 1;
      if (tab[indic].tetri[k.i] != '\0')
	k.i = k.i + 1;
      k.x = (max_size.width / 2) - tab[indic].width + 2;
    }
  touchwin(next);
  wrefresh(next);
}
