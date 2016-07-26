/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:03:27 by pchartie          #+#    #+#             */
/*   Updated: 2016/07/26 11:13:50 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define TOP_NEIGHBOUR 5
# define BOTT_NEIGHBOUR 5
# define LEFT_NEIGHBOUR 1
# define RIGHT_NEIGHBOUR 1
# define LENGTH_TRAY 20
# define ERROR -1
# define MAX_TRAYCASE_SIZE 546
# define NEXT_PIECE_POS 21

typedef struct	s_result
{
	char	map[200];
	int		edge_map;
}				t_result;

typedef struct	s_tris
{
	char	*tetriminos;
	int		diez_position;
	int		pos_in_map;
}				t_tris;

void			ft_init_struct(t_result *res);
void			diez_position(t_tris *tab);
void			init_with_points(t_result *res);
int				ft_sqrt(int nb);
int				valid_tray(char *file_str);
int				coordinate_transformation(int i, t_result *res, t_tris piece);
void			put_tetriminos(t_result *res, t_tris piece);
void			delete_tetriminos(t_result *res, t_tris piece);
void			print_map(t_result *res);
char			get_pos(char *tetris, int x, int y);
void			tetris_resolution(t_result *res, t_tris *piece, int index);
int				add_tetri_in_map(t_result *res, t_tris *piece);
char			*ft_open_file(const char *file);

#endif
