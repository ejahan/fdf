/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:07:33 by ejahan            #+#    #+#             */
/*   Updated: 2021/07/28 14:28:55 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*first_if(int i, int *ret, char *line, char *buff)
{
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
	{
		*ret = -1;
		return (0);
	}
	line[i] = '\0';
	*ret = 1;
	if (buff[0] == '\0')
		*ret = 0;
	return (line);
}

char	*recursive(int fd, int i, int *ret)
{
	char	buff[1];
	int		rd;
	char	*line;

	line = NULL;
	rd = read(fd, buff, 1);
	if (rd == -1)
		return (0);
	if (rd == 0)
		buff[0] = '\0';
	if (buff[0] == '\n' || buff[0] == '\0')
		return (first_if(i, ret, line, buff));
	else
	{
		line = recursive(fd, i + 1, ret);
		if (line == NULL)
		{
			*ret = -1;
			return (0);
		}
		line[i] = buff[0];
	}
	return (line);
}

int	get_next_line2(int fd, char **line)
{
	int	ret;

	*line = recursive(fd, 0, &ret);
	return (ret);
}
