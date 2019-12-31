/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_one_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:32:30 by hopham            #+#    #+#             */
/*   Updated: 2019/11/20 17:52:18 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_neighbors(char **map)
{
	int	i;
	int	j;
	int	count_neighbors;

	i = -1;
	count_neighbors = 0;
	while (map[++i] != NULL && i < 4)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == '#')
			{
				if (j - 1 >= 0 && map[i][j - 1] == '#')
					count_neighbors++;
				if (j + 1 < 4 && map[i][j + 1] == '#')
					count_neighbors++;
				if (i - 1 >= 0 && map[i - 1][j] == '#')
					count_neighbors++;
				if (i + 1 < 4 && map[i + 1][j] == '#')
					count_neighbors++;
			}
		}
	}
	return (count_neighbors == 6 || count_neighbors == 8);
}

static char	**map_memory_allocation(void)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char**)ft_memalloc(sizeof(char*) * 5)))
		return (NULL);
	while (i < 4)
	{
		if (!(map[i] = (char*)ft_memalloc(sizeof(char) * 6)))
			return (NULL);
		i++;
	}
	return (map);
}

static int	check_line(char *line, int nbr_tetrominos)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			nbr_tetrominos++;
		if ((line[i] != '#' && line[i] != '.'))
			return (-1);
		i++;
	}
	return (nbr_tetrominos);
}

char		**check_one_map(int fd)
{
	int		i;
	int		tetrominos;
	char	*line;
	char	**map;

	tetrominos = 0;
	line = NULL;
	map = map_memory_allocation();
	i = 0;
	while (get_next_line(fd, &line) && i < 4)
	{
		if (ft_strlen(line) != 4 ||
			(tetrominos = check_line(line, tetrominos)) < 0)
			break ;
		map[i] = ft_strcat(map[i], line);
		free(line);
		line = (NULL);
		map[i][ft_strlen(map[i])] = '\n';
		i++;
		if (i == 4 && tetrominos == 4 && check_neighbors(map) != 0)
			return (map);
	}
	free(line);
	free_map(map);
	return (0);
}
