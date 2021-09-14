/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:16:28 by ejahan            #+#    #+#             */
/*   Updated: 2021/09/14 21:00:16 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_ptr;
	void	*img;
	char	*addr;
	int		**tab;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		background;
	int		column;
	int		line;
	int		screen;
	int		color;
	double	p_column;
	double	p_line;
	double	p_line_av;
	int		x;
	int		y;
	int		altitude;
	int		i;
	int		j;
	int		a;
	int		max;
	int		min;
	double	altitude2;
	int		co_alt;
}				t_fdf;

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int		recup_map(char **av, t_fdf *fdf);
char	*new_tmp(char *line, int l, int n);
void	test(t_fdf *fdf);
void	window(t_fdf *fdf);
void	test(t_fdf *fdf);
int		iso(t_fdf *fdf, int l);
double	cross_mult(double a, double b, double c);
int		ft_loop(t_fdf *fdf);
double	find_color(int x, int x2, int i, t_fdf *fdf);
double	find_color2(int x, int x2, int i, t_fdf *fdf);
void	get_color(int i, t_fdf *fdf);

#endif
