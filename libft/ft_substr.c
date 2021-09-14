/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:58:30 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 16:29:21 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str2;
	unsigned int	i;

	i = 0;
	str2 = (char *)s;
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (i < len && str2[start] != '\0' && start < ft_strlen(str2))
	{
		str[i] = str2[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
