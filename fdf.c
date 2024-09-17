/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:12:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/08/05 20:55:00 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include <stdio.h>

void matrixfill(t_point **point, char *line, int y)
{
	char	**split;
	char	**data;
	int		x;
	
	x = 0;
	split = ft_split(line, ' ');
	while (split[x])
	{
		if (split[x][0] == '\n')
			break;
		data = ft_split(split[x], ',');
		point[y][x].z = ft_atoi(data[0]);
		point[y][x].x = x;
		point[y][x].y = y;
		point[y][x].last = 0;
		if (data[1])
			point[y][x].color = ft_atoi(data[1]);
		else
			point[y][x].color = 0xffffff;
		freematrix(data);
		x++;
	}
	point[y][x - 1].last = 1;
	freematrix(split);
}

void	get_dimensions(t_fdf *fdf, int fd, char *path)
{
	char	*line;

	fdf->height = getheight(fd);
	fdf->coord = (t_point**)malloc(sizeof(t_point *) * (fdf->height + 1));
	close(fd);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	fdf->height = 0;
	fdf->width = ft_words(line, ' ');
	while (line)
	{
		fdf->coord[fdf->height] = (t_point *)ft_calloc(sizeof(t_point), ((fdf->width) + 1));
		matrixfill(fdf->coord, line, fdf->height);
		fdf->height++;
		free(line);
		line = get_next_line(fd);
	}
	for (int cont1 = 0; fdf->coord[cont1]; cont1++)
	{
		for (int cont2 =0; fdf->coord[cont2]; cont2++)
		{
			printf("%d", fdf->coord[cont2]->z);
			if (fdf->coord[cont2]->last != 1)
				printf(" ");
		}
		printf("\n");
	}

}
static t_fdf *init_generate(t_fdf *fdf)
{	
	fdf->height = 0;
	fdf->width = 0;
	fdf->coord = NULL;
	fdf->angle = 0.523599;
	fdf->win_x = WIDTH;
	fdf->win_y = HEIGHT;
	fdf->offset_x = fdf->win_x / 3;
	fdf->offset_y = fdf->win_y / 3;
	fdf->scale = 20;
	fdf->scale_z = 1;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error("Error to create graphics");
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, "Generate - FdF");
	if (!fdf->win)
		ft_error("Error to create new window");
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
			get_dimensions(fdf, fd, argv[1]);
			draw(fdf->coord, fdf);
			mlx_key_hook(fdf->win, key_handler, fdf);
			mlx_loop(fdf->mlx);
		}
	close(fd);
	}
	else
		ft_error("Too many or too few arguments");
}
