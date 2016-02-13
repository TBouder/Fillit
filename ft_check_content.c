/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:24 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/18 14:58:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This fonction will count the number of [#] and call the error function
** (ft_error()) if the result is not 4, for each tetrominos
*/

static void		ft_check_nb_diaiz(char **str, int nb_tetribox)
{
	int		i;
	int		j;
	int		nb_diaiz;

	i = 0;
	while (i < nb_tetribox)
	{
		nb_diaiz = 0;
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
				nb_diaiz++;
			j++;
		}
		if (nb_diaiz != 4)
			ft_error();
		i++;
	}
}

/*
** This function will check if the tetrominos are valid. ALL OF THEM.
** EVEN 10.000 ! So much ! Whoa ! Incredible ! Amazing !
** n = number || s = string || p = position
*/

static int		ft_check_each_tetribox(char *s, int n, int p)
{
	if (s[p] == '#' && s[p + 1] == '#' && n < 4 && (p + 1) % 4 != 0 && n++)
	{
		n = ft_check_each_tetribox(s, n, p + 1);
		return (n == 4) ? n : -1;
	}
	else if (s[p] == '#' && s[p + 2] == '#' && n < 4 && (p / 4 != (p + 2) / 4)
		&& (s[p + 3] == '#' || s[p - 1] == '#') && n++)
	{
		n = ft_check_each_tetribox(s, n, p + 2);
		return (n == 4) ? n : -1;
	}
	else if (s[p] == '#' && s[p + 3] == '#' && n < 4 && (p / 4 != (p + 3) / 4)
		&& (s[p + 4] == '#' || s[p - 1] == '#') && n++)
	{
		n = ft_check_each_tetribox(s, n, p + 3);
		return (n == 4) ? n : -1;
	}
	else if (s[p] == '#' && s[p + 4] == '#' && n < 4 && n++)
	{
		n = ft_check_each_tetribox(s, n, p + 4);
		return (n == 4) ? n : -1;
	}
	return (n);
}

/*
** This is the launcher for all the content tests
*/

void			ft_check_content_launcher(char **str, int nb_tetribox)
{
	int		i;
	int		j;

	i = 0;
	ft_check_nb_diaiz(str, nb_tetribox);
	while (i < nb_tetribox)
	{
		j = 0;
		while (str[i][j] != '#')
			j++;
		if (ft_check_each_tetribox(str[i], 1, j) != 4)
			ft_error();
		i++;
	}
}
