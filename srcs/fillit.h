/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:18:52 by hopham            #+#    #+#             */
/*   Updated: 2019/11/20 17:49:55 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 32
# define MAX_FD 4864
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_map
{
	char			**valid_map;
	struct s_map	*next;
}				t_map;

typedef struct	s_position
{
	int		x;
	int		y;
}				t_position;

typedef struct	s_tetris
{
	t_position			*positions[4];
	char				letter;
	int					height;
	int					width;
	struct s_tetris		*next;
}				t_tetris;

typedef struct	s_new_map
{
	int		size;
	char	**map_table;
}				t_new_map;

int				get_next_line(const int fd, char **line);
char			**check_one_map(int fd);
t_map			**check_whole_input_map(int fd);
void			ft_del(void *content, size_t size);
t_tetris		*create_tetrominos_list(t_map **map_list);
t_new_map		*create_new_map(int size);
int				solve(t_tetris *tetromino, t_new_map *map);
t_new_map		*solve_map(t_tetris *tetrimino_list);
int				put_tetromino(t_tetris *tetromino, t_new_map *map,
								int x, int y);
t_position		*position(int x, int y);
void			set_character(t_tetris *tetromino, t_new_map *map,
								t_position *pos, char c);
void			free_map(char **map);
void			free_tetrominos(t_tetris *tetrominos);
void			free_new_map(t_new_map *map);
void			delete_map(t_map **map, char **empty_line);

#endif
