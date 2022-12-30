/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:24:28 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/30 15:09:05 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

# define	WINDOW_L 900
# define	WINDOW_H 900
# define 	WINDOW_NAME "fdf"
# define	ERROR 0
# define	GREEN 0x0000FF00
# define	RED 0x00960018
# define	WHITE 0xFFFFFF
# define	BLACK 0x00000

/* --------------- draw pixel --------------------*/
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_L && y >= 0 && y < WINDOW_H)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

/* --------------- draw a square --------------------*/
void draw_squares(t_img *img, int x1, int y1, t_point3d end, int color) 
{
	int x;
	int y = y1;
	int	len_x = (50 * (end.x - 1)) + x1;
	int	len_y = (50 * (end.y - 1)) + y1;
	while (y <= len_y)
	{	
		x = x1;
		if (y % 50 == 0)
			while (x <= len_x)
				img_pix_put(img, x++, y, color);
		else
			while (x <= len_x)
			{
				if (x % 50 == 0)
					img_pix_put(img, x, y, color);
				x++;
			}
		y++;
	}
}

// void draw_isosquare(t_img *img, int x1, int y1, int x2, int y2, int color)
// {
	// 
// }

/* --------------- draw a line --------------------*/
void ft_draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
{
	float step;
	float x;
	float y;
	float delta_x;
	float delta_y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	if (fabs(delta_x) >= fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	delta_x = delta_x / step;
	delta_y = delta_y / step;
	x = x1;
	y = y1;
	while (0 < step)
	{
		img_pix_put(img, x, y, color);
		x += delta_x;
		y += delta_y;
		step--;
	}
}

/* --------------- draw a rect --------------------*/
int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.lenght)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

/* --------------- background color --------------------*/
void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WINDOW_H)
	{
		j = 0;
		while (j <= WINDOW_L)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}
/* --------------- window design --------------------*/
int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (ERROR);
	render_background(&data->img, BLACK);
	render_rect(&data->img, (t_rect){0, 0, WINDOW_L, 50, RED});
	render_rect(&data->img, (t_rect){0, WINDOW_H - 50, WINDOW_L, 50, RED});
	draw_squares(&data->img, 200, 200, *data->map->final, WHITE);
	//ft_draw_line(&data->img, 155, 150, 255, 250, GREEN);
	//ft_draw_line(&data->img, 200, 200, 100, 300, GREEN);

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* --------------- Mouse event --------------------*/
int	mouse_handle(int mousekey, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	(void) data;
	if (mousekey == 1)
		ft_printf("Left Click\n");
	else if (mousekey == 2)
		ft_printf("Right Click\n");
	else if (mousekey == 3)
		ft_printf("Middle Click\n");
	else if (mousekey == 4)
		ft_printf("Scroll UP\n");
	else if (mousekey == 5)
		ft_printf("Scroll DOWN\n");
	else if (mousekey == 6)
		ft_printf("Scroll right\n");
	else if (mousekey == 7)
		ft_printf("Scroll left\n");
	else
		ft_printf("%d\n", mousekey);
	return (0);
}

/* --------------- key event "esc to quit" --------------------*/
int	handle_jeypress(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
	}
	printf("keypress: %d\n", key);
	return (0);
}

/* ++++++++++++++++++++++++++++++ Main +++++++++++++++++++++++++++++++++++ */
int	main(int ac, char **av)
{
	t_data	data;
	int fd;

	if (ac > 2)
	{
		ft_printf("Erreur, trop d'arguments\n");
		exit (0);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		fdf_creat_map(fd, av[1], data.map);
	}
	else 
	{
		ft_printf("Erreur, aucuns arguments valide\n");
		exit (0);
	}
	ft_printf("X vaut %d et Y vaut %d\n", data.map->final->x, data.map->final->y);
		
	data.mlx_ptr = mlx_init();// initialisation de mlx
	if (!data.mlx_ptr)
		return (ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_H, WINDOW_L, WINDOW_NAME);// creation de la fenetre
	if (!data.win_ptr)
		ft_free_arrays(data.mlx_ptr, NULL, "Error, no win_ptr\n");

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_L, WINDOW_H);//creation de la nouvelle image
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);//adresse de l'image
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr,2, 1L << 0, &handle_jeypress, &data);//event "key_press"
	mlx_hook(data.win_ptr, 4, 0, mouse_handle, &data);// event "mouse_action"

	mlx_loop(data.mlx_ptr);//loop gardant la fenetre ouverte

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}

int	ft_count_char(char *str, char c)
{
	int	i = 0;
	int	c_count = 0;
	while(str[i])
	{
		if (str[i] == c)
			c_count++;
		i++;
	}
	return (c_count);
}

/* ++++++++++++++++++++++++++++++ Map_parsing +++++++++++++++++++++++++++++++++++ */
/* --------------- Line_count --------------------*/
int count_lines(int fd, t_point3d *coord_y)
{
	(void) coord_y;
	int		nb_line = 0;
	char	*line;

	if (fd == 0)
		return (ERROR);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
		nb_line++;
	}
	close(fd);
	coord_y->y = nb_line;
	return (nb_line);
}

/* --------------- Parse_line --------------------*/
int	fdf_parse_line(char *str, int index, t_coord *map)
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
	len--;
	map->final->x = len;
	map->map[index] = (int *)malloc((len) * sizeof(int));
	if (!map->map[index])
	{
		ft_free_2da(split, len);
		ft_free_arrays(NULL, NULL, "Error malloc_map.map\n");
	}
	i = -1;
	while (++i < len)
		map->map[index][i] = ft_atoi(split[i]);
	ft_free_2da(split, len + 1);
	return (1);
}

/* --------------- Creat_map --------------------*/
int	fdf_creat_map(int fd,char *map_file, t_coord *data_map)
{
	char	*line;
	int		nb_line;
	int		i;

	nb_line = count_lines(fd, data_map->final);
	data_map->map = (int**)malloc((nb_line + 1) * sizeof(int*));
	if (!data_map->map)
		return (ERROR);
	data_map->map[nb_line] = NULL;
	fd = open(map_file, O_RDONLY);
	i = -1;
	while (++i < nb_line && fd != 0)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!fdf_parse_line(line, i, data_map))
			return (ERROR);
		free(line);
		line = NULL;
	}
	return (1);
}