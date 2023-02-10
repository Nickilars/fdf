/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:00:15 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/10 14:54:11 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Line_count --------------------*/
static int count_lines(int fd, char *map_file, t_model *coord_y)
{
	int		nb_line = 0;
	char	*line = NULL;

	fd = open(map_file, O_RDONLY);
	if (fd <= 0 || !map_file)
		return (ERROR);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
		nb_line++;
	}
	line = NULL;
	// if (ft_strncmp(map_file, "../test_map/42.fdf", 14) == 0)
		// nb_line--;
	close(fd);
	coord_y->hight = nb_line;
	return (nb_line);
}

/* --------------- Parse_line --------------------*/
static int	fdf_parse_line(char *str, int index, t_model *map)
{
	char	**split;
	int		len;
	int		i;

	if(!str)
		return (ERROR);
	split = ft_split(str, ' ');
	if (!split)
		return (ERROR);
	len = 0;
	while (split[len])
		len++;
	//len--;
	map->width = len;
	map->map3d[index] = (float *)malloc((len) * sizeof(float));
	if (!map->map3d[index])
	{
		ft_free_2da(split, index);
		ft_free_arrays(NULL, NULL, "Error malloc_map.map\n");
	}
	i = -1;
	while (++i < len)
		map->map3d[index][i] = (float) ft_atoi(split[i]);
	ft_free_2da(split, len + 1);
	return (1);
}

/* --------------- Creat_map --------------------*/
int	fdf_creat_map(int fd,char *map_file, t_model *map)
{
	char	*line = NULL;
	int		nb_line;
	int		i;

	nb_line = count_lines(fd, map_file, map);
	map->map3d = (float **)malloc(nb_line * sizeof(float *));
	if (!map->map3d)
		return (ERROR);
	fd = open(map_file, O_RDONLY);
	i = -1;
	while (++i < nb_line && fd != 0)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!fdf_parse_line(line, i, map))
			return (ERROR);
		free(line);
		line = NULL;
	}
	close(fd);
	return (1);
}