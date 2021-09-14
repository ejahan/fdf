/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:13:01 by elisa             #+#    #+#             */
/*   Updated: 2021/06/03 16:28:43 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i] && set[i] != c)
		i++;
	if (set[i] == '\0')
		return (1);
	else
		return (0);
}

static int	s_len(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	*str;

	i = s_len(s1) - 1;
	n = 0;
	k = i + 1;
	while (is_set(s1[n], set) == 0 && s1[n])
		n++;
	j = 0;
	while (is_set(s1[i], set) == 0 && i > n)
	{
		i--;
		j++;
	}
	str = malloc(sizeof(char) * (k - j - n + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (n < (k - j))
		str[i++] = s1[n++];
	str[i] = '\0';
	return (str);
}
