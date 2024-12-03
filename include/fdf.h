/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:19:01 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/05 20:35:40 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"


# define WHITE 0x00FFFFFF
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int sx;
	int	sy;
	int	err;
}				t_bresenham;


typedef struct	s_point
{
	int	x;
	int	y;
	int z;
	int color;
}				t_point;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int	img_width;
	int	img_height;
	int	bpp;
	int	line_lenght;
	int	endian;
}				t_img;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;
	int	height;
	int	width;
	t_point	**coord;
}				t_fdf;


int	ft_error(char *message);
int	modnum(int nbr);
int	maxnum(int nbr1, int nbr2);
int	input_check(int argc, char *argv);
int	width_check(t_fdf *fdf, char *clean_line, int map_line, int width_error);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw(t_fdf *fdf, t_point *actual_position, t_point *next_position);
char	**split_line(char *line);
void	matrixfill(t_fdf *fdf, int fd);
t_img	create_img(t_fdf *fdf);
static void	centralize_map(t_point *actual_position, t_point *next_position);
static void	isometric(t_point *position);
static void	diagonal(t_fdf *fdf, t_point *actual_position, t_point *next_position);
void	map_scaling(t_fdf *fdf, t_point *actual_position, t_point *next_position);
int	close_window(t_fdf *fdf);
int	check_map(char *filename);
void	freematrix(t_fdf *fdf, int fd, int height, char *message);
void free_fdf(t_fdf *fdf, int fd, char *message);
int	key_handler(int key, void *data);
void	split_free(char **split);

#endif