/*
** find_err.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Thu Mar 17 19:21:11 2016 Florent Sebag
** Last update Sun Mar 20 19:22:36 2016 Florent Sebag
*/

#include "header.h"

int	test_first_line(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  if (str[i] == ' ')
	    i = i + 1;
	  else
	    return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int	test_tab(t_all *x)
{
  int	i;

  i = 0;
  while (x->tab[i].err != 1)
    {
      if (x->tab[i].width > x->key->size.width)
	x->tab[i].err = -1;
      if (x->tab[i].height > x->key->size.height)
	x->tab[i].err = -1;
      if (x->tab[i].color > 8 || x->tab[i].color < 1)
	x->tab[i].err = -1;
      i = i + 1;
    }
  return (0);
}

