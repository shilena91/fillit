/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:24:33 by hopham            #+#    #+#             */
/*   Updated: 2019/11/18 11:10:44 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
	ft_memdel((void **)map);
	free(map);
}

void		free_tetrominos(t_tetris *tetrominos)
{
	while (tetrominos)
	{
		free(tetrominos);
		tetrominos = tetrominos->next;
	}
}

void		free_new_map(t_new_map *map)
{
	int	i;

	i = 0;
	while (map && map->map_table[i])
	{
		ft_strdel(&(map->map_table[i]));
		i++;
	}
	free(map->map_table);
	ft_memdel((void **)&map);
}

void		delete_map(t_map **map, char **empty_line)
{
	t_map	*a_map;
	int		i;
	t_map	*tmp;

	a_map = *map;
	while (a_map)
	{
		tmp = a_map->next;
		i = 0;
		while (a_map->valid_map[i])
		{
			ft_strdel(&(a_map->valid_map[i]));
			i++;
		}
		free_map(a_map->valid_map);
		free(a_map);
		a_map = tmp;
	}
	ft_strdel(empty_line);
	free(map);
}
