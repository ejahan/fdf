/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:44:54 by elisa             #+#    #+#             */
/*   Updated: 2020/12/01 11:49:13 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (i < 10 && i >= 0)
	{
		ft_putchar_fd(i + 48, fd);
	}
	else if (i < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-i, fd);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
