/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:22:23 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/01 19:48:46 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int	modnum(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}
int	maxnum(int nbr1, int nbr2)
{
	int nbr;

	nbr = nbr1 - nbr2;
	if (nbr > 0)
		return (nbr1);
	else
		return (nbr2);
}