/*
** fenetre.c for fenetre in /home/soulie_b/Essai/tetris
**
** Made by Soulies Clément
** Login   <soulie_b@epitech.net>
**
** Started on  Wed Feb 24 11:36:44 2016 Soulies Clément
** Last update Sun Mar 20 23:26:14 2016 Florent Sebag
*/

#include "header.h"

void	close_win(t_all_win *x)
{
  delwin(x->plat);
  delwin(x->score);
  delwin(x->next);
  delwin(x->big_mac);
  endwin();
}

void	print_tetris(WINDOW *big_mac)
{
  wattron(big_mac, COLOR_PAIR(1));
  mvwprintw(big_mac, 1, 1, "*** *** *** *** * ***");
  mvwprintw(big_mac, 2, 1, " *  *    *  * *   *  ");
  mvwprintw(big_mac, 3, 1, " *  **   *  **  * ***");
  mvwprintw(big_mac, 4, 1, " *  *    *  * * *   *");
  mvwprintw(big_mac, 5, 1, " *  ***  *  * * * ***");
  wattroff(big_mac, COLOR_PAIR(1));
}

int	def_win(t_all *x)
{
  x->win = malloc(sizeof(t_all_win));
  x->win->big_mac = initscr();
  noecho();
  curs_set(false);
  x->map = create_all_win(x->win, x->key->size, x->tab, x->key->level);
  color_init();
  print_tetris(x->win->big_mac);
  refresh();
  keypad(x->win->big_mac, true);
  if (play_game(x) == -1)
    close_win(x->win);
  refresh();
  return (0);
}

void    my_help()
{
  my_putstr("Usage: ./tetris [options]\nOptions:\n");
  my_putstr("--help				Display this help\n");
  my_putstr("-l --level={num}		Start Tetris at level num\n");
  my_putstr("-kl --key-left={K}		Move tetrimino on LEFT with key K\n");
  my_putstr("-kr --key-right={K}		Move tetrimino on RIGHT with key K\n");
  my_putstr("-kt --key-turn={K}		Turn tetrimino with key K\n");
  my_putstr("-kd --key-drop={K}		Set default DROP on key K\n");
  my_putstr("-kq --key-quit={K}		Quit program when press key K\n");
  my_putstr("-kp --key-pause={K}		Pause and restart game when repress key K\n");
  my_putstr("--map-size={row, col}		Set game size at row, col\n");
  my_putstr("-w --without-next		Hide next tetrimino\n");
  my_putstr("-d --debug			Debug mode\n");
}

int     main(int ac, char **av)
{
  t_all		*x;
  int		i;

  i = 1;
  x = malloc(sizeof(t_all));
  x->key = def_key();
  x->score = 0;
  choose_flag(ac, av, x->key);
  x->tab = create_array();
  x->nb_tetri = find_nb_tetri();
  test_tab(x);
  while (i < ac)
    {
      if (str_compare(av[i], "--debug") == 1 || str_compare(av[i], "-d") == 1)
        print_all(x);
      if (str_compare(av[i], "--help") == 1)
	my_help();
      i = i + 1;
    }
  def_win(x);
  return (0);
}
