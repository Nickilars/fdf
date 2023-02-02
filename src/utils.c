/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:22:16 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/02 14:00:48 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_delta(t_point2d **map, t_delta *d, int x, int y)
{
	float delta_x;
	float delta_y;
	float step;

	delta_x = map[y][x].x - map[y][x - 1].x;
	delta_y = map[y][x].y - map[y][x - 1].y;
	if (fabs(delta_x) >= fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	d->d_x = delta_x / step;
	d->d_y = delta_y / step;
	return (step);
}

void ft_3d_to_2d(t_model *model)
{
	int x;
	int y;
	float ex = cos(30);
	float ey = cos(60);
	
	y = 0;
	model->map2d = (t_point2d **)malloc(model->hight * sizeof(t_point2d *));
	if (!model->map2d)
		exit (0);
	while (y < model->hight)
	{
		model->map2d[y] = (t_point2d *)malloc(model->width * sizeof(t_point2d));
		if (!model->map2d[y])
			exit (0);
		x = 0;
		while (x < model->width)
		{
			model->map2d[y][x].x = (ex * x + -ex * x) * model->zoom + model->offset_x;
			model->map2d[y][x].y = (ey * x + ey * x - model->map3d[y][x])
			 	* model->zoom + model->offset_y;
			model->map2d[y][x].color = GREEN;
			x++;
		}
		y++;
	}
}
