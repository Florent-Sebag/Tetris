/*
** call_gnl_to_end.c for  in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar 18 15:43:50 2016 Florent Sebag
** Last update Sun Mar 20 22:53:04 2016 Florent Sebag
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "header.h"

int	verif_return(int ret)
{
  if (ret > 0)
    return (1);
  return (0);
}

int	 new_other_gnl(t_result res, int indic)
{
  if (test_char(res, indic) == 1)
    return (1);
  if (res.x.err == 4)
    return (2);
  return (0);
}

t_result	new_gnl(t_result res, int i, int fd, int reset)
{
  if (i == 0)
    {
      res.i = 0;
      res.result = malloc(sizeof(char) * (READ_SIZE));
      res.x = get_next_char(fd, reset);
    }
  else
    {
      if (res.i % READ_SIZE == 0)
        res.result = re_alloc(res.result, res.i);
      res.x = get_next_char(fd, reset);
    }
  return (res);
}

int	call_gnl_to_end(int fd)
{
  char	*tmp;

  tmp = get_next_line(fd);
  while (tmp != NULL)
    {
      tmp = get_next_line(fd);
      free(tmp);
    }
  close(fd);
  return (0);
}
