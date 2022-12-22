/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:42:44 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/22 14:33:16 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/uio.h> //"read"
# include <unistd.h> // "write","close","read"
# include <string.h> // "NULL","strerror",
# include <stdlib.h> // "malloc","free"

# include <fcntl.h> //"open",
# include <sys/types.h> //"open",
# include <sys/stat.h> //"open",

# include <stdio.h> //"perror",
# include <stdlib.h>//"exit", 
# include <math.h>//"math function"

# include "../lib/minilibx/mlx.h"//"minilibX"
# include "../lib/libft/include/libft.h"

typedef struct s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
} t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int lenght;
	int height;
	int color;
}	t_rect;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_rect	rect;
} t_data;

void	img_pix_put(t_img *img, int x, int y, int color);
void ft_draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);
int	ft_parse_map(char *map_file);

#endif