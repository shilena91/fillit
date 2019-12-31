/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:43:01 by hopham            #+#    #+#             */
/*   Updated: 2019/11/20 17:50:12 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		add_letter(t_tetris *tetromino)
{
	char	letter;

	letter = 'A';
	while (tetromino != NULL)
	{
		tetromino->letter = letter;
		tetromino = tetromino->next;
		letter++;
	}
}

static void		print_map(t_new_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->map_table[i]);
		i++;
	}
}

static int		map_count(t_map **map)
{
	int		i;
	t_map	*map_element;

	i = 0;
	map_element = *map;
	while (map_element)
	{
		map_element = map_element->next;
		i++;
	}
	return (i);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_map		**map;
	t_new_map	*new_map;
	t_tetris	*tetrominos_list;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		if (!(map = check_whole_input_map(fd)) || map_count(map) > 26)
		{
			write(1, "error\n", 6);
			return (0);
		}
		tetrominos_list = create_tetrominos_list(map);
		add_letter(tetrominos_list);
		new_map = solve_map(tetrominos_list);
		print_map(new_map);
	}
	else
		ft_putstr_fd("usage: ./fillit input_file\n", 2);
	return (0);
}
