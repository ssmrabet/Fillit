/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:03:27 by pchartie          #+#    #+#             */
/*   Updated: 2016/07/26 11:14:13 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*transforme_tray(int index, char *file_str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char*)malloc(sizeof(char) * 16 + 1);
	while (i < 16)
	{
		if (file_str[j] == '#')
		{
			ret[i] = index + 'A';
			i++;
		}
		if (file_str[j] == '.')
		{
			ret[i] = file_str[j];
			i++;
		}
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	copy_tray(char *file_str, t_tris *tab)
{
	int index;
	int start;

	start = 0;
	index = 0;
	while (index < valid_tray(file_str))
	{
		tab[index].tetriminos = transforme_tray(index, &file_str[start]);
		tab[index].pos_in_map = -1;
		start = NEXT_PIECE_POS + start;
		index++;
	}
}

void		exit_err(void)
{
	ft_putstr("error\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_result	res;
	t_tris		tab[27];
	char		*file_str;

	ft_bzero(tab, 27 * sizeof(*tab));
	init_with_points(&res);
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit file\n");
		exit(0);
	}
	file_str = ft_open_file(argv[1]);
	if (!file_str)
		exit_err();
	if (valid_tray(file_str) > 0)
	{
		copy_tray(file_str, tab);
		res.edge_map = ft_sqrt(valid_tray(file_str) * 4);
		diez_position(tab);
		tetris_resolution(&res, tab, 0);
	}
	else
		exit_err();
	return (0);
}
