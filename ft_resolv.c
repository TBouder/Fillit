/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:07:06 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/17 11:16:38 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Before starting to put a tetrominos in the grid, this function allow us to
** check if the grid is free for it and if there is no other tetrominos
*/

static int		ft_check_form(char *g, char *s, int len, int index)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == '.' && i++)
		j++;
	while (s[i])
	{
		if (s[i] != '.' && s[i + 1] != '.' && s[i + 1] != '\0'
			&& (j + index) % len == len - 1 && j + index != 0)
			return (0);
		if ((s[i] == '.' && g[j] == '.') || (s[i] == '.' && g[j] != '.'))
			ft_checkplace_helper(&i, &j, len, s);
		else if (s[i] != '.' && g[j] != '.')
			return (0);
		i++;
		j++;
	}
	return (1);
}

/*
** Retaking the function ft_check_form(), this function will just put the
** tetrominos in the grid.
*/

static void		ft_place_form(char *g, char *s, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == '.')
	{
		i++;
		j++;
	}
	while (s[i])
	{
		if (s[i] != '.' && g[j] == '.')
			g[j] = s[i];
		else if ((s[i] == '.' && g[j] == '.') || (s[i] == '.' && g[j] != '.'))
			ft_checkplace_helper(&i, &j, len, s);
		i++;
		j++;
	}
}

/*
** This function will clear the grid until the main character of *str
*/

static int		ft_clear_tetro(char *grid, char *str)
{
	int		i;
	char	c;
	int		pos;

	pos = 0;
	i = 0;
	while (str[i] == '.')
		i++;
	c = str[i];
	i = 0;
	while (grid[i])
	{
		if (grid[i] == c && pos == 0)
			pos = i + 1;
		if (grid[i] >= c && grid[i] != '.')
			grid[i] = '.';
		i++;
	}
	return (pos);
}

/*
** Hearth of the programm, recurs'
*/

int				ft_optimization(char *grid, char **str, t_lintdor size, int j)
{
	int		i;

	i = 0;
	if (size.tetri == 0)
		return (1);
	while (i < size.squ * size.squ)
	{
		if ((grid[i] == '.' || str[j][0] == '.')
			&& ft_check_form(&grid[i], str[j], size.squ, i) == 1)
		{
			ft_place_form(&grid[i], str[j], size.squ);
			size.tetri -= 1;
			j++;
			if (ft_optimization(grid, str, size, j) == 1)
				return (1);
			else
			{
				j--;
				size.tetri += 1;
				ft_clear_tetro(&grid[i], str[j]);
			}
		}
		i++;
	}
	return (0);
}
