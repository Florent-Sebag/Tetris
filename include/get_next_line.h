/*
** my.h for h in /home/sebag_f/Desktop/rendu/CPE_2015_getnextline
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Mon Jan  4 15:11:42 2016 Florent Sebag
** Last update Fri Mar 18 17:28:25 2016 Florent Sebag
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (1)

#endif /* !READ_SIZE */

typedef	struct	s_char_err
{
  int		err;
  char		c;
}		t_char_err;

typedef	struct	s_result
{
  t_char_err	x;
  char		*result;
  int		i;
}		t_result;

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
