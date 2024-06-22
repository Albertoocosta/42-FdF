/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:12:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/06/22 15:57:42 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include "./Libft/libft.h"
#include "./Printf/ft_printf.h"


int	check_map(char *filename)
{
	int len;

	len = ft_strlen(filename);
	if (filename[len - 4] == '.' && filename[len - 3] == 'f' && filename[len - 2] == 'd' && filename[len - 1] == 'f')
		return (1);
	else
	{
		ft_printf("File not .fdf");
		exit(13);
	}
}

t_map	*get_dimensions(int fd)
{
	int	height;
	int width;
	t_map *map;

	height = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error to allocated map");
		exit(14);
	}
	width = ft_strlen(get_next_line(fd));
	ft_printf("gnl -> %s\n", get_next_line(fd));
	ft_printf("width antes do loop -> %d\n", width);
	while (width != 0)
	{
		if (get_next_line(fd) == NULL)
			break ;
		ft_printf("gnl inside loop-> %s\n", get_next_line(fd));
		width = ft_strlen(get_next_line(fd));
		height++;
	}
	ft_printf("height -> %d\n", height);
	map->height = height;
	map->width = width;
	map->list = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return(map);
}

int main(int argc, char **argv)
{
	int	fd;
	t_map *map;

	map = NULL;
	if (argc != 2)
	{
		ft_printf("usage: ./fdf <mapname>.fdf");
		exit(10);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening");
		exit(11);
	}
	if (check_map(argv[1]))
		map = get_dimensions(fd);
	else
	{
		ft_printf("Map error");
		exit(12);
	}
}
