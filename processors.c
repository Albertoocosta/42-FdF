/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:22:23 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/01 19:48:46 by cda-fons         ###   ########.fr       */
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

int	key_handler(int key, void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)data;
	if (key == 65307 || !fdf)
		ft_error("Closed");
	return (0);
}