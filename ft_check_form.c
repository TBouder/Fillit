/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:42:02 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/17 16:22:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Helper for ft_check_form_lines_columns()
*/

static void			ft_check_helper(char *str, int i)
{
	if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
		ft_error();
	else if ((str[i - 1] == '#' || str[i - 1] == '.') && str[i] == '\0')
		ft_error();
}

/*
** This function will check if each tetrominos is a 4 x 4 square. Not 3 x 4,
** not 4 x 5, just 4 x 4
*/

static void			ft_check_form_lines_columns(char *str)
{
	int		i;
	int		len;
	int		column;

	i = 0;
	len = 0;
	column = 0;
	while (str[i])
	{
		while (str[i] == '.' || str[i] == '#')
		{
			column++;
			i++;
		}
		if (str[i] == '\n' && column != 4 && len != 4)
			ft_error();
		else if (str[i] == '\n' && column == 0 && len == 4)
			len = 0;
		else if (len > 3)
			ft_error();
		column == 4 ? len++ : 0;
		column == 4 ? column = 0 : 0;
		ft_check_helper(str, i);
		i++;
	}
}

/*
** This is the launcher for the ft_check_form_char() and the
** ft_check_form_lines_columns() functions
*/

void				ft_check_form_launcher(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
			i++;
		else
			ft_error();
	}
	ft_check_form_lines_columns(str);
}
