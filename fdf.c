/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:12:43 by cda-fons          #+#    #+#             */
/*   Updated: 2025/02/04 12:10:45 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"
#include <stdio.h>

void	pointfill(t_point *point, char **clean_line, int height, t_fdf *fdf)
{
	int		cur_position;
	char	**z_color;

	cur_position = 0;
	while (clean_line[cur_position] != 0)
	{
		point[cur_position].x = cur_position;
		point[cur_position].y = height;
		z_color = ft_split(clean_line[cur_position], ',');
		if (fdf->height > 30 && fdf->height < 60)
			point[cur_position].z = ft_atoi(z_color[0]) * 10;
		else
			point[cur_position].z = ft_atoi(z_color[0]);
		if (z_color[1])
			point[cur_position].color = ft_atoi_hexa(z_color[1] + 2);
		else
			point[cur_position].color = WHITE;
		split_free(z_color);
		cur_position++;
	}
}

void	matrixfill(t_fdf *fdf, int fd)
{
	char	*line;
	char	**clean_line;
	int		height;

	height = 0;
	fdf->coord = (t_point **)malloc(sizeof(t_point *) * fdf->height);
	if (!fdf->coord)
		free_fdf(fdf, fd, "Matrix error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_line = split_line(line);
		fdf->coord[height] = (t_point *)malloc(sizeof(t_point) * fdf->width);
		if (!fdf->coord)
			freematrix(fdf, fd, height, "Matrix line error");
		pointfill(fdf->coord[height], clean_line, height, fdf);
		height++;
		split_free(clean_line);
	}
	close(fd);
}

void	get_dimensions(t_fdf *fdf, int fd)
{
	char	*line;
	char	*clean_line;
	int		map_line_width;
	int		width_erro;

	map_line_width = 0;
	width_erro = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_line = ft_strtrim(line, "\n");
		free(line);
		if (map_line_width == 0)
			map_line_width = ft_words(clean_line, ' ');
		else
			width_erro = width_check(fdf, clean_line,
					map_line_width, width_erro);
		fdf->height++;
		free(clean_line);
	}
	if (width_erro == 1)
		free_fdf(fdf, fd, "Width error");
	close(fd);
}

void	init_generate(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fdf");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;

	fd = input_check(argc, argv[1]);
	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 2);
	if (!fdf)
	{
		close(fd);
		ft_error("Error to allocated map");
	}
	ft_memset(fdf, 0, sizeof(t_fdf));
	get_dimensions(fdf, fd);
	init_generate(fdf);
	fd = open(argv[1], O_RDONLY, 0);
	matrixfill(fdf, fd);
	fdf->img = create_img(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	mlx_hook(fdf->win, 17, 0L, close_window, fdf);
	mlx_key_hook(fdf->win, &key_handler, fdf);
	mlx_loop(fdf->mlx);
	exit(EXIT_SUCCESS);
}
