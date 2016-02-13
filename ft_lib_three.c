/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:14:18 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/18 14:58:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		while (s1[i + j] == s2[j] && s2[j])
			j++;
		if (s2[j] == '\0')
			return (&((char*)s1)[i]);
		i++;
		j = 0;
	}
	return (NULL);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (s == NULL || !(buffer = ft_strnew(len)) || len > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		buffer[i] = ((char *)s)[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static int		count_spaces_st(char const *s, char c)
{
	int		i;
	int		custom_char;

	i = 0;
	custom_char = 0;
	while (s[i] == c)
	{
		i++;
		custom_char++;
	}
	return (custom_char);
}

static int		count_spaces_nd(char const *s, char c)
{
	int		j;
	int		custom_char;

	j = 1;
	custom_char = 0;
	while (s[ft_strlen(s) - j] == c)
	{
		j++;
		custom_char++;
	}
	return (custom_char);
}

char			*ft_strtrim_char(char const *s, char c)
{
	char	*str;
	int		custom_char;

	if (s == NULL)
		return (NULL);
	custom_char = count_spaces_st(s, c) + count_spaces_nd(s, c);
	str = (char *)malloc(sizeof(char) * ft_strlen(s) - custom_char);
	str = ft_strsub(s, count_spaces_st(s, c), ft_strlen(s)
		- count_spaces_nd(s, c));
	str[ft_strlen(s) - custom_char] = '\0';
	return (str);
}
