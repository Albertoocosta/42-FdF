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

int	input_check(int argc, char *argv)
{
	int	fd;

	if (argc != 2)
		ft_error("Invalid input.");
	fd = open(argv, O_RDONLY, 0);
	if (fd == -1)
		ft_error("Error to open the file.");
	return (fd);
}

int	width_check(t_fdf *fdf, char *clean_line, int map_line, int width_error)
{
	fdf->width = ft_words(clean_line, ' ');
	if (map_line != fdf->width)
		width_error = 1;
	return (width_error);
}

char	**split_line(char *line)
{
	char	*to_clean_line;
	char	**splited_line;

	to_clean_line = ft_strtrim(line, "\n");
	free(line);
	splited_line = ft_split(to_clean_line, ' ');
	free(to_clean_line);
	return(splited_line);
}