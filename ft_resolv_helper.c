/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:10:00 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/17 15:50:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allow us to count all the white spaces [.] between a [#] and the next one
*/

int				ft_point(char *str, int i)
{
	int		point;

	point = 0;
	while (str[i] == '.')
	{
		point++;
		i++;
	}
	return (point);
}

/*
** If s[x] = '.' this function will move forward, until the next line
** to keep the correct tetrominos (the form)
*/

void			ft_helper_forme(int *i, int *j, int len, int point)
{
	int		count;

	count = 1;
	while (len > count++)
		*j += 1;
	*i += point;
	*i -= 1;
}

/*
** This function will count the number of [.] when len < 3
*/

int				ft_count_pts(char *s, int *i)
{
	int		count;

	count = 0;
	while (s[*i] == '.' && s[*i])
	{
		count++;
		*i += 1;
	}
	return (count);
}

void			ft_checkplace_helper(int *i, int *j, int len, char *s)
{
	int		count;
	int		r_size;

	count = 0;
	r_size = (len < 4) ? len : 4;
	if (len <= 4)
	{
		count = ft_count_pts(s, i);
		len == 2 ? count -= 3 : 0;
		len == 3 ? count -= 2 : 0;
		len == 4 ? count -= 1 : 0;
		*j += count;
		*i -= 1;
	}
	else
		ft_helper_forme(i, j, len - r_size + ft_point(s, *i), ft_point(s, *i));
}
