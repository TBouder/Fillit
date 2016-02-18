/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:20:20 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/17 16:01:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_lintdor
{
	int			squ;
	int			tetri;
}				t_lintdor;

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *s);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strtrim_char(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);

void			ft_check_form_launcher(char *str);
void			ft_check_content_launcher(char **str, int nb_tetribox);
char			*ft_forme(char *str, char c);
char			*ft_extract_string(char *file, int fd);
char			**ft_split_string(char *str, int nb);
int				ft_optimization(char *grid, char **str, t_lintdor size, int j);
int				ft_point(char *str, int i);
void			ft_resolv_helper_start(char *s, int *i, int *j);
void			ft_helper_forme(int *i, int *j, int len, int point);
void			ft_error(void);
void			ft_print_grid(char *grid, int size);
int				ft_size_grid(int nb_tetribox);
void			ft_extract_forms(char **str, int nb_tetribox, char **forms);
int				ft_count_pts(char *s, int *i);
void			ft_checkplace_helper(int *i, int *j, int len, char *s);

#endif
