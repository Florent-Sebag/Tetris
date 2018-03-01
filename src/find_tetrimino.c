/*
** find_tetrimino.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar  4 14:29:42 2016 Florent Sebag
** Last update Sun Mar 20 23:15:57 2016 Florent Sebag
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "header.h"
#include "get_next_line.h"

int		find_nb_tetri()
{
  DIR		*dir;
  struct dirent	*file;
  int		i;

  i = 0;
  dir = opendir("./tetriminos");
  file = readdir(dir);
  if (file != NULL)
    i = 1;
  while (file != NULL)
    {
      file = readdir(dir);
      if (file != NULL)
	i = i + 1;
    }
  closedir(dir);
  return (i - 2);
}

void	add_to_end(char *src, char *dest, int len)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  if (i != 0)
    {
      dest[i] = '\n';
      i = i + 1;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  while (j < len)
    {
      dest[i] = ' ';
      i = i + 1;
      j = j + 1;
    }
  dest[i] = '\0';
}

int	my_get_heig_width(char *str, int indic)
{
  t_counter	x;
  int		res;

  res = 0;
  x.i = 0;
  x.j = 0;
  while (x.j < indic + 1)
    {
      while (str[x.i] != ' ' && str[x.i] != '\0')
	x.i = x.i + 1;
      if (str[x.i] != '\0' && (x.j + 1) < indic + 1)
	x.i = x.i + 1;
      x.j = x.j + 1;
    }
  x.i = x.i - 1;
  x.j = 1;
  while (x.i >= 0)
    {
      if (str[x.i] == ' ')
	return (res);
      res = res + (x.j * (str[x.i] - 48));
      x.j = x.j * 10;
      x.i = x.i - 1;
    }
  return (res);
}


t_tetrimino	fill_struct(struct dirent *file)
{
  int		fd;
  char		*tmp;
  t_tetrimino	res;

  tmp = find_path(file);
  fd = open(tmp, O_RDONLY);
  free(tmp);
  res = def_elem(res, fd, file);
  call_gnl_to_end(fd);
  close(fd);
  return (res);
}

t_tetrimino	*create_array()
{
  t_tetrimino	*array;
  t_dir_and_fil	x;

  array = malloc(sizeof(t_tetrimino) * (find_nb_tetri() + 1) * 4);
  x.i = 0;
  x.dir = opendir("./tetriminos");
  x.file = readdir(x.dir);
  while (x.file != NULL)
    {
      if (x.file->d_name[0] == '.')
	x.file = readdir(x.dir);
      if (x.file != NULL)
	{
	  if ((x.i % 4) == 0)
	    {
	      array[x.i] = fill_struct(x.file);
	      x.file = readdir(x.dir);
	    }
	  else
	    array[x.i] = next_turn(array[x.i - 1]);
	  x.i = x.i + 1;
	}
    }
  last_turn(array, x.i, x.dir);
  return (array);
}
