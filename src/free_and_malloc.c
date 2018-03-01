/*
** free_and_malloc.c for h in /home/sebag_f/Desktop/rendu/PSU_2015_tetris
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Sun Mar 20 22:58:15 2016 Florent Sebag
** Last update Sun Mar 20 23:00:41 2016 Florent Sebag
*/

#include "header.h"

int	free_and_malloc(int *tab, char *cmd)
{
  free(tab);
  if ((tab = malloc(sizeof(int) * my_strlen(cmd))) == NULL)
    exit(42);
  return (0);
}
