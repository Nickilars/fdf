/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:22:16 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/10 13:44:48 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void black_screen(t_img *img)
{
	t_point2d s = {0, 0, BLACK};

	while (s.y <= WINDOW_HIGHT)
	{
		s.x = 0;
		while (s.x <= WINDOW_WIDTH)
			img_pix_put(img, s.x++, s.y, s.color);
		s.y++;
	}
}
// int	ft_delta(t_point2d s, t_point2d f, t_delta *d)
// {
	// float delta_x;
	// float delta_y;
	// float step;
	// static int i = 0;
// 
	// delta_x = s.x - f.x;
	// delta_y = s.y - f.y;
	// if (fabs(delta_x) >= fabs(delta_y))
		// step = fabs(delta_x);
	// else
		// step = fabs(delta_y);
	// d->d_x = delta_x / step;
	// d->d_y = delta_y / step;
	// i++;
	// printf("%f // %d\n", step, i);
	// return (step);
// }
// 
// void ft_3d_to_2d(t_model *model)
// {
	// int x;
	// int y;
	// float ex = cos(30);
	// float ey = cos(60);
	// 
	// y = 0;
	// model->map2d = (t_point2d **)malloc(model->hight * sizeof(t_point2d *));
	// if (!model->map2d)
		// exit (0);
	// while (y < model->hight)
	// {
		// model->map2d[y] = (t_point2d *)malloc(model->width * sizeof(t_point2d));
		// if (!model->map2d[y])
			// exit (0);
		// x = 0;
		// while (x < model->width)
		// {
			// model->map2d[y][x].x = ((ex * x) - (ex * x)) * model->zoom + model->offset_x;
			// model->map2d[y][x].y = (((ey * y) + (ey * x)) - model->map3d[y][x])
			 	// * model->zoom + model->offset_y;
			// model->map2d[y][x].color = GREEN;
			// x++;
		// }
		// y++;
	// }
// }
