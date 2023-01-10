/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:57:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/02 10:58:27 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
void draw_squares(t_img *img, int x1, int y1, t_point3d end, int color) 
{
	int x;
	int y = y1;
	int	len_x = (50 * (end.x - 1)) + x1;
	int	len_y = (50 * (end.y - 1)) + y1;
	while (y <= len_y)
	{	
		x = x1;
		if (y % 50 == 0)
			while (x <= len_x)
				img_pix_put(img, x++, y, color);
		else
			while (x <= len_x)
			{
				if (x % 50 == 0)
					img_pix_put(img, x, y, color);
				x++;
			}
		y++;
	}
}

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