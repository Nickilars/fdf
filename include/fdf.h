/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:42:44 by nrossel           #+#    #+#             */
/*   Updated: 2023/01/24 09:04:08 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> //"perror",
# include <stdlib.h>//"exit", 
# include <math.h>//"math function"

# include "../lib/minilibx/mlx.h"//"minilibX"
# include "../lib/libft/include/libft.h"

# define	WINDOW_L 900
# define	WINDOW_H 900
# define	WINDOW_NAME "fdf"
# define	ERROR 0
# define	GREEN 0x7CFC00
# define	RED 0x00960018
# define	WHITE 0xFFFFFF
# define	BLACK 0x00000

typedef struct s_img // Informations relatives à l'image
{
	void		*mlx_img; // Pointeur de l'image à rendre
	char		*addr; // ?
	int			bpp; // Bit par pixels
	int			line_len; //Longueur de la ligne
	int			endian; // ?
}	t_img;

typedef struct s_rect // Afficher les rectangles
{
	int			x;
	int			y;
	int			lenght;
	int			height;
	int			color;
}	t_rect;

typedef struct s_point2d // Coordonées 2D
{
	float			x;
	float			x1;
	float			x2;
	float			y;
	float			y1;
	float			y2;
}	t_point2d ;

typedef struct s_delta
{
	float		x;
	float		y;
} t_delta ;

typedef struct s_point3d // Coordonées 3D
{
	int			ligne;
	int			colonne;
	int			len;
	int			z;
}	t_point3d;

typedef struct s_coord // Coordonées de départ & de fin
{
	t_delta		delta;
	t_point2d	init;
	t_point2d	point;
	t_point3d	len;
	int			**map;
}	t_coord;

typedef struct s_data // Structure principal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_rect		rect;
	t_coord		map;
}	t_data;

int		ft_delta(t_point2d *coord, t_delta *delta);
void	img_pix_put(t_img *img, int x, int y, int color);
void	ft_draw_line(t_img *img, t_coord *start, int map_x, int map_y, int z, int color);
void	ft_draw_iso(t_img *img, t_coord *coord, int color);

int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	draw_squares(t_img *img, t_point2d start, t_point3d end, int color);

int		fdf_parse_line(char *str, int index, t_coord *map);
int		count_lines(int fd, char *map_file, t_point3d *coord_y);
int		fdf_creat_map(int fd, char *map_file, t_coord *data_map);

int		handle_keypress(int key, t_data *data);
int		mouse_handle(int mousekey, int x, int y, t_data *data);

#endif