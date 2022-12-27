/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:24:28 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/27 14:29:46 by nrossel          ###   ########.fr       */
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
		return (MLX_ERROR);
	render_background(&data->img, BLACK);
	render_rect(&data->img, (t_rect){0, 0, WINDOW_L, 50, RED});
	render_rect(&data->img, (t_rect){0, WINDOW_H - 50, WINDOW_L, 50, RED});
	draw_squares(&data->img, 200, 200, 700, 700, WHITE);
	ft_draw_line(&data->img, 155, 150, 255, 250, GREEN);
	ft_draw_line(&data->img, 200, 200, 100, 300, GREEN);

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
/* --------------- main --------------------*/
int	main(int ac, char **av)
{
	t_data	data;
	int **map;

	if (ac > 2)
	{
		ft_printf("Erreur, trop d'arguments");
		exit (0);
	}
	if (ac == 1 || ac == 0)
		map = ft_parse_map(av[1]);

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
	mlx_hook(data.win_ptr,2, 1L << 0, &handle_keypress, &data);//event "key_press"
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

int	ft_free_funct(char *str1, char *str2, char *str3)
{
	free(str1);
	if (str2 != NULL)
		free(str2);
	ft_printf("%s", str3);
	exit (0);
}

int **ft_atoi_fdf(char **map)
{
	int **tab_map = NULL;
	char **cpy_map = NULL;
	int i = 0;
	int j;
	int k;

	while (map[i])
	{
		cpy_map = ft_split(map[i], ' ');
		j = 0;
		k = 0;
		while (cpy_map[j])
		{
			tab_map[i][j] = ft_atoi(cpy_map[j]);
			j++;
		}
		while(cpy_map[k])
		{
			free(cpy_map[k++]);
		}
		i++;
	}
	return (tab_map);
}

/* --------------- map_parsing --------------------*/
int	**ft_parse_map(char *map_enter)
{
	char *line;
	char *cpy_line;
	int fd;
	char **map_exit = NULL;
	int **map;

	fd = open(map_enter, O_RDONLY);
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
	map_exit = ft_split(cpy_line, '\n');
	if (!map_exit)
		ft_free_funct(cpy_line, NULL, "Error split");
	free (cpy_line);
	map = ft_atoi_fdf(map_exit)
	return (map);
}
