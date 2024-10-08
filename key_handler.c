/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:22:23 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/01 19:48:46 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int	key_handler(int key, t_fdf *data)
{
	if (key == 65307)
		ft_error("Closed");
	if (key == 126)
		data->scale += 3;
	ft_printf("%d\n", key);
	return (0);
}