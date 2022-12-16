/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:24:28 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/16 11:34:05 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

# define	WINDOW_LENGHT 900
# define	WINDOW_HEIGHT 900

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

int	handle_no_event(void *data)
{
	(void) data;
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}


int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_LENGHT, "fdf");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (1);
	}

	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free(data.mlx_ptr);
}