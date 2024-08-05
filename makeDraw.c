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

void	putpixel(t_fdf *fdf, int x, int y, int color)
{
	char *dst;
	
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		dst = fdf->address + (y * fdf->size_line + x *(fdf->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	less_than_one(int p, int dx, int dy, t_point *point1, t_point *point2, t_fdf *fdf)
{
	int	i;
	int x;
	int y;

	x = point1->x;
	y = point1->y;
	i = -1;
	while (++i < dx)
	{
		if (dx < 0)
			x -= 1;
		else
			x += 1;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			if (dy < 0)
				y -= 1;
			else
				y += 1;  
			p = p + 2 * dy - 2 * dx;
		}
		putpixel(fdf, x, y, point1->color);
	}
}

void	bigger_than_one(int p, int dx, int dy, t_point *point1, t_point *point2, t_fdf *fdf)
{
	int	i;
	int	x;
	int y;

	x = point1->x;
	y = point1->y;
	i = -1;
	while (++i < dy)
	{
		if (dy < 0)
			y -= 1;
		else
			y += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			if (dx < 0)
				x -= 1;
			else
				x += 1;
			p = p + 2 * dx - 2 * dy;
		}
		putpixel(fdf,x,y, point1->color);
	}
}

void	draw(t_fdf *fdf, t_point *point1, t_point *point2)
{
	int	dx;
	int	dy;
	int	max;
	
	dx = point2->x - point1->x;
	dy = point2->y - point1->y;
	if (dx > dy)
		bigger_than_one((2 * dy-dx), dx, dy, point1, point2, fdf);
	else
		less_than_one((2 * dy-dx), dx, dy, point1, point2, fdf);
}
