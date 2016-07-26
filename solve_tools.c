/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:03:27 by pchartie          #+#    #+#             */
/*   Updated: 2016/07/26 11:15:58 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_result *res)
{
	int i;

	i = 0;
	while (i < res->edge_map)
	{
		write(1, res->map + (i * res->edge_map), res->edge_map);
		write(1, "\n", 1);
		i++;
	}
}

void	delete_tetriminos(t_result *res, t_tris piece)
{
	int i;

	i = 0;
	while (i < (res->edge_map * res->edge_map))
	{
		if (res->map[i] == piece.tetriminos[piece.diez_position])
			res->map[i] = '.';
		i++;
	}
}

void	put_tetriminos(t_result *res, t_tris piece)
{
	int i;

	i = piece.diez_position;
	while (i < 16)
	{
		if (piece.tetriminos[i] != '.')
			res->map[coordinate_transformation(i, res, piece)] =
			piece.tetriminos[i];
		i++;
	}
}
