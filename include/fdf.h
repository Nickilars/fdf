/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:42:44 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/13 11:14:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> //"perror",
# include <stdlib.h>//"exit", 
# include <math.h>//"math function"

# include "../libmlx/mlx.h"//"minilibX"
# include "../libft/include/libft.h"

# define	WINDOW_WIDTH 1200
# define	WINDOW_HIGHT 900
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

typedef struct s_point2d
{
	float		x;
	float		y;
	int			color;
	// void		*next_x;
	// void		*next_y;
} t_point2d;
typedef struct s_point3d
{
	float		x;
	float		y;
	float		z;
	int			color;
} t_point3d;

typedef struct s_delta
{
	float		d_x;
	float		d_y;
} t_delta;

typedef struct s_model // Coordonées de départ & de fin
{
	int			width;
	int			hight;
	float		**map3d;
	//t_point2d	**map2d;
	int			offset_x;
	int			offset_y;
	float		zoom;
	int			len;
	t_delta		delta;
}	t_model;

typedef struct s_data // Structure principal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_model		map;
}	t_data;

void	ft_draw_line(t_img *img, t_model *model);
void 	black_screen(t_img *img);
void	img_pix_put(t_img *img, int x, int y, int color);

void	ft_3d_to_2d(t_model *model);

int		fdf_creat_map(int fd, char *map_file, t_model *map);

int		handle_keypress(int key, t_data *data);
int		mouse_handle(int mousekey, int x, int y, t_data *data);
int		close_window(int keycode, t_data *data);

#endif