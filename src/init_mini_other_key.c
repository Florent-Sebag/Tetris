/*
** init_mini_other_key.c for h in /home/sebag_f/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar 11 16:49:29 2016 Florent Sebag
** Last update Sun Mar 20 21:47:47 2016 Florent Sebag
*/

#include "header.h"

int     key_mini_pause(t_key *key, char *cmd)
{
  int   i;

  i = 0;
  free(key->pause);
  key->pause = malloc(sizeof(int) * my_strlen(cmd));
  while (cmd[i] != '\0')
    {
      key->pause[i] = (int)cmd[i];
      i = i + 1;
    }
  key->pause[i] = -1;
  return (0);
}

int	without_next(t_key *key, char *cmd)
{
  key->wn = 1;
  (void)cmd;
  return (0);
}

int     def_mini_level(t_key *key, char *cmd)
{
  key->level = my_getnbr(cmd);
  return (0);
}
