/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:59:15 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/02 10:59:42 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* --------------- draw a rect --------------------*/
int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.lenght)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

/* --------------- background color --------------------*/
void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i <= WINDOW_H)
	{
		j = 0;
		while (j <= WINDOW_L)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}