/*
** find_key.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Thu Mar 10 13:47:31 2016 Florent Sebag
** Last update Sun Mar 20 22:15:13 2016 Florent Sebag
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses/curses.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <term.h>
#include <curses.h>

void		my_bzero(char *str)
{
  int		i;

  i = 0;
  while (i < 11)
    {
      str[i] = '\0';
      i = i + 1;
    }
  str[i] = '\0';
}

void		mode(int i)
{
  static struct	termios	save;
  static struct	termios	new_t;

  if (i == 0)
    {
      ioctl(0, TCGETS, &save);
      ioctl(0, TCGETS, &new_t);
      new_t.c_lflag &= ~ICANON;
      new_t.c_lflag &= ~ECHO;
      new_t.c_cc[VMIN] = 0;
      new_t.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &new_t);
    }
  else if (i == 1)
    ioctl(0, TCSETS, &save);
  else
    {
      ioctl(0, TCGETS, &save);
      ioctl(0, TCGETS, &new_t);
      new_t.c_lflag &= ~ICANON;
      new_t.c_lflag &= ~ECHO;
      new_t.c_cc[VMIN] = 1;
      new_t.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &new_t);
    }
}
