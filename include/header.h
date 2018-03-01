/*
** header.h for header in /home/soulie_b/PSU_2015_tetris
** 
** Made by Soulies Clément
** Login   <soulie_b@epitech.net>
** 
** Started on  Mon Feb 22 10:10:49 2016 Soulies Clément
** Last update Sun Mar 20 23:35:42 2016 Florent Sebag
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "get_next_line.h"

#ifndef HEADER_H_
# define HEADER_H_

typedef	struct	s_all_win
{
  WINDOW	*plat;
  WINDOW	*score;
  WINDOW	*next;
  WINDOW	*big_mac;
}		t_all_win;

typedef	struct	s_size
{
  int		width;
  int		height;
}		t_size;

typedef	struct	s_tetrimino
{
  int		color;
  char		*name;
  char		*tetri;
  int		width;
  int		height;
  int		size;
  int		err;
}		t_tetrimino;

typedef	struct	s_counter
{
  int		i;
  int		j;
  int		k;
  int		x;
  int		y;
}		t_counter;

typedef	struct	s_wid_hei
{
  int		width;
  int		height;
}		t_wid_hei;

typedef	struct	s_index
{
  int		indic;
  int		color;
}		t_index;

typedef	struct	s_key
{
  int		level;
  int		*left;
  int		*right;
  int		*turn;
  int		*drop;
  int		*quit;
  int		*pause;
  int		wn;
  t_size	size;
}		t_key;

typedef	struct	s_debug
{
  int		(*ptr)(t_key *, char *);
  char		*cmd;
}		t_debug;

typedef	struct	s_all
{
  t_all_win	*win;
  t_index	*map;
  t_tetrimino	*tab;
  t_key		*key;
  int		score;
  int		nb_tetri;
}		t_all;

typedef	struct	s_dir_and_fil
{
  DIR		*dir;
  struct dirent	*file;
  int		i;
}		t_dir_and_fil;

void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strlen(char *str);
int		str_compare(char *str, char *dest);
t_tetrimino	next_turn(t_tetrimino elem);
void		print_tetrimino(t_all_win *z);
void		create_plat_win(t_all_win *x, int width, int height);
void		create_score_win(t_all_win *x, int level);
void		create_next_win(t_all_win *x, int width, t_tetrimino *tab);
t_index		*create_all_win(t_all_win *x, t_size size, t_tetrimino *tab, int level);
t_tetrimino	*create_array();
char		*find_path(struct dirent *file);
int		find_nb_tetri();
int		test_on_map(char bin, t_index *map, int pos);
int		put_on_map(char bin, t_index *map, int pos, int color);
int		print_map(t_index *map, WINDOW *plat, t_size size);
t_index		*create_plat_game(int width, int height);
int		play_game(t_all *x);
int		rm_to_map(t_tetrimino x, t_index *map, int pos, int width);
void		put_next(WINDOW *next, int indic, t_tetrimino *tab);
t_size		find_max_size(t_tetrimino *tab);
int		nb_key(char *str);
int		key_left(t_key *key, char *cmd);
int		key_right(t_key *key, char *cmd);
int		key_turn(t_key *key, char *cmd);
int		key_drop(t_key *key, char *cmd);
int		key_quit(t_key *key, char *cmd);
int		key_pause(t_key *key, char *cmd);
int		my_get_size(char *str, int indic);
int		def_size(t_key *key, char *cmd);
int		def_level(t_key *key, char *cmd);
int		key_mini_left(t_key *key, char *cmd);
int		key_mini_right(t_key *key, char *cmd);
int		key_mini_turn(t_key *key, char *cmd);
int		key_mini_drop(t_key *key, char *cmd);
int		key_mini_quit(t_key *key, char *cmd);
int		key_mini_pause(t_key *key, char *cmd);
int		def_mini_level(t_key *key, char *cmd);
int		without_next(t_key *key, char *cmd);
t_key		*def_key();
int		choose_flag(int ac, char **av, t_key *key);
void		my_bzero(char *str);
void		mode(int i);
void		settup();
int		find_keypad(t_all *x, char *buffer);
int		my_getnbr(char *nbr);
int		put_new_score(t_all *x);
int		len_of_nb(int nb);
char		*convert_int_to_char(int nb, char *buffer);
int		rm_line(t_all *x, t_size size);
int		test_first_line(char *str);
int		test_line(char *str, int len);
int		test_tab(t_all *x);
void		color_init();
void		my_putnbr(int nb);
char		*my_strdup(char *str);
int		call_gnl_to_end(int fd);
int		print_all(t_all *x);
t_tetrimino	def_elem(t_tetrimino res, int fd, struct dirent *file);
void		add_to_end(char *src, char *dest, int len);
int		my_get_heig_width(char *str, int indic);
t_result	new_gnl(t_result res, int i, int fd, int reset);
int		new_other_gnl(t_result res, int indic);
int		verif_return(int ret);
int		test_char(t_result res, int indic);
t_char_err	get_next_char(const int fd, int reset);
char		*re_alloc(char *src, int size);
int		free_and_malloc(int *tab, char *cmd);
void		print_with_color(int x, int color, WINDOW *plat, int y);
void		last_turn(t_tetrimino *array, int i, DIR *dir);
t_tetrimino	turn_tetri(t_tetrimino elem, t_tetrimino result, int i, int tmp);
void		add_and_remove(t_all *x, t_tetrimino *tab, int pos, char *buff);
#endif /* !HEADER_H_ */
