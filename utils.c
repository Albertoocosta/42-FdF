/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:22:23 by cda-fons          #+#    #+#             */
/*   Updated: 2025/01/20 13:12:30 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int	ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit(-1);
}

int	check_map(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] == '.' && filename[len - 3] == 'f'
		&& filename[len - 2] == 'd' && filename[len - 1] == 'f')
		return (1);
	else
		ft_error("File not .fdf");
	return (0);
}

void	freematrix(t_fdf *fdf, int fd, int height, char *message)
{
	while (height)
	{
		if (fdf->coord[height])
			free(fdf->coord[height]);
		height--;
	}
	free(fdf->coord);
	free_fdf(fdf, fd, message);
}

void	free_fdf(t_fdf *fdf, int fd, char *message)
{
	free(fdf);
	close(fd);
	ft_error(message);
}

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
