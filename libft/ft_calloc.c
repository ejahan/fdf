/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:45:21 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 15:00:33 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(sizeof(char) * (size * count));
	if (!(str))
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
