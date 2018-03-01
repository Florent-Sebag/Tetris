/*
** my_strdup.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar 18 17:51:01 2016 Florent Sebag
** Last update Fri Mar 18 17:52:12 2016 Florent Sebag
*/

#include "header.h"

char	*my_strdup(char *str)
{
  char	*res;
  int	i;

  i = 0;
  res = malloc(sizeof(char) * my_strlen(str) + 1);
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i = i + 1;
    }
  res[i] = '\0';
  return (res);
}
