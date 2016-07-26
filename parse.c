/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:03:27 by pchartie          #+#    #+#             */
/*   Updated: 2016/07/26 11:15:08 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_neighbour_case(char *tray, int index)
{
	int count_neighbour;

	count_neighbour = 0;
	if ((index + 1) % 5 != 4)
	{
		if (tray[index + RIGHT_NEIGHBOUR] == '#')
			count_neighbour++;
	}
	if ((index - 1) % 5 != 4 && index)
	{
		if (tray[index - LEFT_NEIGHBOUR] == '#')
			count_neighbour++;
	}
	if (index - 5 >= 0)
	{
		if (tray[index - BOTT_NEIGHBOUR] == '#')
			count_neighbour++;
	}
	if (index + 5 < 20)
	{
		if (tray[index + TOP_NEIGHBOUR] == '#')
			count_neighbour++;
	}
	return (count_neighbour);
}

static int	valid_tetriminos(char *tray)
{
	int	i;
	int total;
	int j;

	i = 0;
	total = 0;
	while (i < LENGTH_TRAY)
	{
		if (tray[i] == '#')
		{
			if ((j = valid_neighbour_case(tray, i)) > 0)
				total = total + j;
		}
		i++;
	}
	return (total == 6 || total == 8);
}

static int	count_case(char *file_str)
{
	int i;
	int count_case;

	i = 0;
	count_case = 0;
	while (i < LENGTH_TRAY)
	{
		if (file_str[i] != '#' && file_str[i] != '.' && file_str[i] != '\n')
			return (-1);
		if ((i + 1) % 5 == 0)
		{
			if (file_str[i] != '\n')
				return (ERROR);
		}
		if (file_str[i] == '#')
			count_case++;
		i++;
	}
	if (file_str[LENGTH_TRAY] && file_str[LENGTH_TRAY] != '\n')
		return (ERROR);
	return (count_case == 4);
}

int			valid_tray(char *file_str)
{
	int i;
	int counter_tray;
	int is_first_launch;

	i = 0;
	counter_tray = 0;
	is_first_launch = 1;
	while (file_str[i])
	{
		if (file_str[i] == '\n' && !is_first_launch)
			file_str++;
		if ((count_case(&file_str[i])) <= 0)
			return (ERROR);
		if ((valid_tetriminos(&file_str[i]) == 0))
			return (ERROR);
		counter_tray++;
		i = i + LENGTH_TRAY;
		is_first_launch = 0;
	}
	return (counter_tray);
}
