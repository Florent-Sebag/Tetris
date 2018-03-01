/*
** def_tetri_tab.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar 20 22:04:01 2016 Florent Sebag
** Last update Sun Mar 20 23:12:33 2016 Florent Sebag
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line.h"
#include "header.h"

t_tetrimino	read_elem(t_tetrimino res, int fd)
{
  int		i;
  int		indic;
  char		*tmp;

  i = 0;
  indic = 0;
  while (i < res.height)
    {
      tmp = get_next_line(fd);
      if (my_strlen(tmp) == res.width)
        indic = 1;
      if (my_strlen(tmp) > res.width)
        res.err = -1;
      add_to_end(tmp, res.tetri, res.width);
      free(tmp);
      i = i + 1;
    }
  if (indic == 0)
    res.err = -1;
  return (res);
}

t_tetrimino	def_elem(t_tetrimino res, int fd, struct dirent *file)
{
  char		*tmp;

  tmp = get_next_line(fd);
  if (test_first_line(tmp) == -1)
    {
      call_gnl_to_end(fd);
      res.err = -1;
      return (res);
    }
  res.width = my_get_heig_width(tmp, 0);
  res.height = my_get_heig_width(tmp, 1);
  res.color = my_get_heig_width(tmp, 2);
  res.name = my_strdup(file->d_name);
  res.tetri = malloc(sizeof(char) * (res.width * (res.height + 1)) + 10);
  res.tetri[0] = '\0';
  free(tmp);
  res.err = 0;
  res = read_elem(res, fd);
  return (res);
}

void		last_turn(t_tetrimino *array, int i, DIR *dir)
{
  int		j;

  j = 0;
  while (j < 3)
    {
      array[i] = next_turn(array[i - 1]);
      i = i + 1;
      j = j + 1;
    }
  array[i].err = 1;
  closedir(dir);
}
