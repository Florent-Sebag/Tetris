/*
** basic.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
**
** Started on  Wed Mar  2 15:05:53 2016 Florent Sebag
** Last update Sun Mar 20 21:58:00 2016 Florent Sebag
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	str_compare(char *str, char *dest)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != dest[i])
        return (0);
      i = i + 1;
    }
  if (dest[i] != '\0')
    return (0);
  return (1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}


char	*my_epur_str(char *str)
{
  int	i;
  char	*res;
  int	j;

  j = 0;
  res = malloc(my_strlen(str) + 1);
  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] != ' ')
	{
	  res[j] = str[i];
	  i = i + 1;
	  j = j + 1;
	}
      while (str[i] == ' ' && str[i] != '\0')
	i = i + 1;
      if (str[i] != '\0')
	{
	  res[j] = ' ';
	  j = j + 1;
	}
    }
  res[j] = '\0';
  return (res);
}
