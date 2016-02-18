/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:13:25 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/17 11:20:30 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function will print an error message and stop the program
*/

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

/*
** This function will print the final grid (or not final if we want to)
*/

void	ft_print_grid(char *grid, int size)
{
	int		j;

	j = 0;
	while (grid[j])
	{
		ft_putchar(grid[j]);
		j++;
		if (j % size == 0 && j != 0)
			ft_putchar('\n');
	}
}

/*
** This function will give us the minimum size of the grid, according to
** the size of all the tetrominos areas, +1 to secure the thing
*/

int		ft_size_grid(int nb_tetribox)
{
	int		size;
	int		i;

	size = (nb_tetribox + 1) * 4;
	i = 0;
	while ((i * i) < size)
		i++;
	return (i);
}
