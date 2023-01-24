/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:34 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/24 12:46:23 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
	{
		ft_printf("Scroll UP\n");
		data->map.len.len += 10;
	}
	else if (mousekey == 5)
	{
		ft_printf("Scroll DOWN\n");
		data->map.len.len -= 10;
	}
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
	else if (key == 126)
		data->map.init.y -= 10;
	else if (key == 125)
		data->map.init.y += 10;
	else if (key == 124)
		data->map.init.x += 10;
	else if (key == 123)
		data->map.init.x -= 10;
	
	printf("keypress: %d\n", key);
	return (0);
}

//int	close_window(int mousekey, t_data *data)