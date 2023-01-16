/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:57:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/16 15:33:55 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Calcule delta --------------------*/
int	ft_delta(t_point2d start, t_point3d end, t_delta *delta)
{
	float x;
	float y;

	x = delta->x;
	y = delta->y;
	float step;
	x = end.x - start.x;
	y = end.y - start.y;
	if (fabs(y) >= fabs(x))
		step = fabs(x);
	else
		step = fabs(y);
	delta->x = x / step;
	delta->y = y / step;
	return (step);
}

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
// void draw_squares(t_img *img, t_point2d start, t_point3d end, int color)
// {
	// int x;
	// int y = start.y;
	// int	len_x = (50 * (end.x - 1)) + start.x;
	// int	len_y = (50 * (end.y - 1)) + start.y;
	// while (y <= len_y)
	// {	
		// x = start.x;
		// if (y % 50 == 0)
			// while (x <= len_x)
				// img_pix_put(img, x++, y, color);
		// else
			// while (x <= len_x)
			// {
				// if (x % 50 == 0)
					// img_pix_put(img, x, y, color);
				// x++;
			// }
		// y++;
	// }
// }

/* --------------- draw a line --------------------*/
// void ft_draw_line(t_img *img, t_point2d start, t_point3d end, int color)
// {
	// float step;
	// float delta_x;
	// float delta_y;
// 
	// end.x = end.x * 50;
	// end.y = end.y * 50;
	// step = ft_delta(start, end, &end);
	// 
	// while (0 < step)
	// {
		// img_pix_put(img, start.x, start.y, color);
		// start.x += delta_x;
		// start.y += delta_y;
		// step--;
	// }
// }

/* ------------------------ draw iso -----------------------------*/
void ft_draw_iso(t_img *img, t_point2d start, t_point3d end, int color)
{
	float step;
	int x;
	int y;
	int len;
	
	len = 50;
	x = start.x;
	y = start.y;
	step = ft_delta(start, end, &end.delta);
	//if ((end.x + (end.delta.x * len)) >= WINDOW_H)
		//len = 10;
	end.x = end.x * len;
	end.y = end.y * len;
	while(y <= end.y)
	{
		x = start.x;
		if (y % len == 0)
			while(x <= end.x)
				img_pix_put(img, x++, y, color);
		else
		{
			while (x <= end.x)
			{
				img_pix_put(img, x, y, color);
				x += len;
			}
		}
		start.x += end.delta.x;
		end.x += end.delta.x;
		y += end.delta.x;
	}
}