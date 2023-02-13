/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_design.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:58:44 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/13 09:38:05 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- Calcul de l'angle --------------------*/
static int	ft_delta(t_point2d s, t_point2d f, t_delta *d)
{
	float delta_x;
	float delta_y;
	float step;

	delta_x = f.x - s.x;
	delta_y = f.y - s.y;
	if (fabs(delta_x) >= fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	d->d_x = delta_x / step;
	d->d_y = delta_y / step;
	return (step);
}

/* --------------- draw pixel --------------------*/
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

/* --------------- Axe X --------------------*/
static void	draw_x(t_img *img, t_model *model, int x, int y)
{
	float		step;
	int			i;
	t_point2d	d; // point depart
	t_point2d	f; // point final
	
	if (x > 0)
	{
		d.x = model->offset_x + ((x - y) * model->zoom);
		d.y = model->offset_y + ((x + y) * (model->zoom / 2))
		- (model->map3d[y][x] * model->zoom);
		f.x = d.x - model->zoom;
		f.y = ((d.y + (model->map3d[y][x] * model->zoom)) - (model->zoom / 2)) 
		- (model->map3d[y][x - 1] * model->zoom);
		step = ft_delta(d, f, &model->delta);
		i = 0;
		while (i < step)
		{
			img_pix_put(img, d.x, d.y, GREEN);
			d.x += model->delta.d_x;
			d.y += model->delta.d_y;
			i++;
		}
	}
}

/* --------------- Axe Y --------------------*/
static void	draw_y(t_img *img, t_model *model, int x, int y)
{
	float		step;
	int			i;
	t_point2d	d;
	t_point2d	f;

	if (y > 0)
	{
		d.x = model->offset_x - ((y - x) * model->zoom);
		d.y = model->offset_y + ((y + x) * (model->zoom / 2)) 
		- (model->map3d[y][x] * model->zoom);
		f.x = d.x + model->zoom;
		f.y = ((d.y + (model->map3d[y][x] * model->zoom)) - (model->zoom / 2))
		- (model->map3d[y - 1][x] * model->zoom);
		step = ft_delta(d, f, &model->delta);
		i = 0;
		while (i < step)
		{
			img_pix_put(img, d.x, d.y, GREEN);
			d.x += model->delta.d_x;
			d.y += model->delta.d_y;
			i++;
		}
	}
}

/* ++++++++++++++++++++++++++++++ Main fonction +++++++++++++++++++++++++++++++++++ */
void	ft_draw_line(t_img *img, t_model *model)
{
	int x;
	int y = 0;
	
	black_screen(img);
	while (y < model->hight)
	{
		x = 0;
		while (x < model->width)
		{
			if (x == 0 && y == 0)
				img_pix_put(img, model->offset_x, model->offset_y 
				- (model->map3d[y][x] * model->zoom), RED);
			else
			{
				draw_x(img, model, x, y);
				draw_y(img, model, x, y);
			}
			x++;
		}
		y++;
	}
}