/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:55:35 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/15 14:23:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void		*ft_memalloc(size_t size)
{
	void	*buffer;

	if ((buffer = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(buffer, size);
	return (buffer);
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;

	if ((ptr = (char*)malloc(sizeof(*ptr) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
}
