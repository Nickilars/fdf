/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:57:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/20 16:33:37 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Calcul delta --------------------*/
int	ft_delta(int x1, int y1, int x2, int y2, t_delta *delta)
{
	float x;
	float y;
	float step;

	x = x1 - x2;
	y = y1 - y2;
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
void ft_draw_line(t_img *img, t_coord *start, int map_x, int map_y, int z, int color)
{
	float step;
	float step_tmp;
	int x;
	int x_tmp;
	int y;

	x = start->init.x + (map_x * 25);
	x_tmp = x;
	y = start->init.y + (map_y * 25);
	if (map_x != 0)
		start->init.x2 = x - 25;
	else
		start->init.x2 = start->init.x;
	if (map_y != 0)
		start->init.y2 = y - (z * 25);
	else
		start->init.y2 = start->init.x2;
	step = ft_delta(x, y, start->init.x2, start->init.y2, &start->delta);
	step_tmp = step;
	while (0 < step_tmp)
	{
		img_pix_put(img, x, y, color);
		x -= start->delta.x;
		step_tmp--;
	}
	step_tmp = step;
	x = x_tmp;
	while(0 < step_tmp)
	{
		img_pix_put(img, x, y, color);
		y -= start->delta.y;
		step_tmp--;
	}
}
// 
/* ------------------------ draw iso -----------------------------*/
void ft_draw_iso(t_img *img, t_coord *coord, int color)
{
	int x;
	int y = -1;
	// int x_tmp = coord->init.x;
	// int y_tmp = coord->init.y;
	
	while (++y < coord->len.ligne)
	{
		x = -1;
		while (++x < coord->len.colonne)
		{
			//coord->len.z = coord->map[y][x];
			if (x == 0 && y == 0)
				x = 0;
			else if (x == 0)
				ft_draw_line(img, coord, x, y, coord->len.z, color);
			else if (y == 0)
				ft_draw_line(img, coord, x, y, coord->len.z, color);
			else 
				ft_draw_line(img, coord, x, y, coord->len.z, color);
		}
	}
}