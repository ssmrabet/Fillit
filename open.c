/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:03:27 by pchartie          #+#    #+#             */
/*   Updated: 2016/07/26 11:14:40 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_size_file(const char *file)
{
	int		fd;
	char	buffer;
	int		size;

	size = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		return (-1);
	}
	if (fd > 0)
	{
		while (read(fd, &buffer, 1))
		{
			size++;
			if (size > MAX_TRAYCASE_SIZE)
			{
				return (-1);
			}
		}
	}
	close(fd);
	return (size);
}

char		*ft_open_file(const char *file)
{
	int		fd;
	char	*str_file;
	int		size_file;
	char	buffer;
	int		i;

	i = 0;
	size_file = ft_size_file(file);
	if (size_file <= 0)
		return (NULL);
	str_file = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if ((str_file = (char *)malloc(sizeof(char) * size_file + 1)))
	{
		while (read(fd, &buffer, 1))
		{
			str_file[i] = buffer;
			i++;
		}
		str_file[i] = '\0';
	}
	close(fd);
	return (str_file);
}
