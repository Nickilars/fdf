/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:24:28 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/22 15:01:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

# define	WINDOW_L 900
# define	WINDOW_H 900
# define 	WINDOW_NAME "fdf"
# define	MLX_ERROR 1
# define	GREEN 0x0000FF00
# define	RED 0x00960018
# define	WHITE 0xFFFFFF
# define	BLACK 0x000000

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
void draw_squares(t_img *img, int x1, int y1, int x2, int y2, int color) 
{
	int x;
	int y = y1;

	while (y <= y2)
	{	
		x = x1;
		if (y % 50 == 0)
			while (x <= x2)
				img_pix_put(img, x++, y, color);
		else
			while (x <= x2)
			{
				if (x % 50 == 0)
					img_pix_put(img, x, y, color);
				x++;
			}
		y++;
	}
}

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

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	render_background(&data->img, BLACK);
	render_rect(&data->img, (t_rect){0, 0, WINDOW_L, 50, RED});
	render_rect(&data->img, (t_rect){0, WINDOW_H - 50, WINDOW_L, 50, RED});
	draw_squares(&data->img, 0, 0, WINDOW_H, WINDOW_L, WHITE);
	ft_draw_line(&data->img, 100, 100, 200, 200, GREEN);
	ft_draw_line(&data->img, 200, 200, 100, 300, GREEN);

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* --------------- key event "esc to quit" --------------------*/
int	handle_keypress(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit (0);
	}
	printf("Keypress: %d\n", key);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		ft_printf("Erreur, trop d'arguments");
		exit (0);
	}
	if (ac > 1)
		ft_parse_map(av[1]);
	t_data	data;

	data.mlx_ptr = mlx_init();// initialisation de mlx
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_H, WINDOW_L, WINDOW_NAME);// creation de la fenetre
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (MLX_ERROR);
	}

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_L, WINDOW_H);//creation de la nouvelle image
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);//adresse de l'image
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);//event "key_press"

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

int	ft_free_funct(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	ft_printf("%s", str3);
	exit (0);
}

int	ft_parse_map(char *map_file)
{
	char **map;
	char *line;
	char *cpy_line;
	int i = 0;
	int fd;

	fd = open(map_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (cpy_line == NULL)
		{
			cpy_line = ft_strdup(line);
			if (cpy_line == NULL)		
				ft_free_funct(cpy_line, line, "Error strdup");
		}
		else
		{
			cpy_line = ft_strjoin(cpy_line, line);
			if (cpy_line == NULL)
				ft_free_funct(cpy_line, line, "Error strjoin");
		}
		free (line);
	}
	map = ft_split(cpy_line, '\n');
	if (!map)
	{
		free(cpy_line);
		cpy_line = NULL;
		ft_printf("Error split");
		return (MLX_ERROR);
	}
	free (cpy_line);
	while (map[i])
		ft_printf("%s\n", map[i++]);
	
	return (0);
}