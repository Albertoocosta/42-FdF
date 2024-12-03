/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:47 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/05 20:44:46 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

t_img	create_img(t_fdf *fdf)
{
	t_img	img;

	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (img.img == NULL)
		ft_error("Failed to create the image.");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lenght, &img.endian);
	img.img_width = WIDTH;
	img.img_height = HEIGHT;
	return (img);
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

static void	bresenham(t_bresenham *point, t_point *actual_position, t_point *next_position)
{
	point->dx = abs(next_position->x - actual_position->x);
	point->dy = -1 * abs(next_position->y - actual_position->y);
	if (actual_position->x <= next_position->x)
		point->sx = 1;
	else
		point->sx = -1;
	if (actual_position->y <= next_position->y)
		point->sy = 1;
	else
		point->sy = -1;
	point->err = point->dx + point->dy;
	point->x0 =	actual_position->x;
	point->y0 = actual_position->y;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char *pixel;

	if (x >= 0 && y >= 0 && x < img->img_width && y < img->img_height)
	{
		pixel = img->addr + ((y * img->line_lenght) + (x * (img->bpp / 8)));
		*(unsigned int *) pixel = color;
	}
}

void	draw(t_fdf *fdf, t_point *actual_position, t_point *next_position)
{
	t_bresenham	point;

	map_scaling(fdf, actual_position, next_position);
	bresenham(&point, actual_position, next_position);
	while (1)
	{
		if (point.x0 < WIDTH && point.x0 > 0 && point.y0 < HEIGHT && point.y0 > 0)
			put_pixel(&fdf->img, point.x0, point.y0, set_color(actual_position, next_position));
		if (point.x0 == next_position->x && point.y0 == next_position->y)
			break ;
		if (2 * point.err >= point.dy && point.x0 != next_position->x)
		{
			point.err += point.dy;
			point.x0 += point.sx;
		}
		if (2 * point.err <= point.dx && point.y0 != next_position->y)
		{
			point.err += point.dx;
			point.y0 += point.sy;
		}
	}
}