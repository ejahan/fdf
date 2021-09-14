/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:42:31 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 16:23:03 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	c = (char)c;
	str = (char *)d;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
