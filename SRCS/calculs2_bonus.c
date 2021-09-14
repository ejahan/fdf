/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:25:04 by ejahan            #+#    #+#             */
/*   Updated: 2021/09/14 20:59:53 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	recup_max(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fdf->max = 0;
	fdf->min = 0;
	while (j < fdf->line)
	{
		i = 0;
		while (i < fdf->column)
		{
			if (fdf->tab[j][i] > fdf->max)
				fdf->max = fdf->tab[j][i];
			if (fdf->tab[j][i] < fdf->min)
				fdf->min = fdf->tab[j][i];
			i++;
		}
		j++;
	}
	fdf->min = -1 * fdf->min;
	if (fdf->min > fdf->max)
		fdf->max = fdf->min;
}

void	test(t_fdf *fdf)
{
	int	l;

	fdf->i = 0;
	fdf->j = 0;
	fdf->p_line_av = 0;
	fdf->color = create_trgb(21, 255, 255, 255);
	recup_max(fdf);
	fdf->a = (fdf->screen - fdf->screen / 12) / (fdf->line + fdf->column + 1);
	l = fdf->screen - fdf->a * (fdf->line + fdf->column);
	iso(fdf, l);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_ptr, fdf->img, 0, 0);
}

void	get_color(int i, t_fdf *fdf)
{
	fdf->color = create_trgb(21, 0, 130, 130);
	if (i > 0)
	{
		fdf->co_alt = (int)cross_mult(255.0, i, fdf->max);
		fdf->color = create_trgb(21, fdf->co_alt, 100, 100);
	}
	if (i < 0)
	{
		fdf->co_alt = (int)cross_mult(155, -i, fdf->min);
		fdf->color = create_trgb(21, fdf->co_alt, 100, 100 + fdf->co_alt);
	}
}

double	find_color(int x, int x2, int i, t_fdf *fdf)
{
	double	m;
	double	p;
	double	alt;

	m = (double)(fdf->tab[fdf->j][fdf->i]
			- fdf->tab[fdf->j - 1][fdf->i]) / (double)(x - x2);
	p = (double)fdf->tab[fdf->j][fdf->i] - m * (double)x;
	alt = m * i + p;
	return (alt);
}

double	find_color2(int x, int x2, int i, t_fdf *fdf)
{
	double	m;
	double	p;
	double	alt;

	m = (double)(fdf->tab[fdf->j][fdf->i]
			- fdf->tab[fdf->j][fdf->i - 1]) / (double)(x - x2);
	p = (double)fdf->tab[fdf->j][fdf->i] - m * (double)x;
	alt = m * i + p;
	return (alt);
}
