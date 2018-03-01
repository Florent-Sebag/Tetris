/*
** debug_mode.c for h in /home/sebag_f/Desktop/rendu/save/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Thu Mar 10 18:51:05 2016 Florent Sebag
** Last update Sun Mar 20 19:11:15 2016 Florent Sebag
*/

#include "header.h"

t_debug	array[] =
  {
    {&def_level, "--level="},
    {&key_left, "--key-left="},
    {&key_right, "--key-right="},
    {&key_turn, "--key-turn="},
    {&key_drop, "--key-drop="},
    {&without_next, "--without-next"},
    {&without_next, "-w"},
    {&key_quit, "--key-quit="},
    {&key_pause, "--key-pause="},
    {&def_size, "--map-size="},
    {&def_mini_level, "-l"},
    {&key_mini_left, "-kl"},
    {&key_mini_right, "-kr"},
    {&key_mini_turn, "-kt"},
    {&key_mini_drop, "-kd"},
    {&key_mini_quit, "-kq"},
    {&key_mini_pause, "-kp"},
    {0, NULL}
  };

int	str_custom_compare(char *str, char *src)
{
  int	i;

  i = 0;
  while (str[i] != '=')
    {
      if (str[i] != src[i])
	return (0);
      i = i + 1;
    }
  if (str[i] != src[i])
    return (0);
  return (1);
}

int	find_key(char *cmd, t_key *key)
{
  int	i;

  i = 0;
  while (str_custom_compare(cmd, array[i].cmd) == 0)
    {
      i = i + 1;
      if (array[i].cmd[1] == 'l')
	return (0);
    }
  array[i].ptr(key, cmd);
  return (1);
}

int	find_mini_key(char *cmd, t_key *key, char *arg)
{
  int   i;

  i = 0;
  while (str_compare(cmd, array[i].cmd) == 0)
    {
      i = i + 1;
      if (array[i].cmd == NULL)
	return (0);
    }
  array[i].ptr(key, arg);
  return (1);
}

int	choose_flag(int ac, char **av, t_key *key)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (str_compare(av[i], "--debug") == 1 || str_compare(av[i], "-d") == 1)
	i = i + 1;
      if (i < ac)
	{
	  if (find_key(av[i], key) == 0)
	    {
	      find_mini_key(av[i], key, av[i + 1]);
	      i = i + 2;
	    }
	  else
	    i = i + 1;
	}
    }
  return (0);
}
