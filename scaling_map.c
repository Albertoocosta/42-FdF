/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:08:47 by cda-fons          #+#    #+#             */
/*   Updated: 2025/01/20 13:09:22 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	centralize_map(t_point *actual_position, t_point *next_position)
{
	int	x_offset;
	int	y_offset;

	x_offset = WIDTH * 2 / 5;
	y_offset = HEIGHT * 1 / 5;
	actual_position->x += x_offset;
	actual_position->y += y_offset;
	next_position->x += x_offset;
	next_position->y += y_offset;
}

void	isometric(t_point *position)
{
	int	x_temp;
	int	y_temp;

	x_temp = position->x;
	y_temp = position->y;
	position->x = (x_temp - y_temp) * cos(0.523599);
	position->y = (x_temp + y_temp) * sin(0.523599) - position->z;
}

void	diagonal(t_fdf *fdf, t_point *actual_position, t_point *next_position)
{
	float	hypo;
	float	scaling_factor;

	hypo = sqrt(fdf->width * fdf->width + fdf->height * fdf->height);
	scaling_factor = 0.85 * HEIGHT / hypo;
	actual_position->x = round(actual_position->x * scaling_factor);
	actual_position->y = round(actual_position->y * scaling_factor);
	next_position->x = round(next_position->x * scaling_factor);
	next_position->y = round(next_position->y * scaling_factor);
}

void	map_scaling(t_fdf *fdf, t_point *actual_position,
		t_point *next_position)
{
	diagonal(fdf, actual_position, next_position);
	isometric(actual_position);
	isometric(next_position);
	centralize_map(actual_position, next_position);
}
