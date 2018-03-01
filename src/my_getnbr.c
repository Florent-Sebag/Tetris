/*
** my_getnbr.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Wed Mar 16 15:52:01 2016 Florent Sebag
** Last update Fri Mar 18 18:05:29 2016 Florent Sebag
*/

#include "header.h"

void    my_putnbr(int nb)
{
  int   mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
        {
          mod = (nb % 10);
          nb = (nb - mod) / 10;
          my_putnbr(nb);
          my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
}

int     my_getnbr(char *nbr)
{
  int   n;
  int   i;
  int   res;

  n = 1;
  res = 0;
  i = my_strlen(nbr) - 1;
  while (i >= 0 && nbr[i] != '-')
    {
      res = res + (n * (nbr[i] - 48));
      n = n * 10;
      i = i - 1;
    }
  if (nbr[0] == '-')
    res = res * -1;
  return (res);
}
