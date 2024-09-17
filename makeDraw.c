/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeDraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:47 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/05 20:44:46 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	zoom(t_point *point1, t_point *point2, t_fdf *fdf)
{
	point1->x *= fdf->scale;
	point1->y *= fdf->scale;
	point1->z *= fdf->scale_z;
	point2->x *= fdf->scale;
	point2->y *= fdf->scale;
	point2->z *= fdf->scale_z;
}

void	adjust(t_point *point1, t_point *point2, t_fdf *fdf)
{
	zoom(point1, point2, fdf);
	isometric(point1, fdf->angle);
	isometric(point2, fdf->angle);
	point1->x += fdf->offset_x;
	point1->y += fdf->offset_y;
	point2->x += fdf->offset_x;
	point2->y += fdf->offset_y;

}

void	bresenham(t_point point1, t_point point2, t_fdf *fdf)
{
	float stepx;
	float stepy;
	int max;

	adjust(&point1, &point2, fdf);
	stepx = point1.x - point2.x;
	stepy = point1.y - point2.y;
	max = maxnum(modnum(stepx), modnum(stepy));
	stepx /= max;
	stepy /= max;
	while ((int)(point1.x - point2.x) || (int)(point1.y - point2.y))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, point1.x, point1.y, point1.color);
		point1.x += stepx;
		point1.y += stepy;
		if (point1.x > fdf->win_x || point1.y > fdf->win_y || point1.y < 0 || point1.x < 0)
			break ;
	}
}
void	draw(t_point **matrix, t_fdf *fdf)
{
	int	y;
	int x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y + 1][x], fdf);
			if (!matrix[y][x].last)
				bresenham(matrix[y][x], matrix[y][x + 1], fdf);
			if (matrix[y][x].last)
				break ;
			x++;
		}
		y++;
	}
}
