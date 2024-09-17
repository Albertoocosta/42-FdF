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


# define WIDTH 1080
# define HEIGHT 800

typedef struct	s_point
{
	float	x;
	float	y;
	int z;
	int last;
	int color;
}				t_point;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	int	scale;
	int	scale_z;
	double	angle;
	int	win_x;
	int	win_y;
	int	offset_x;
	int offset_y;
	size_t	height;
	size_t	width;
	t_point	**coord;
}				t_fdf;


int	ft_error(char *message);
int	modnum(int nbr);
int	maxnum(int nbr1, int nbr2);
void	draw(t_point **matrix, t_fdf *fdf);
void	matrixfill(t_point **point, char *line, int y);
int	check_map(char *filename);
void	freematrix(char **matrix);
int	getheight(int fd);
int	key_handler(int key, t_fdf *data);
void	isometric(t_point *point, double angle);

#endif