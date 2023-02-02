/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:57:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/02 13:32:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- draw pixel --------------------*/
static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_L && y >= 0 && y < WINDOW_H)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

/* --------------- draw a line --------------------*/

void draw_x(t_img *img, t_model model, int x, int y)
{
	float step;
	int i;
	float x1;
	float y1;
	
	x1 = model.map2d[y][x - 1].x;
	y1 = model.map2d[y][x - 1].y;
	step = ft_delta(model.map2d, &model.delta, x, y);
	while (i < step && (x1 <= model.map2d[y][x].x || y1 <= model.map2d[y][x].y))
	{
		img_pix_put(img, x1, y1, model.map2d[y][x].color);
		x1 += model.delta.d_x;
		y1 += model.delta.d_y;
		i++;
	}
}

void draw_y(t_img *img, t_model model, int x, int y)
{
	
}

void draw_line(t_img *img, t_model model)
{
	int y = 0;
	int x;
	
	ft_3d_to_2d(&model);
	while (y < hight)
	{
		x = 0;
		while (x < width)
		{
			if ( x == 0 && y == 0)
				img_pix_put(img, model.map2d[y][x].x, model.map2d[y][x].y, model.map2d[y][x].color);
			else if (x == 0)
				draw_y();
			else if (y == 0)
				draw_x(img, model, x, y);
			else
			{
				draw_x();
				draw_y();
			}
		}
	}
}