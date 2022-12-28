/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:42:44 by nrossel           #+#    #+#             */
/*   Updated: 2022/12/28 15:30:16 by nrossel          ###   ########.fr       */
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

typedef struct s_img // Informations relatives à l'image
{
	void *mlx_img; // Pointeur de l'image à rendre
	char *addr; // ?
	int bpp; // Bit par pixels
	int line_len; //Longueur de la ligne
	int endian; // ?
}	t_img;

typedef struct s_rect // Afficher les rectangles
{
	int	x;
	int	y;
	int lenght;
	int height;
	int color;
}	t_rect;

typedef struct s_point2d // Coordonées 2D
{
	int	x;
	int	y;
}	t_point2d ;

typedef struct s_point3d // Coordonées 3D
{
	int	x;
	int	y;
	int	z;
}	t_point3d;

typedef struct s_coord // Coordonées de départ & de fin
{
	t_point2d	init;
	t_point3d	final;
	int			**map;
}	t_coord;

typedef struct s_data // Structure principal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_rect	rect;
	t_coord	map;
}	t_data;

void	img_pix_put(t_img *img, int x, int y, int color);
void	ft_draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);
int		fdf_creat_map(int fd, char *map_file, t_coord data_map);
int		ft_free_funct(char *ptr1, char *ptr2, char *ptr3);

#endif