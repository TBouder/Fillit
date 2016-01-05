/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_form.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:19:35 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/18 14:57:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_nigma(char *str)
{
	if (ft_strstr(str, "..#.##..#..") == NULL)
		return (1);
	else if (ft_strstr(str, "..#..##.#..") == NULL)
		return (1);
	else if (ft_strstr(str, "...#.##.#...") == NULL)
		return (1);
	else if (ft_strstr(str, ".##.#...#..") == NULL)
		return (1);
	else if (ft_strstr(str, "..#...#.##.") == NULL)
		return (1);
	else if (ft_strstr(str, "..#.##...#.") == NULL)
		return (1);
	else if (ft_strstr(str, ".#...##.#..") == NULL)
		return (1);
	return (0);
}

/*
** It is the launcher for the functions in ft_extract_form.c. All the forms
** will be put in the 2D char forms
*/

void			ft_extract_forms(char **str, int nb_tetribox, char **forms)
{
	int		i;
	char	c;

	i = 0;
	c = 'A';
	while (i <= nb_tetribox)
	{
		forms[i] = (char *)ft_forme(str[i], c);
		i++;
		c++;
	}
}

/*
** This function will, detect the tetrominos and extract it as a string on
** the top left (if the tetrominos is on the bottom right, this will cut
** all the [.]) before the start of the tetrominos, to keep only this one
*/

char			*ft_forme(char *str, char c)
{
	int		i;
	char	*form;

	i = 0;
	form = NULL;
	if (ft_nigma(str) == 0)
		ft_error();
	else
		form = ft_strtrim_char(str, '.');
	while (form[i])
	{
		form[i] == '#' ? form[i] = c : 0;
		i++;
	}
	return (form);
}
