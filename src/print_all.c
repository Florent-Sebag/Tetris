/*
** print_all.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris/src
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Fri Mar 18 17:33:12 2016 Florent Sebag
** Last update Sun Mar 20 23:24:00 2016 Florent Sebag
*/

#include "header.h"

void	print_tab(int *tab)
{
  int	i;

  i = 0;
  while (tab[i] != -1)
    {
      if (tab[i] != 27 && tab[i] != 32)
	my_putchar(tab[i]);
      else if (tab[i] == 32)
	my_putstr("(space)");
      else
	{
	  my_putchar('^');
	  my_putchar('E');
	}
      i = i + 1;
    }
}

void	print_tetri_for_debug(t_all *x)
{
  int	i;

  i = 0;
  while (x->tab[i].err != 1)
    {
      my_putstr("Tetriminos : Name ");
      my_putstr(x->tab[i].name);
      if (x->tab[i].err != -1)
	{
	  my_putstr(" : Size ");
	  my_putnbr(x->tab[i].width);
	  my_putchar('*');
	  my_putnbr(x->tab[i].height);
	  my_putstr("Color : ");
	  my_putnbr(x->tab[i].color);
	  my_putstr(" :\n");
	  my_putstr(x->tab[i].tetri);
	  my_putchar('\n');
	}
      else
	my_putstr(" : Error\n");
      i = i + 4;
    }
}

void	second_print(t_all *x, char *tmp)
{
  if (x->key->wn == 1)
    my_putstr("No\n");
  else
    my_putstr("Yes\n");
  my_putstr("Level : ");
  my_putnbr(x->key->level);
  my_putchar('\n');
  my_putstr("Size : ");
  my_putnbr(x->key->size.height);
  my_putchar('*');
  my_putnbr(x->key->size.width);
  my_putchar('\n');
  print_tetri_for_debug(x);
  my_putstr("Press a key to start Tetris\n");
  mode(2);
  read(0, tmp, 1);
}

int	print_all(t_all *x)
{
  char	tmp[2];

  my_putstr("*** DEBUG MODE ***\n");
  my_putstr("Key Left : ");
  print_tab(x->key->left);
  my_putchar('\n');
  my_putstr("Key Right : ");
  print_tab(x->key->right);
  my_putchar('\n');
  my_putstr("Key Turn : ");
  print_tab(x->key->turn);
  my_putchar('\n');
  my_putstr("Key Drop : ");
  print_tab(x->key->drop);
  my_putchar('\n');
  my_putstr("Key Quit : ");
  print_tab(x->key->quit);
  my_putchar('\n');
  my_putstr("Key Pause : ");
  print_tab(x->key->pause);
  my_putchar('\n');
  my_putstr("Next : ");
  second_print(x, tmp);
  mode(1);
  return (0);
}
