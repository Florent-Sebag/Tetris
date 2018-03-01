/*
** key_turn.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Mon Mar 14 16:58:12 2016 Florent Sebag
** Last update Sun Mar 20 23:20:14 2016 Florent Sebag
*/

#include "header.h"

int    		find_last_backslash(char *str)
{
  int  		i;
  int		res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	res = i + 1;
      i = i + 1;
    }
  return (res);
}

int		find_width(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\n' && str[i] != '\0')
    i = i + 1;
  return (i);
}

int		find_height(char *str)
{
  int		i;
  int		res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	res = res + 1;
      i = i + 1;
    }
  return (res + 1);
}

t_tetrimino	one_line(t_tetrimino elem)
{
  int		i;
  int		j;
  t_tetrimino	result;

  result.tetri = malloc(sizeof(char) * my_strlen(elem.tetri) * 2 + 1);
  j = 0;
  i = 0;
  while (elem.tetri[j] != '\0')
    {
      result.tetri[i] = elem.tetri[j];
      result.tetri[i + 1] = '\n';
      i = i + 2;
      j = j + 1;
    }
  result.tetri[i - 1] = '\0';
  result.width = find_width(result.tetri);
  result.height = find_height(result.tetri);
  return (result);
}

t_tetrimino	next_turn(t_tetrimino elem)
{
  t_tetrimino	result;
  int	       	i;
  int		tmp;

  result.err = 0;
  if (elem.err == -1)
    {
      result.err = -1;
      return (result);
    }
  if ((tmp = find_last_backslash(elem.tetri)) == 0)
    return (one_line(elem));
  i = tmp;
  result = turn_tetri(elem, result, i, tmp);
  result.width = find_width(result.tetri);
  result.height = find_height(result.tetri);
  return (result);
}

