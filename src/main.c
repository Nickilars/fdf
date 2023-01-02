/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:24:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/02 11:00:43 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void draw_isosquare(t_img *img, int x1, int y1, int x2, int y2, int color)
// {
	// 
// }

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