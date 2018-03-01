/*
** init_key.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Wed Mar 16 17:54:11 2016 Florent Sebag
** Last update Sun Mar 20 23:02:55 2016 Florent Sebag
*/

#include "header.h"

int     key_left(t_key *key, char *cmd)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  free_and_malloc(key->left, cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '^' && cmd[i + 1] == 'E')
	{
	  key->left[j] = 27;
	  i = i + 2;
	}
      else
	{
	  key->left[j] = (int)cmd[i];
	  i = i + 1;
	}
      j = j + 1;
    }
  key->left[j] = -1;
  return (0);
}

int     key_right(t_key *key, char *cmd)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  free_and_malloc(key->right, cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '^' && cmd[i + 1] == 'E')
	{
	  key->right[j] = 27;
	  i = i + 2;
	}
      else
	{
	  key->right[j] = (int)cmd[i];
	  i = i + 1;
	}
      j = j + 1;
    }
  key->right[j] = -1;
  return (0);
}

int     key_turn(t_key *key, char *cmd)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  free_and_malloc(key->turn, cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '^' && cmd[i + 1] == 'E')
	{
	  key->turn[j] = 27;
	  i = i + 2;
	}
      else
	{
      key->turn[j] = (int)cmd[i];
      i = i + 1;
	}
      j = j + 1;
    }
  key->turn[j] = -1;
  return (0);
}

int     key_drop(t_key *key, char *cmd)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  free_and_malloc(key->drop, cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '^' && cmd[i + 1] == 'E')
	{
	  key->drop[j] = 27;
	  i = i + 2;
	}
      else
	{
	  key->drop[j] = (int)cmd[i];
	  i = i + 1;
	}
      j = j + 1;
    }
  key->drop[j] = -1;
  return (0);
}

int     key_quit(t_key *key, char *cmd)
{
  int   i;
  int	j;

  i = 0;
  j = 0;
  while (cmd[i] != '=')
    i = i + 1;
  i = i + 1;
  free_and_malloc(key->quit, cmd);
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '^' && cmd[i + 1] == 'E')
	{
	  key->quit[j] = 27;
	  i = i + 2;
	}
      else
	{
	  key->quit[j] = (int)cmd[i];
	  i = i + 1;
	}
      j = j + 1;
    }
  key->quit[j] = -1;
  return (0);
}
