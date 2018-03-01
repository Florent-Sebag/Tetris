/*
** basic_use_map.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar  6 17:16:53 2016 Florent Sebag
** Last update Sun Mar 20 23:07:23 2016 Florent Sebag
*/

#include "header.h"

int	test_on_map(char bin, t_index *map, int pos)
{
  if (bin == ' ')
    return (1);
  if (map[pos].indic == 1)
    return (0);
  return (1);
}

int	put_on_map(char bin, t_index *map, int pos, int color)
{
  if (bin == ' ')
    return (0);
  if (bin == '\n')
    return (0);
  map[pos].indic = 1;
  map[pos].color = color;
  return (0);
}

int	rm_on_map(char bin, t_index *map, int pos)
{
  if (bin == ' ')
    return (0);
  map[pos].indic = 0;
  map[pos].color = -1;
  return (0);
}

int	rm_to_map(t_tetrimino x, t_index *map, int pos, int width)
{
  int	i;

  i = 0;
  while (x.tetri[i] != '\0')
    {
      if (x.tetri[i] != '\n')
        {
          rm_on_map(x.tetri[i], map, pos);
          pos = pos + 1;
        }
      else
        pos = pos + width - x.width;
      i = i + 1;
    }
  return (0);
}

int	print_map(t_index *map, WINDOW *plat, t_size size)
{
  int	i;
  int	x;
  int	y;

  x = 1;
  y = 1;
  i = 0;
  while (i < (size.width * size.height))
    {
      if (map[i].indic == 1)
	print_with_color(x, map[i].color, plat, y);
      else
	mvwprintw(plat, y, x, " ");
      i = i + 1;
      x = x + 1;
      if (x % (size.width + 1) == 0)
	{
	  x = 1;
	  y = y + 1;
	}
    }
  touchwin(plat);
  wrefresh(plat);
  return (0);
}
