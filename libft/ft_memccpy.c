/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:00:49 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 16:21:47 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	d;

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	d = (unsigned char)c;
	while (i < n)
	{
		s2[i] = s1[i];
		if (s1[i] == d)
			return (&s2[i + 1]);
		i++;
	}
	return (NULL);
}
