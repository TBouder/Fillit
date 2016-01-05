/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:52:42 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/17 18:44:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This is a recursiv function : it will try to fill the grid of a size x
** If it can not, the size will be increase by 1.
*/

static int			ft_launch_resolv(char *grid, char **forms, t_lintdor size)
{
	if (ft_optimization(grid, forms, size, 0) == 0)
	{
		size.squ++;
		grid = ft_memalloc(size.squ * size.squ + 1);
		ft_memset(grid, '.', size.squ * size.squ);
		ft_launch_resolv(grid, forms, size);
	}
	else
	{
		ft_print_grid(grid, size.squ);
		return (0);
	}
	return (1);
}

/*
** This function will launch all the test (form, content), will extract all
** the tetrominos ans finaly launch the function to resolv the main algo
*/

static int			ft_launcher(char *string)
{
	char			*grid;
	char			**splited_string;
	char			**forms;
	t_lintdor		size;

	if ((size.tetri = (ft_strlen(string) + 1) / 21) > 26)
		ft_error();
	if (size.tetri == 0)
		ft_error();
	size.squ = ft_size_grid(ft_strlen((string) + 1) / 21);
	forms = (char **)malloc(sizeof(char *) * ft_strlen((string) + 1) / 21);
	grid = ft_memalloc(size.squ * size.squ + 1);
	ft_memset(grid, '.', size.squ * size.squ);
	ft_check_form_launcher(string);
	splited_string = ft_split_string(string, size.tetri);
	ft_check_content_launcher(splited_string, size.tetri);
	ft_extract_forms(splited_string, ft_strlen((string) + 1) / 21, forms);
	ft_launch_resolv(grid, forms, size);
	ft_strdel(&grid);
	ft_strdel(forms);
	ft_strdel(splited_string);
	return (1);
}

int					main(int ac, char **av)
{
	int		fd;
	char	*string;

	string = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac == 2 && fd != -1)
	{
		string = ft_extract_string(av[1], fd);
		ft_launcher(string);
		free(string);
	}
	else
		ft_error();
	return (0);
}
