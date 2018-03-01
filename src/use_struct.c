/*
** use_struct.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar  6 16:24:58 2016 Florent Sebag
** Last update Sun Mar 20 23:37:44 2016 Florent Sebag
*/

#include <stdlib.h>
#include "header.h"

t_index		*create_plat_game(int width, int height)
{
  t_index	*map;
  int		i;

  i = 0;
  map = malloc(sizeof(t_index) * ((width * height) + 2));
  while (i < (width * height))
    {
      map[i].indic = 0;
      map[i].color = -1;
      i = i + 1;
    }
  return (map);
}

int		check_place(t_tetrimino x, t_index *map, t_size size, int pos)
{
  int		i;

  i = 0;
  while (x.tetri[i] != '\0')
    {
      if (pos > (size.width * size.height))
	return (-1);
      if (x.tetri[i] != '\n')
	{
	  if (test_on_map(x.tetri[i], map, pos) == 0)
	    return (0);
	  pos = pos + 1;
	}
      else
	pos = pos + size.width - x.width;
      i = i + 1;
    }
  return (1);
}

int		add_to_map(t_tetrimino x, t_index *map, int pos, int width)
{
  int		i;

  i = 0;
  while (x.tetri[i] != '\0')
    {
      if (x.tetri[i] != '\n')
	{
	  put_on_map(x.tetri[i], map, pos, x.color);
	  pos = pos + 1;
	}
      else
	pos = pos + width - x.width;
      i = i + 1;
    }
  return (0);
}

int		down_piece(t_tetrimino *tab, t_all *x, char *buff, int i)
{
  int		pos;
  int		indic;
  int		res;

  pos = x->key->size.width / 2;
  if ((indic = check_place(tab[i], x->map, x->key->size, pos)) != 1)
    return (-1);
  while (indic == 1 && pos < (x->key->size.width * x->key->size.height))
    {
      add_to_map(tab[i], x->map, pos, x->key->size.width);
      my_bzero(buff);
      read(0, buff, 10);
      if (x->key->level < 30)
	usleep((100000) - ((x->key->level - 1) * 2000));
      else
	usleep(40000);
      print_map(x->map, x->win->plat, x->key->size);
      rm_to_map(tab[i], x->map, pos, x->key->size.width);
      res = find_keypad(x, buff);
      if ((pos + tab[i].width) % x->key->size.width == 0 && res == 1)
	res = x->key->size.width;
      if (pos  % (x->key->size.width) == 0 && res == -1)
	res = x->key->size.width;
      if ((res >= -1 && res <= 1) || res == x->key->size.width)
	pos = pos + res;
      if (res == 6)
	{
	  res = 0;
	  while (res != 6)
	    {
	      my_bzero(buff);
	      read(0, buff, 10);
	      usleep(50000);
	      res = find_keypad(x, buff);
	    }
	  res = x->key->size.width;
	}
      if (res == 4)
	{
	  res = x->key->size.width;
	  while (check_place(tab[i], x->map, x->key->size, pos) == 1)
	    pos = pos + x->key->size.width;
	}
      if (res == 3)
	{
	  i = i + 1;
	  if (i % 4 == 0)
	    i = i - 4;
	}
      if (res == 5)
	return (-1);
      indic = check_place(tab[i], x->map, x->key->size, pos);
      if (indic == 0 && res != x->key->size.width)
	{
	  pos = pos - res;
	  indic = 1;
	}
    }
  add_to_map(tab[i], x->map, pos - res, x->key->size.width);
  return (0);
}

int		play_game(t_all *x)
{
  int		i;
  int		tmp;
  char		*buff;

  buff = malloc(sizeof(char) * 12);
  my_bzero(buff);
  i = (rand() % x->nb_tetri) * 4;
  while (x->tab[i].err == -1)
    i = (rand() % x->nb_tetri) * 4;
  mode(0);
  while (42)
    {
      tmp = (rand() % x->nb_tetri) * 4;
      while (x->tab[tmp].err == -1)
	tmp = (rand() % x->nb_tetri) * 4;
      if (x->key->wn == 0)
	put_next(x->win->next, tmp, x->tab);
      if (down_piece(x->tab, x, buff, i) == -1)
	{
	  mode(1);
	  return (-1);
	}
      while (rm_line(x, x->key->size) == -1);
      i = tmp;
    }
  mode(1);
  return (0);
}
