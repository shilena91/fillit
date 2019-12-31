/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrominos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:44:58 by hopham            #+#    #+#             */
/*   Updated: 2019/11/20 19:07:17 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_position	*check_line(char **line, t_position *pos)
{
	int				index;
	t_position		*position;

	index = 0;
	while ((*line)[index])
	{
		if ((*line)[index] == '#')
		{
			(*line)[index] = '.';
			position = (t_position *)ft_memalloc(sizeof(*position));
			position->x = index;
			if (pos->x > index)
				pos->x = index;
			if (pos->y < index)
				pos->y = index;
			return (position);
		}
		index++;
	}
	return (NULL);
}

static void			check_tetrominos_cordinate(t_tetris *tetris, t_map *map)
{
	int			line_num;
	int			line_start;
	int			i;
	char		*line;
	t_position	*pos;

	line_start = -1;
	line_num = -1;
	i = 0;
	pos = position(4, 0);
	while (++line_num < 4 && (line = ft_strdup(map->valid_map[line_num])))
	{
		while (i < 4 && (tetris->positions[i] = check_line(&line, pos)))
		{
			if (line_start == -1)
				line_start = 0;
			tetris->positions[i]->y = line_start;
			i++;
		}
		line_start != -1 ? line_start++ : line_start;
		free(line);
	}
	while (line_num-- > 0)
		tetris->positions[line_num]->x -= pos->x;
	free(pos);
}

static void			check_tetrominos_size(t_tetris *tetrominos_pos, t_map *map)
{
	int			line_num;
	int			index;
	char		*line;
	t_position	*pos;

	line_num = -1;
	index = 0;
	pos = position(4, 0);
	tetrominos_pos->height = 0;
	while (++line_num < 4)
	{
		line = ft_strdup(map->valid_map[line_num]);
		if (ft_strchr(line, '#'))
			tetrominos_pos->height += 1;
		while (index < 4 && (tetrominos_pos->positions[index] =
				check_line(&line, pos)))
		{
			free(tetrominos_pos->positions[index]);
			index++;
		}
		free(line);
	}
	tetrominos_pos->width = pos->y - pos->x + 1;
	free(pos);
}

t_tetris			*create_tetrominos_list(t_map **map_list)
{
	t_tetris	*tetrominos_pos;
	t_tetris	*tetrominos_list;
	t_map		*map;

	if (!(tetrominos_pos = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	map = *map_list;
	tetrominos_list = tetrominos_pos;
	while (map)
	{
		check_tetrominos_size(tetrominos_pos, map);
		check_tetrominos_cordinate(tetrominos_pos, map);
		if ((map = map->next))
		{
			if (!(tetrominos_pos->next =
				(t_tetris*)ft_memalloc(sizeof(t_tetris))))
			{
				tetrominos_pos = tetrominos_list;
				free_tetrominos(tetrominos_pos);
				return (NULL);
			}
			tetrominos_pos = tetrominos_pos->next;
		}
	}
	return (tetrominos_list);
}
