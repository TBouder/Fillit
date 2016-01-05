/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:04:23 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/18 14:58:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Just a malloc things
*/

static char		**ft_attrib(char **tab, int nb)
{
	int		i;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * nb + 1)))
		return (NULL);
	while (i < nb + 1)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		i++;
	}
	return (tab);
}

/*
** This function will cut the ending line \n for one tetrominos
*/

static char		*ft_cut_ln(char *str, int nb)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!(res = (char*)malloc(sizeof(char) * ((nb * 4) * 4) + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i] != '\n')
		{
			res[j++] = str[i];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

/*
** This function will extract the tetrominos from the file, as a single
** string with \n
*/

char			*ft_extract_string(char *file, int fd)
{
	char	buffer;
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0)
		i++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (!(string = (char *)malloc(sizeof(char *) * (i + 1))) && fd != -1)
		return (NULL);
	while (read(fd, &buffer, 1) > 0)
		string[j++] = buffer;
	close(fd);
	string[j] = '\0';
	return (string);
}

/*
** This function will split the strings in [nb] tetrimonos, so in multiple
** substrings
*/

char			**ft_split_string(char *str, int nb)
{
	char	**tab;
	int		i;
	int		j;

	str = ft_cut_ln(str, nb);
	tab = NULL;
	tab = ft_attrib(tab, nb);
	j = 0;
	nb = 0;
	i = 0;
	while (str[nb])
	{
		if (nb % 16 == 0 && nb != 0)
		{
			tab[i++][j] = '\0';
			j = 0;
		}
		tab[i][j++] = str[nb++];
	}
	tab[i][j] = '\0';
	return (tab);
}
