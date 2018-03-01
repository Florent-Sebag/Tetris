/*
** first_def_key.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar 11 13:43:54 2016 Florent Sebag
** Last update Sun Mar 20 19:42:32 2016 Florent Sebag
*/

#include "header.h"
#include <stdlib.h>

void	fill_key(t_key *key)
{
  key->level = 1;
  key->left[0] = 27;
  key->left[1] = 79;
  key->left[2] = 68;
  key->left[3] = -1;
  key->right[0] = 27;
  key->right[1] = 79;
  key->right[2] = 67;
  key->right[3] = -1;
  key->turn[0] = 27;
  key->turn[1] = 79;
  key->turn[2] = 65;
  key->turn[3] = -1;
  key->drop[0] = 27;
  key->drop[1] = 79;
  key->drop[2] = 66;
  key->drop[3] = -1;
  key->quit[0] = 113;
  key->quit[1] = -1;
  key->pause[0] = 112;
  key->pause[1] = -1;
  key->size.width = 10;
  key->size.height = 20;
}

t_key	*def_key()
{
  t_key *key;

  key = malloc(sizeof(t_key));
  key->pause = malloc(sizeof(int) * 2);
  key->left = malloc(sizeof(int) * 4);
  key->right = malloc(sizeof(int) * 4);
  key->turn = malloc(sizeof(int) * 4);
  key->drop = malloc(sizeof(int) * 4);
  key->quit = malloc(sizeof(int) * 2);
  key->wn = 0;
  fill_key(key);
  return (key);
}


