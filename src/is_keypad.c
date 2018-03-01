/*
** is_keypad.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar 13 17:22:11 2016 Florent Sebag
** Last update Mon Mar 14 15:13:16 2016 Florent Sebag
*/

#include "header.h"

int	compare_seq(int *key, char *buffer)
{
  int	i;

  i = 0;
  while (key[i] != -1)
    {
      if (key[i] != (int)buffer[i])
	return (0);
      i = i + 1;
    }
  if (buffer[i] != '\0')
    return (0);
  return (1);
}

int	find_keypad(t_all *x, char *buffer)
{
  if (compare_seq(x->key->left, buffer) == 1)
    return (-1);
  if (compare_seq(x->key->right, buffer) == 1)
    return (1);
  if (compare_seq(x->key->turn, buffer) == 1)
    return (3);
  if (compare_seq(x->key->drop, buffer) == 1)
    return (4);
  if (compare_seq(x->key->quit, buffer) == 1)
    return (5);
  if (compare_seq(x->key->pause, buffer) == 1)
    return (6);
  return (x->key->size.width);
}
