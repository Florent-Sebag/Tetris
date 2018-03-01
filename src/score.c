/*
** score.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Wed Mar 16 14:42:20 2016 Florent Sebag
** Last update Sun Mar 20 20:46:52 2016 Florent Sebag
*/

#include "header.h"

int	len_of_nb(int nb)
{
  int	res;
  int	tmp;

  tmp = nb;
  res = 1;
  while (tmp > 1)
    {
      tmp = tmp / 10;
      res = res + 1;
    }
  return (nb);
}

char	*convert_int_to_char(int nb, char *buffer)
{
  int	divide;
  int	digit;
  int	i;

  i = 0;
  divide = 1;
  if (nb > - 2147483647 && nb < 2147483647)
    {
      while (nb / divide > 9)
        divide = divide * 10;
      while (divide > 0)
        {
          digit = (nb / divide) % 10;
          buffer[i] = digit + 48;
          divide = divide / 10;
          i = i + 1;
        }
      buffer[i] = '\0';
    }
  return (buffer);
}

char	*new_score(t_all *x)
{
  char	*res;

  res = malloc(sizeof(char) * len_of_nb(x->score) + 1);
  return (convert_int_to_char(x->score, res));
}

int	put_new_score(t_all *x)
{
  char	*res;

  res = new_score(x);
  wclear(x->win->score);
  wattron(x->win->score, COLOR_PAIR(4));
  box(x->win->score, ACS_VLINE, ACS_HLINE);
  mvwprintw(x->win->score, 1, 1, "HIGH SCORE:");
  mvwprintw(x->win->score, 1, 13, res);
  mvwprintw(x->win->score, 2, 1, "SCORE:");
  mvwprintw(x->win->score, 2, 10, res);
  free(res);
  res = malloc(sizeof(char) * len_of_nb(x->score) + 2);
  mvwprintw(x->win->score, 4, 1, "LINES:");
  mvwprintw(x->win->score, 4, 10, convert_int_to_char(x->score / 100, res));
  mvwprintw(x->win->score, 5, 1, "LEVEL:");
  free(res);
  res = malloc(sizeof(char) * len_of_nb(x->key->level) + 2);
  mvwprintw(x->win->score, 5, 10, convert_int_to_char(x->key->level, res));
  wrefresh(x->win->score);
  wattroff(x->win->score, COLOR_PAIR(4));
  return (0);
}
