/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:31:33 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/12 17:27:43 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_position	*position(int x, int y)
{
	t_position	*position;

	position = (t_position*)ft_memalloc(sizeof(t_position));
	position->x = x;
	position->y = y;
	return (position);
}

void		set_character(t_tetris *tetromino, t_new_map *map,
						t_position *pos, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	while (count < 4)
	{
		i = tetromino->positions[count]->x;
		j = tetromino->positions[count]->y;
		map->map_table[pos->y + j][pos->x + i] = c;
		count++;
	}
	ft_memdel((void **)&pos);
}

int			put_tetromino(t_tetris *tetromino, t_new_map *map, int x, int y)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	while (count < 4)
	{
		i = tetromino->positions[count]->x;
		j = tetromino->positions[count]->y;
		if (map->map_table[y + j][x + i] != '.')
			return (0);
		count++;
	}
	set_character(tetromino, map, position(x, y), tetromino->letter);
	return (1);
}

t_new_map	*create_new_map(int size)
{
	t_new_map	*new_map;
	int			i;
	int			j;

	if (!(new_map = (t_new_map*)ft_memalloc(sizeof(t_new_map))))
		return (NULL);
	new_map->size = size;
	if (!(new_map->map_table = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_map->map_table[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			new_map->map_table[i][j] = '.';
			j++;
		}
		i++;
	}
	return (new_map);
}
