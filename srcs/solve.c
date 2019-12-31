/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:53:06 by hopham            #+#    #+#             */
/*   Updated: 2019/11/20 19:07:14 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				solve(t_tetris *tetromino, t_new_map *map)
{
	int			x;
	int			y;

	if (tetromino == NULL)
		return (1);
	y = 0;
	while (y < map->size - tetromino->height + 1)
	{
		x = 0;
		while (x < map->size - tetromino->width + 1)
		{
			if (put_tetromino(tetromino, map, x, y))
			{
				if (solve(tetromino->next, map))
					return (1);
				else
					set_character(tetromino, map, position(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

static size_t	tetromino_count(t_tetris *list)
{
	int	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

static int		ft_sqrt(int nbr)
{
	int		size;

	size = 2;
	while (size * size < nbr)
		size++;
	return (size);
}

t_new_map		*solve_map(t_tetris *tetromino_list)
{
	int			size;
	t_new_map	*new_map;

	size = ft_sqrt(tetromino_count(tetromino_list) * 4);
	new_map = create_new_map(size);
	while (!solve(tetromino_list, new_map))
	{
		free_new_map(new_map);
		size++;
		new_map = create_new_map(size);
	}
	return (new_map);
}
