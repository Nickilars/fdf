/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:57:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/20 13:35:05 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Calcul delta --------------------*/
int	ft_delta(int x1, int y1, int x2, int y2, t_delta *delta)
{
	float x;
	float y;
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
// void draw_squares(t_img *img, t_point2d start, t_point3d len, int color)
// {
	// int x;
	// int y = start.y;
	// int	len_x = (50 * (len.x - 1)) + start.x;
	// int	len_y = (50 * (len.y - 1)) + start.y;
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
void ft_draw_line(t_img *img, t_coord *start, int index_x, int index_y, int index_z, int color)
{
	float step;
	int point_x;
	int point_y;

	point_x = start->init.x + (index_x * 25);
	point_y = start->init.y + (index_y * 25);
	start->init.x2 = point_x - 25;
	start->init.y2 = point_y - (index_z * 25) 
	step = ft_delta(point_x, point_y, start->init.x2, start->init.y2 )
	
	while (0 < step)
	{
		img_pix_put(img, start.x, start.y, color);
		start->init.x -= delta_x;
		start->init.y -= delta_y;
		step--;
	}
}
// 
/* ------------------------ draw iso -----------------------------*/
void ft_draw_iso(t_img *img, t_coord *coord, int color)
{
	int x;
	int y = 0;
	int x_tmp = coord->init.x;
	int y_tmp = coord->init.y;
	
	while (y < coord.len.ligne)
	{
		x = 0;
		if (x < coord.len.colonne)
		{
			if (coord->delta[i][j] > 0)
				coord->len.z = coord->map[i][j];
			if (x == 0 && y == 0)
				x = 0;
			else if (x == 0)
				ft_draw_line(img, coord, x, y, coord.len.z, color);
			else if (y == 0)
				ft_draw_line(img, coord, x, y, coord.len.z, color);
			else 
			{
				ft_draw_line(img, coord, x, y, coord.len.z, color);
				ft_draw_line(img, coord, x, y, coord.len.z, color);
			}
		}
	}
}