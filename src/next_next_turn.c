/*
** next_next_turn.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar 20 23:18:04 2016 Florent Sebag
** Last update Sun Mar 20 23:21:21 2016 Florent Sebag
*/

#include "header.h"

t_tetrimino	turn_tetri(t_tetrimino elem, t_tetrimino result, int i, int tmp)
{
  int		j;

  j = 0;
  result.tetri = malloc(sizeof(char) * my_strlen(elem.tetri) * 2 + 1);
  result.color = elem.color;
  while (elem.tetri[i] != '\0')
    {
      while (i >= 0)
        {
          result.tetri[j] = elem.tetri[i];
          j = j + 1;
          i = i - (elem.width + 1);
        }
      result.tetri[j] = '\n';
      j = j + 1;
      tmp = tmp + 1;
      i = tmp;
    }
  result.tetri[j - 1] = '\0';
  return (result);
}
