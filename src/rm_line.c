/*
** rm_line.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Tue Mar 15 17:02:10 2016 Florent Sebag
** Last update Sun Mar 20 20:36:35 2016 Florent Sebag
*/

#include "header.h"

int	go_down_piece(t_index *map, t_size size, int i)
{
  while (i > size.width)
    {
      map[i].indic = map[i - size.width].indic;
      map[i].color = map[i - size.width].color;
      i = i - 1;
    }
  while (i >= 0)
    {
      map[i].indic = 0;
      i = i - 1;
    }
  return (0);
}

int	rm_line_to_map(t_index *map, t_size size, int i)
{
  int	j;

  j = i - size.width;
  while (j < i)
    {
      map[j].indic = 0;
      j = j + 1;
    }
  return (0);
}

int	rm_line(t_all *x, t_size size)
{
  int	i;
  int	indic;
  int	z;

  i = 0;
  indic = 0;
  z = 1;
  while (i < (size.width * size.height))
    {
      if (x->map[i].indic == 1)
	indic = indic + 1;
      i = i + 1;
      z = z + 1;
      if (z % (size.width + 1) == 0)
	{
	  z = 1;
	  if (indic == size.width)
	    {
	      rm_line_to_map(x->map, size, i);
	      go_down_piece(x->map, size, i);
	      x->score = x->score + 100;
	      if (x->score % 500 == 0)
		x->key->level = x->key->level + 1;
	      put_new_score(x);
	      return (-1);
	    }
	  indic = 0;
	}
    }
  return (0);
}
