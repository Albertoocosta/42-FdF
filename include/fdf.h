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


# define WIDTH 1920
# define HEIGHT 900

typedef struct	s_point
{
	int	x;
	int	y;
	int z;
	int color;
}				t_point;

typedef struct	s_map
{
	size_t	height;
	size_t	width;
	t_point	**coord;
	int	z_max;
	int	z_min;
}				t_map;


typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
	int	bpp;
	int	size_line;
	int	endian;
	int	steep;
	t_map	*map;
}				t_fdf;


int ft_error(char *message);
void	draw(t_fdf *fdf, t_point *point1, t_point *point2);
void matrixfill(t_point *point, char *line, int y);
int	check_map(char *filename);
void	freematrix(char **matrix);
int	getheight(int fd);

#endif