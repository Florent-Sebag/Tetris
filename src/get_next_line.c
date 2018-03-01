/*
** get3.c for g in /home/sebag_f/Desktop/rendu/CPE_2015_getnextline
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Wed Jan  6 13:13:07 2016 Florent Sebag
** Last update Sun Mar 20 22:55:04 2016 Florent Sebag
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "header.h"
#include "get_next_line.h"

char		*re_alloc(char *src, int size)
{
  char		*dest;
  int		i;

  if ((dest = (char*)malloc(sizeof(char) * (size + READ_SIZE))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  free(src);
  return (dest);
}

int		test_size(int size)
{
  if (size == 0)
    return (4);
  if (size == -1)
    return (-1);
  return (0);
}

t_char_err	get_next_char(const int fd, int reset)
{
  static char	buffer[READ_SIZE];
  static int	size = -2;
  static int	i = -2;
  t_char_err	x;

  if (reset == 1)
    {
      size = -2;
      i = -2;
    }
  if (i == size)
    {
      size = read(fd, buffer, READ_SIZE);
      i = 0;
    }
  if ((x.err = test_size(size)) != 0)
    return (x);
  x.c = buffer[i];
  i = i + 1;
  if (x.c == '\n')
    x.err = 1;
  return (x);
}

int		test_char(t_result res, int indic)
{
  if (indic == 1 || res.x.err == -1)
    {
      free(res.result);
      return (1);
    }
  if (res.result == NULL)
    {
      free(res.result);
      return (1);
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  t_result	res;
  static int	indic = 0;
  static int	reset = 0;
  int		ret;

  res = new_gnl(res, 0, fd, reset);
  if (reset == 1)
    {
      indic = 0;
      reset = 0;
    }
  while (res.x.err != 1)
    {
      ret = new_other_gnl(res, indic);
      if (ret == 2)
	indic = 1;
      if ((reset = verif_return(ret)) > 0)
	return (NULL);
      res.result[res.i++] = res.x.c;
      if ((reset = test_char(res, indic)) == 1)
	return (NULL);
      res = new_gnl(res, 1, fd, reset);
    }
  res.result[res.i] = '\0';
  return (res.result);
}
