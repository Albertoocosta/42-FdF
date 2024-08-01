/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:22:23 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/01 19:48:46 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit(-1);
}
int	check_map(char *filename)
{
	int len;

	len = ft_strlen(filename);
	if (filename[len - 4] == '.' && filename[len - 3] == 'f' && filename[len - 2] == 'd' && filename[len - 1] == 'f')
		return (1);
	else
		ft_error("File not .fdf");
	return(0);
}
void	freematrix(char **matrix)
{
	int y;

	y = 0;
	while(matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	getheight(int fd)
{
	char *line;
	int	height;

	height = 0;	
	line = get_next_line(fd);
	while(line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}