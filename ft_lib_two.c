/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:22:51 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/15 14:30:10 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

char		*ft_strnew(size_t size)
{
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}
