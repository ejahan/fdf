/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:24:46 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 16:20:52 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len_int(long n)
{
	int	len_int;

	len_int = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		len_int++;
	}
	return (len_int + 1);
}

char	*ft_itoa(int n)
{
	char	*dst;
	long	nb;
	int		len;

	nb = n;
	len = ft_len_int(nb) + (nb < 0);
	dst = (char *)malloc(sizeof(char) * len + 1 + (n < 0));
	if ((dst) == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		*dst = '-';
	}
	dst[len--] = '\0';
	while (len >= (n < 0))
	{
		dst[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}
