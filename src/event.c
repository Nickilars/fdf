/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:34 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/02 10:59:05 by nrossel          ###   ########.fr       */
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