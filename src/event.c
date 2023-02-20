/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:34 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/20 16:33:18 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_zoom(int key, t_model *map)
{
	t_point2d	p;

	p.x = 0;
	p.y = 0;
	p.color = GREEN;
	while (p.y < map->hight)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (map->map3d[(int)p.y][(int)p.x] != 0)
			{
				if (key == 13)
					map->map3d[(int)p.y][(int)p.x]++;
				else if (key == 1)
					map->map3d[(int)p.y][(int)p.x]--;
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

/* --------------- Mouse event --------------------*/
int	mouse_handle(int mousekey, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (mousekey == 4)
		data->map.zoom += 1;
	else if (mousekey == 5)
		data->map.zoom -= 1;
	return (0);
}

/* --------------- key event "esc to quit" --------------------*/
int	handle_keypress(int key, t_data *data)
{
	if (key == 53)
		exit (0);
	else if (key == 126)
		data->map.offset_y += 20;
	else if (key == 125)
		data->map.offset_y -= 20;
	else if (key == 123)
		data->map.offset_x += 20;
	else if (key == 124)
		data->map.offset_x -= 20;
	else if (key == 13 || key == 1)
		ft_zoom(key, &data->map);
	return (0);
}

int	close_window(int key, t_data *data)
{
	(void) key;
	(void) data;
	exit (0);
}
