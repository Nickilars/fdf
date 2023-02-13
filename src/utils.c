/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:22:16 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/13 15:21:53 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	black_screen(t_img *img)
{
	t_point2d	s;

	s.x = 0;
	s.y = 0;
	s.color = BLACK;
	while (s.y <= WINDOW_HIGHT)
	{
		s.x = 0;
		while (s.x <= WINDOW_WIDTH)
			img_pix_put(img, s.x++, s.y, s.color);
		s.y++;
	}
}
