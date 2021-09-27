/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:15:53 by ejahan            #+#    #+#             */
/*   Updated: 2021/09/17 05:36:14 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_quit(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->mlx)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->mlx_ptr)
			mlx_destroy_window(fdf->mlx, fdf->mlx_ptr);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	while (i < fdf->line)
	{
		free(fdf->tab[i]);
		i++;
	}
	free(fdf->tab);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_quit_test(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->line)
	{
		free(fdf->tab[i]);
		i++;
	}
	free(fdf->tab);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int key_code, t_fdf *fdf)
{
	if (key_code == 65307)
		ft_quit(fdf);
	return (0);
}

void	window(t_fdf *fdf)
{
	int	screen_x;
	int	screen_y;

	fdf->mlx = mlx_init();
	mlx_get_screen_size(fdf->mlx, &screen_x, &screen_y);
	if (screen_x >= screen_y)
		fdf->screen = screen_y;
	else
		fdf->screen = screen_x;
	fdf->mlx_ptr = mlx_new_window(fdf->mlx, fdf->screen, fdf->screen, "fdf");
	fdf->img = mlx_new_image(fdf->mlx, fdf->screen, fdf->screen);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	test(fdf);
	mlx_hook(fdf->mlx_ptr, 2, (1L << 0), key_press, fdf);
	mlx_hook(fdf->mlx_ptr, 33, (1L << 2), ft_quit, fdf);
	mlx_loop_hook(fdf->mlx, ft_loop, fdf);
	mlx_loop(fdf->mlx);
}	

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		i;
	int		screen_x;

	screen_x = 0;
	if (ac == 2)
	{
		i = recup_map(av, &fdf);
		if (i == -1)
			return (1);
		window(&fdf);
	}
	return (0);
}
