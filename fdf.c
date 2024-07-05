/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:12:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/07/05 18:04:20 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"



void matrixfill(t_point *point, char *line, int y, int x)
{
	char	**split;
	char	**data;
	char	*n;

	n = "\n";
	split = ft_split(line, ' ');
	while (split[x])
	{
		if (split[x] == n)
			break;
		data = ft_split(split[x], ',');
		point->z = ft_atoi(data[0]);
		point->x = x;
		point->y = y;
		point->color = 0xffffff;
		free(split[x]);
		x++;
	}
}

t_map	*get_dimensions(int fd)
{
	int		x;
	char	*line;
	t_map	*map;
	
	x = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("Error to allocated map");
	line = get_next_line(fd);
	map->width = ft_words(line, ' ');
	map->height = 0;
	map->coord = malloc(map->height * sizeof(t_point *));
	if (!map->coord)
		ft_error("Error to allocated map->coord");
	while (line)
	{
		line = get_next_line(fd);
		matrixfill(map->coord[map->height], line, map->height, x);
		map->height++;
		free(line);
	}
	map->list = NULL;
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

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
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
			fdf->map = get_dimensions(fd);
			mlx_loop(fdf->mlx);
		}
	}
	else
		ft_error("Too many or too few arguments");
}
