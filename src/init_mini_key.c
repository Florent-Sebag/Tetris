/*
** init_mini_key.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar 11 16:37:22 2016 Florent Sebag
** Last update Sun Mar 20 19:21:59 2016 Florent Sebag
*/

#include "header.h"

int	key_mini_left(t_key *key, char *cmd)
{
  int	i;

  i = 0;
  free(key->left);
  key->left = malloc(sizeof(int) * my_strlen(cmd));
  while (cmd[i] != '\0')
    {
      key->left[i] = (int)cmd[i];
      i = i + 1;
    }
  key->left[i] = -1;
  return (0);
}

int	key_mini_right(t_key *key, char *cmd)
{
  int	i;

  i = 0;
  free(key->right);
  key->right = malloc(sizeof(int) * my_strlen(cmd));
  while (cmd[i] != '\0')
    {
      key->right[i] = (int)cmd[i];
      i = i + 1;
    }
  key->right[i] = -1;
  return (0);
}

int	key_mini_turn(t_key *key, char *cmd)
{
  int	i;

  i = 0;
  free(key->turn);
  key->turn = malloc(sizeof(int) * my_strlen(cmd) + 2);
  while (cmd[i] != '\0')
    {
      key->turn[i] = (int)cmd[i];
      i = i + 1;
    }
  key->turn[i] = -1;
  return (0);
}

int	key_mini_drop(t_key *key, char *cmd)
{
  int	i;

  i = 0;
  free(key->drop);
  key->drop = malloc(sizeof(int) * my_strlen(cmd));
  while (cmd[i] != '\0')
    {
      key->drop[i] = (int)cmd[i];
      i = i + 1;
    }
  key->drop[i] = -1;
  return (0);
}

int	key_mini_quit(t_key *key, char *cmd)
{
  int	i;

  i = 0;
  free(key->quit);
  key->quit = malloc(sizeof(int) * my_strlen(cmd));
  while (cmd[i] != '\0')
    {
      key->quit[i] = (int)cmd[i];
      i = i + 1;
    }
  key->quit[i] = -1;
  return (0);
}
