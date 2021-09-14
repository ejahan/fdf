/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:49:44 by ejahan            #+#    #+#             */
/*   Updated: 2021/09/14 21:00:03 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	recup_line_nbr(char **av, t_fdf *fdf)
{
	int		fd;
	char	*line;

	fdf->line = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line2(fd, &line) == 1)
	{
		fdf->line++;
		free(line);
	}
	free(line);
	if (get_next_line2(fd, &line) == -1)
	{
		close(fd);
		return (-1);
	}
	free(line);
	close(fd);
	return (1);
}

static void	recup_column_nbr(char *line, t_fdf *fdf, int *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i] != '\0')
			j++;
		while (line[i] != '\0' && line[i] != ' ')
			i++;
	}
	fdf->column = j;
	*a = 1;
}

static int	fill_tab2(char *line, t_fdf *fdf, int n)
{
	static int	i = 0;
	static int	a = 0;
	int			j;
	char		*tmp;

	j = 0;
	if (a == 0)
		recup_column_nbr(line, fdf, &a);
	fdf->tab[i] = malloc(sizeof(int) * fdf->column);
	if (!(fdf->tab[i]))
		return (-1);
	while (j < fdf->column)
	{
		tmp = new_tmp(line, ft_strlen(line), n);
		n = 1;
		if (tmp == NULL)
			return (-1);
		fdf->tab[i][j] = ft_atoi(tmp);
		free(tmp);
		j++;
	}
	i++;
	return (1);
}

static int	fill_tab(char **av, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	i = get_next_line2(fd, &line);
	while (i == 1 || i == 0)
	{
		if (i == 0)
		{
			free(line);
			close(fd);
			return (1);
		}
		i = fill_tab2(line, fdf, 0);
		free(line);
		if (i == 1)
			i = get_next_line2(fd, &line);
	}
	close(fd);
	return (-1);
}

int	recup_map(char **av, t_fdf *fdf)
{
	int	i;

	i = recup_line_nbr(av, fdf);
	if (i == -1)
		return (-1);
	fdf->tab = malloc(sizeof(int *) * fdf->line);
	if (!(fdf->tab))
		return (-1);
	i = fill_tab(av, fdf);
	if (i == -1)
		return (-1);
	return (1);
}
