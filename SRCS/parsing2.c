/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:26:12 by ejahan            #+#    #+#             */
/*   Updated: 2021/09/14 21:00:06 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*new_tmp(char *line, int l, int n)
{
	char		*tmp;
	static int	i = 0;

	if (n == 0)
	{
		tmp = ft_strdup(line);
		i = 0;
		return (tmp);
	}
	if (line[i] == '-' || line[i] == '+')
		i++;
	while (ft_isalnum((int)line[i]) == 1 || line[i] == ',')
		i++;
	while (line[i] == ' ')
		i++;
	tmp = ft_substr(line, i, l - i);
	return (tmp);
}
