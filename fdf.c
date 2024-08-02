/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:12:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/02 18:09:57 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include <stdio.h>

void matrixfill(t_point *point, char *line, int y)
{
	char	**split;
	char	**data;
	char	*n;
	int		x;
	
	n = "\n";
	x = 0;
	split = ft_split(line, ' ');
	while (split[x])
	{
		if (split[x][0] == '\n')
			break;
		data = ft_split(split[x], ',');
		point[x].z = ft_atoi(data[0]);
		point[x].x = x;
		point[x].y = y;
		//printf("x,y,z = %d,%d,%d\n ", point[x].x, point[x].y, point[x].z);
		if (data[1])
			point[x].color = ft_atoi(data[1]);
		else
			point[x].color = 0xffffff;
		freematrix(data);
		x++;
	}
	freematrix(split);
}

t_map	*get_dimensions(int fd, char *path)
{
	char	*line;
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("Error to allocated map");
	map->height = getheight(fd);
	map->coord = (t_point**)malloc(sizeof(t_point *) * (map->height + 1));
	close(fd);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map->height = 0;
	map->width = ft_words(line, ' ');
	while (line)
	{
		map->coord[map->height] = ft_calloc(sizeof(t_point), ((map->width) + 1));
		matrixfill(map->coord[map->height], line, map->height);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	map->z_max = 0;
	map->z_min = 0;
	return(map);
}
static t_fdf *init_generate(t_fdf *fdf)
{	
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error("Error to create graphics");
	fdf->win = mlx_new_window(fdf->mlx, 700, 800, "Generate - FdF");
	if (!fdf->win)
		ft_error("Error to create new window");
	fdf->img = mlx_new_image(fdf->mlx, 700, 800);
	if (!fdf->img)
		ft_error("Error to create image");
	fdf->address = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->size_line, &fdf->endian);
	fdf->map = NULL;
	return (fdf);
}


int main(int argc, char **argv)
{
	int	fd;
	t_fdf *fdf;

	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 2);
	if (!fdf)
		ft_error("Error to allocated map");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_error("Error to open file");
		if (check_map(argv[1]))
		{
			fdf = init_generate(fdf);
			fdf->map = get_dimensions(fd, argv[1]);
			mlx_loop(fdf->mlx);
		}
	close(fd);
	}
	else
		ft_error("Too many or too few arguments");
}
