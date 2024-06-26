/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:12:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/06/26 20:54:23 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"


void cleaner(char *line, t_map *map)
{
	free(line);
	free(map);
}

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
	char *line;
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error to allocated map");
		exit(14);
	}
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		/* if(map->width != ft_strlen(line))
		{
			cleaner(line, map);
			exit(15);
		} */
		map->height++;
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
	{
		ft_printf("Error to create graphics");
		exit(16);
	}
	fdf->win = mlx_new_window(fdf->mlx, 700, 800, "Generate - FdF");
	if (!fdf->win)
	{
		ft_printf("Error to create new window");
		exit(17);
	}
	fdf->img = mlx_new_image(fdf->mlx, 700, 800);
	if (!fdf->img)
	{
		ft_printf("Error to create image");
		exit(14);
	}
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
	{
		ft_printf("Error to allocated map");
		exit(10);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("Error opening");
			exit(11);
		}
		if (check_map(argv[1]))
		{
			fdf = init_generate(fdf);
			fdf->map = get_dimensions(fd);
			mlx_loop(fdf->mlx);
		}
	}
	else
	{
		ft_printf("usage: ./fdf <mapname>.fdf");
		exit(12);
	}
}
