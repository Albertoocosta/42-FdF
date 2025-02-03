/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:22:23 by cda-fons          #+#    #+#             */
/*   Updated: 2025/02/03 19:07:20 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int	set_color(t_point *actual_position, t_point	*next_position)
{
	if (actual_position->color != WHITE)
		return (actual_position->color);
	else if (next_position->color != WHITE)
		return (next_position->color);
	return (WHITE);
}

int	close_window(t_fdf *fdf)
{
	int	line;

	line = fdf->height - 1;
	if (fdf)
	{
		mlx_destroy_image(fdf->mlx, fdf->img.img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		while (line >= 0)
		{
			if (fdf->coord[line])
				free(fdf->coord[line]);
			line--;
		}
		free(fdf->coord);
		free(fdf->mlx);
		free(fdf);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_handler(int key, void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)data;
	if (key == 65307 || !fdf)
		close_window(fdf);
	return (0);
}

void	line_horizon(t_fdf *fdf, int x, int y)
{
	t_point	actual_position;
	t_point	next_position;

	actual_position.x = fdf->coord[y][x].x;
	actual_position.y = fdf->coord[y][x].y;
	actual_position.z = fdf->coord[y][x].z;
	actual_position.color = fdf->coord[y][x].color;
	next_position.x = fdf->coord[y][x + 1].x;
	next_position.y = fdf->coord[y][x + 1].y;
	next_position.z = fdf->coord[y][x + 1].z;
	next_position.color = fdf->coord[y][x + 1].color;
	draw(fdf, &actual_position, &next_position);
}

void	line_vertical(t_fdf *fdf, int x, int y)
{
	t_point	actual_position;
	t_point	next_position;

	actual_position.x = fdf->coord[y][x].x;
	actual_position.y = fdf->coord[y][x].y;
	actual_position.z = fdf->coord[y][x].z;
	actual_position.color = fdf->coord[y][x].color;
	next_position.x = fdf->coord[y + 1][x].x;
	next_position.y = fdf->coord[y + 1][x].y;
	next_position.z = fdf->coord[y + 1][x].z;
	next_position.color = fdf->coord[y + 1][x].color;
	draw(fdf, &actual_position, &next_position);
}
