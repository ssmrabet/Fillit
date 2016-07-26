/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:03:27 by pchartie          #+#    #+#             */
/*   Updated: 2016/07/26 11:15:32 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetris_resolution(t_result *res, t_tris *piece, int index)
{
	if (piece[index].tetriminos == NULL)
	{
		print_map(res);
		exit(0);
	}
	else
	{
		while (add_tetri_in_map(res, &piece[index]))
		{
			tetris_resolution(res, piece, index + 1);
			delete_tetriminos(res, piece[index]);
		}
		piece[index].pos_in_map = -1;
		if (index == 0)
		{
			res->edge_map++;
			tetris_resolution(res, piece, index);
		}
	}
}

int		coordinate_transformation(int i, t_result *res, t_tris piece)
{
	return (((i % 4) - (piece.diez_position % 4))
		+ (((i / 4) - (piece.diez_position / 4)) * res->edge_map)
		+ piece.pos_in_map);
}

/*
** verifi si l'emplacement dans la map est dispo pour placer une seule
** partie du tetriminos
*/

char	check_value_in_map(int i, t_result *res, t_tris piece)
{
	int x;

	x = coordinate_transformation(i, res, piece);
	if (x >= (res->edge_map * res->edge_map))
		return ('#');
	if ((x % res->edge_map) >
		(coordinate_transformation(piece.diez_position, res, piece)
			% res->edge_map))
	{
		if ((i % 4 < piece.diez_position % 4))
			return ('#');
	}
	else if (i % 4 > piece.diez_position % 4)
		return ('#');
	return (res->map[coordinate_transformation(i, res, piece)]);
}

/*
** verifi si l'emplacement dans la map est dispo pour placer la
** totaliter du tetriminos
*/

int		have_place_for_tetri(t_result *res, t_tris piece)
{
	int i;

	i = piece.diez_position;
	while (i < 16)
	{
		if (piece.tetriminos[i] != '.')
		{
			if (check_value_in_map(i, res, piece) != '.')
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

/*
** place le tetriminos dans la map
*/

int		add_tetri_in_map(t_result *res, t_tris *piece)
{
	piece->pos_in_map++;
	if (piece->pos_in_map < (res->edge_map * res->edge_map))
	{
		if (have_place_for_tetri(res, *piece) > 0)
		{
			put_tetriminos(res, *piece);
			return (1);
		}
		else
			return (add_tetri_in_map(res, piece));
	}
	else
	{
		piece->pos_in_map = -1;
		return (0);
	}
}
