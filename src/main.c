/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:24:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/10 15:54:33 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void ft_init(t_model *init)
{
	init->offset_x = WINDOW_WIDTH / 2;
	init->offset_y = WINDOW_HIGHT / 2;
	init->zoom = 50;
}

/* --------------- window design --------------------*/
int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (ERROR);
	ft_draw_line(&data->img, &data->map);

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* ++++++++++++++++++++++++++++++ Main +++++++++++++++++++++++++++++++++++ */
int	main(int ac, char **av)
{
	t_data	data;
	int fd = 0;
	
	ft_init(&data.map);
	if (ac > 2)
	{
		ft_printf("Erreur, trop d'arguments\n");
		exit (0);
	}
	else if (ac == 2)
		fdf_creat_map(fd, av[1], &data.map);
	else 
	{
		ft_printf("Erreur, aucuns arguments valide\n");
		exit (0);
	}
	
	// ft_printf("Y vaut %d et X vaut %d\n\n", data.map.hight, data.map.width);
	// int i = 0;
	// int j;
	// while (i < data.map.hight)
	// {
		// j = 0;
		// while (j < data.map.width)
		// {
			// printf("la Valeur de %d.%d = %f\n", i, j, data.map.map3d[i][j]);
			// j++;
		// }
		// ft_printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		// i++;
	// }
	// ft_3d_to_2d(&data.map);
	data.mlx_ptr = mlx_init();// initialisation de mlx
	if (!data.mlx_ptr)
		return (ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HIGHT, WINDOW_NAME);// creation de la fenetre
	if (!data.win_ptr)
		ft_free_arrays(data.mlx_ptr, NULL, "Error, no win_ptr\n");

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HIGHT);//creation de la nouvelle image
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);//adresse de l'image
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_keypress, &data);//event "key_press"
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_mouse_hook(data.win_ptr, &mouse_handle, &data);// event "mouse_action"
	
	mlx_loop(data.mlx_ptr);//loop gardant la fenetre ouverte

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}