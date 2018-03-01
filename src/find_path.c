/*
** find_path.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sat Mar  5 15:54:39 2016 Florent Sebag
** Last update Sun Mar 20 15:34:57 2016 Florent Sebag
*/

#include <stdlib.h>
#include <dirent.h>
#include "header.h"

int	my_strcpy(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (i);
}

char	*find_path(struct dirent *file)
{
  int	i;
  char	*result;
  int	j;

  result = malloc(my_strlen(file->d_name) + 16);
  i = my_strcpy("./tetriminos/", result);
  j = 0;
  while (file->d_name[j] != '\0')
    {
      result[i] = file->d_name[j];
      i = i + 1;
      j = j + 1;
    }
  result[i] = '\0';
  return (result);
}
