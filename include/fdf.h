/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:19:01 by cda-fons          #+#    #+#             */
/*   Updated: 2024/06/26 20:30:41 by cda-fons         ###   ########.fr       */
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

typedef struct	s_point
{
	int	x;
	int	y;
	int z;
}				t_point;

typedef struct	s_map
{
	size_t	height;
	size_t width;
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

#endif