/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:00:15 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/16 11:28:53 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Line_count --------------------*/
static int	count_lines(int fd, char *map_file, t_model *coord_y)
{
	int		nb_line;
	char	*line;

	nb_line = 0;
	line = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd <= 0 || !map_file || ft_strnstr(map_file, ".fdf", 30) == NULL)
		ft_free_arrays(NULL, NULL, "Erreur,[2] argument invalide\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		nb_line++;
	}
	if (nb_line < 1)
		ft_free_arrays(NULL, NULL, "Erreur, [3] map invalide");
	line = NULL;
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

	if (!str)
		return (ERROR);
	split = ft_split(str, ' ');
	if (!split)
		return (ERROR);
	len = 0;
	while (split[len])
		len++;
	if (len < 1)
		ft_free_arrays((char *)map->map3d, NULL, "Erreur,[5] map invalide");
	map->width = len;
	map->map3d[index] = (float *)malloc((len) * sizeof(float));
	if (!map->map3d[index])
		ft_free_2da(split, "Erreur,[6] malloc_map.map\n");
	i = -1;
	while (++i < len)
		map->map3d[index][i] = (float) ft_atoi(split[i]);
	ft_free_2da(split, NULL);
	return (1);
}

/* --------------- Creat_map --------------------*/
int	fdf_creat_map(int fd, char *map_file, t_model *map)
{
	char	*line;
	int		nb_line;
	int		i;

	nb_line = count_lines(fd, map_file, map);
	map->map3d = (float **)malloc(nb_line * sizeof(float *));
	if (!map->map3d)
		ft_free_arrays(NULL, NULL, "Erreur,[4] map3d non-crée");
	fd = open(map_file, O_RDONLY);
	i = -1;
	while (++i < nb_line && fd != 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!fdf_parse_line(line, i, map))
			ft_free_arrays(NULL, NULL, "Erreur,[7] fdf_parse_line non-passé");
		free(line);
		line = NULL;
	}
	close(fd);
	return (1);
}
