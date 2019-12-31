/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_whole_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:43:01 by hopham            #+#    #+#             */
/*   Updated: 2019/11/20 17:53:20 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_mapadd_end(t_map **alst, t_map *new)
{
	t_map	*elem;

	elem = *alst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	return ;
}

static t_map	*new_valid_map(char **map)
{
	t_map	*map_element;

	map_element = (t_map*)ft_memalloc(sizeof(t_map));
	map_element->valid_map = map;
	map_element->next = NULL;
	return (map_element);
}

t_map			**check_whole_input_map(int fd)
{
	t_map		**map_list;
	char		**map;
	char		*empty_line;

	empty_line = NULL;
	if (!(map = check_one_map(fd)))
		return (NULL);
	if (!(map_list = (t_map**)malloc(sizeof(t_map*))))
	{
		free_map(map);
		return (NULL);
	}
	*map_list = new_valid_map(map);
	while (get_next_line(fd, &empty_line))
	{
		if (*empty_line != '\0' || !(map = check_one_map(fd)))
		{
			delete_map(map_list, &empty_line);
			return (NULL);
		}
		else
			ft_mapadd_end(map_list, new_valid_map(map));
		free(empty_line);
	}
	return (map_list);
}
