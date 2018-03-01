/*
** init_other_key.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Thu Mar 17 14:28:51 2016 Florent Sebag
** Last update Sun Mar 20 23:03:13 2016 Florent Sebag
*/

#include "header.h"

int     key_pause(t_key *key, char *cmd)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  free_and_malloc(key->pause, cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '^' && cmd[i + 1] == 'E')
        {
          key->pause[j] = 27;
          i = i + 2;
        }
      else
        {
	  key->pause[j] = (int)cmd[i];
	  i = i + 1;
	}
      j = j + 1;
    }
  key->pause[j] = -1;
  return (0);
}

int     get_width(int i, char *cmd)
{
  char  *tmp;
  int   res;
  int   j;

  tmp = malloc(sizeof(char) * 2048);
  j = 0;
  i = i + 1;
  while (cmd[i] != '\0')
    {
      tmp[j] = cmd[i];
      i = i + 1;
      j = j + 1;
    }
  tmp[j] = '\0';
  res = my_getnbr(tmp);
  free(tmp);
  return (res);
}

int     def_size(t_key *key, char *cmd)
{
  int   i;
  int   j;
  char  *tmp;

  i = 0;
  j = 0;
  tmp = malloc(sizeof(char) * 2048);
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  while (cmd[i] != ',')
    {
      tmp[j] = cmd[i];
      i = i + 1;
      j = j + 1;
    }
  tmp[j] = '\0';
  key->size.height = my_getnbr(tmp);
  free(tmp);
  key->size.width = get_width(i, cmd);
  return (0);
}

int     def_level(t_key *key, char *cmd)
{
  char	*tmp;
  int	i;
  int	j;

  j = 0;
  i = 0;
  tmp = malloc(sizeof(char) * 2048);
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  while (cmd[i] != '\0')
    {
      tmp[j] = cmd[i];
      i = i + 1;
      j = j + 1;
    }
  tmp[j] = '\0';
  key->level = my_getnbr(tmp);
  free(tmp);
  return (0);
}
