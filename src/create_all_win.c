/*
** create_all_win.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Thu Mar  3 15:21:22 2016 Florent Sebag
** Last update Sun Mar 20 20:47:13 2016 Florent Sebag
*/

#include "header.h"

t_size	find_max_size(t_tetrimino *tab)
{
  int	i;
  t_size	result;

  i = 0;
  result.width = 0;
  result.height = 0;
  while (i < 4)
    {
      if (tab[i].width > result.width)
	result.width = tab[i].width;
      if (tab[i].height > result.height)
	result.height = tab[i].height;
      i = i + 1;
    }
  if (result.width < 6)
    result.width = 8;
  if (result.height < 8)
    result.height = 8;
  return (result);
}

void	create_plat_win(t_all_win *x, int width, int height)
{
  x->plat = subwin(x->big_mac, height + 2, width + 2, 0, 26);
  wattron(x->plat, COLOR_PAIR(2));
  box(x->plat, ACS_VLINE, ACS_HLINE);
  wattron(x->plat, COLOR_PAIR(2));
}

void	create_score_win(t_all_win *x, int level)
{
  char	*res;

  res = malloc(sizeof(char) * len_of_nb(level) + 1);
  res = convert_int_to_char(level, res);
  x->score = subwin(x->big_mac, 10, 23, 7, 1);
  wattron(x->score, COLOR_PAIR(4));
  box(x->score, ACS_VLINE, ACS_HLINE);
  mvwprintw(x->score, 1, 1, "HIGH SCORE: 0");
  mvwprintw(x->score, 2, 1, "SCORE:   0");
  mvwprintw(x->score, 4, 1, "LINES:   0");
  mvwprintw(x->score, 5, 1, "LEVEL:");
  mvwprintw(x->score, 5, 10, res);
  wattroff(x->score, COLOR_PAIR(4));
}

void	create_next_win(t_all_win *x, int width, t_tetrimino *tab)
{
  t_size	max_size;

  max_size = find_max_size(tab);
  x->next = subwin(x->big_mac, max_size.height + 2, max_size.width + 2, 0, width + 30);
  box(x->next, ACS_VLINE, ACS_HLINE);
  mvwprintw(x->next, 1, (max_size.width / 2) - 1, "NEXT");
}

t_index		*create_all_win(t_all_win *x, t_size size, t_tetrimino *tab, int level)
{
  t_index	*map;

  map = create_plat_game(size.width, size.height);
  create_plat_win(x, size.width, size.height);
  create_score_win(x, level);
  create_next_win(x, size.width, tab);
  return (map);
}
