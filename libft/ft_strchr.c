/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:35:09 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 16:24:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i++] != c)
	{
		if (str[i] == '\0')
			return (NULL);
	}
	str = &str[i - 1];
	return (str);
}
