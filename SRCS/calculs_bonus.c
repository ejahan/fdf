/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:28:24 by ejahan            #+#    #+#             */
/*   Updated: 2021/09/14 20:59:44 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	link_point_up(t_fdf *fdf, double x, double x2, double y)
{
	int		i;
	double	y2;
	double	m;
	double	p;

	i = x;
	if (fdf->tab[fdf->j][fdf->i] == 0)
		y2 = y - fdf->p_line_av
			- (fdf->tab[fdf->j - 1][fdf->i] * fdf->altitude2);
	else
		y2 = y - fdf->p_line_av
			+ (fdf->altitude - fdf->tab[fdf->j - 1][fdf->i] * fdf->altitude2);
	m = (y2 - y) / (x2 - x);
	p = -m * x + y;
	while (i < x2)
	{
		get_color((int)find_color(x, x2, i, fdf), fdf);
		my_mlx_pixel_put(fdf, i, m * i + p, fdf->color);
		i++;
	}
}

static void	link_point_side(t_fdf *fdf, int x, int y)
{
	int		i;
	double	x2;
	double	y2;
	double	m;
	double	p;

	x2 = x - fdf->a;
	i = x2;
	if (fdf->tab[fdf->j][fdf->i] == 0)
		y2 = y - fdf->p_line_av
			- (fdf->tab[fdf->j][fdf->i - 1] * fdf->altitude2);
	else
		y2 = y - fdf->p_line_av
			+ (fdf->altitude - fdf->tab[fdf->j][fdf->i - 1] * fdf->altitude2);
	m = (y - y2) / (x - x2);
	p = -m * x + y;
	while (i < x)
	{
		get_color((int)find_color2(x, x2, i, fdf), fdf);
		my_mlx_pixel_put(fdf, i, m * i + p, fdf->color);
		i++;
	}
}

static	void	link_point(t_fdf *fdf, int x, int x2, int y)
{
	fdf->p_line_av = (0.82 * fdf->a + fdf->p_line) - fdf->p_line;
	if (fdf->j < fdf->line && fdf->j != 0)
		link_point_up(fdf, x, x2, y);
	if (fdf->i < fdf->column && fdf->i != 0)
		link_point_side(fdf, x, y);
	fdf->i++;
	if (fdf->i == fdf->column)
	{
		fdf->i = 0;
		fdf->j++;
	}
}

static void	iso_loop(t_fdf *fdf, int x2, int j)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < fdf->column)
	{
		x = x2 + fdf->a * i;
		get_color(fdf->tab[j][i], fdf);
		fdf->altitude = fdf->tab[j][i] * fdf->altitude2;
		y = 0.82 * x + fdf->p_column - fdf->altitude;
		my_mlx_pixel_put(fdf, x, y, fdf->color);
		link_point(fdf, x, x2 + fdf->a * (i + 1), y);
		i++;
	}
}

int	iso(t_fdf *fdf, int l)
{
	int	y;
	int	x2;
	int	j;

	j = 0;
	fdf->x = l / 2 + fdf->line * fdf->a;
	fdf->y = (fdf->screen - 0.82 * fdf->a * (fdf->line + fdf->column - 1)) / 2;
	if (fdf->max != 0)
		fdf->altitude2 = cross_mult(fdf->y / 2, 1, fdf->max);
	if (fdf->altitude2 > fdf->a / 2)
		fdf->altitude2 = fdf->a / 3;
	while (j < fdf->line)
	{
		x2 = fdf->x - j * fdf->a;
		fdf->p_line = 0.82 * fdf->x + fdf->y;
		y = -0.82 * x2 + fdf->p_line;
		fdf->p_column = -0.82 * x2 + y;
		iso_loop(fdf, x2, j);
		j++;
	}
	return (1);
}
