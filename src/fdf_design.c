/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:57:11 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/24 12:59:54 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Calcul delta --------------------*/
int	ft_delta(t_point2d *coord, t_delta *delta)
{
	float delta_x;
	float delta_y;
	float step;

	delta_x = coord->x2 - coord->x1;
	delta_y = coord->y2 - coord->y1;
	if (fabs(delta_x) >= fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	delta->x = delta_x / step;
	delta->y = delta_y / step;
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
void ft_draw_x_axe(t_img *img, t_coord *start, int x, int z, int color)
{
	float step;
	int i;

	i = 0;
	start->point.x1 = start->point.x + (x * start->len.len);
	start->point.y1 = start->point.y + (x * (start->len.len / 2)) - (z * start->len.len);
	start->point.x2 = start->point.x1 - start->len.len;
	if (start->map[0][x - 1] != 0)
		start->point.y2 = (start->point.y1 - (start->len.len / 2)) - (start->map[0][x - 1] * start->len.len);
	else
		start->point.y2 = start->point.y1 - (start->len.len / 2) - (z * start->len.len);
	step = ft_delta(&start->point, &start->delta);
	while (i < step)
	{
		img_pix_put(img, start->point.x1, start->point.y1, color);
		start->point.x1 += start->delta.x;
		start->point.y1 += start->delta.y;
		i++;
	}
	
}

// void ft_draw_y_axe(t_img *img, t_coord *start, int z, int color)
// {
	// float step;
	// int i;
	// (void) z;
// 
	// i = 0;
	// start->point.x1 = start->point.x;
	// start->point.y1 = start->point.y /*+ (z * start->len.len)*/;
	// start->point.x2 = start->point.x1 + start->len.len;
	// start->point.y2 = start->point.y1 - (start->len.len / 2) /*- (z * start->len.len)*/;
	// step = ft_delta(&start->point, &start->delta);
	// while (i < step)
	// {
		// img_pix_put(img, start->point.x1, start->point.y1, color);
		// start->point.x1 += start->delta.x;
		// start->point.y1 += start->delta.y;
		// i++;
	// }
// }

// void ft_draw_xyz_axe(t_img *img, t_coord *start, int x, int y, int z, int color)
// {
	// float step;
	// (void) z;
	// (void) y;
	// int i;
	// 
	// i = 0;
	// start->point.x1 = start->point.x + (x * start->len.len);
	// start->point.y1 = (start->point.y + (x * (start->len.len / 2))) /*+ (z * start->len.len)*/;
	// start->point.x2 = start->point.x1 + start->len.len;
	// start->point.y2 = (start->point.y1 - (start->len.len / 2)) /*- (z * start->len.len)*/;
	// if (start->map[y - 1][x] != 0)
		// start->point.y2 = (start->point.y1 - (start->len.len / 2)) + (start->map[y - 1][x] * start->len.len);
	// step = ft_delta(&start->point, &start->delta);
	// while (i < step)
	// {
		// img_pix_put(img, start->point.x1, start->point.y1, color);
		// start->point.x1 += start->delta.x;
		// start->point.y1 += start->delta.y;
		// i++;
	// }
	// start->point.x1 = start->point.x + (x * start->len.len);
	// start->point.y1 = (start->point.y + (x * (start->len.len / 2))) /*+ (z * start->len.len)*/;
	// start->point.x2 = start->point.x1 - start->len.len;
	// start->point.y2 = (start->point.y1 - (start->len.len / 2)) /*- (z * start->len.len)*/;
	// step = ft_delta(&start->point, &start->delta);
	// i = 0;
	// while (i < step)
	// {
		// img_pix_put(img, start->point.x1, start->point.y1, color);
		// start->point.x1 += start->delta.x;
		// start->point.y1 += start->delta.y;
		// i++;
	// }
// }

/* ------------------------ draw iso -----------------------------*/
void ft_draw_iso(t_img *img, t_coord *coord, int color)
{
	int x;
	int y = 0;
	
	coord->point.x = coord->init.x;
	coord->point.y = coord->init.y;
	while (y < coord->len.ligne)
	{
		x = 0;
		while (x <= coord->len.colonne)
		{
			coord->len.z = coord->map[y][x];
			if (x == 0 && y == 0)
				img_pix_put(img, coord->init.x, coord->init.y - (coord->len.len * coord->len.z), color);
			else if (y == 0)
				ft_draw_x_axe(img, coord, x, coord->len.z, color);
			// else if (x == 0)
				// ft_draw_y_axe(img, coord, coord->len.z, color);
			// else
				// ft_draw_xyz_axe(img, coord, x, y, coord->len.z, color);
			x++;
		}
		coord->point.x -= coord->len.len;
		coord->point.y += coord->len.len / 2;
		y++;
	}
}