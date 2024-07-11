/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:19:01 by cda-fons          #+#    #+#             */
/*   Updated: 2024/07/11 19:57:45 by cda-fons         ###   ########.fr       */
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


# define WIDTH 800
# define HEIGHT 700

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
	int	***list;
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
void draw(t_fdf fdf);
int	check_map(char *filename);
void	freematrix(char **matrix);

#endif