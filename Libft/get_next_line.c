/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:07 by cda-fons          #+#    #+#             */
/*   Updated: 2025/01/30 14:06:43 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_aux(int fd, char *buffer, char *backup)
{
	int		i;
	char	*aux;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!backup)
			backup = ft_strdup("");
		aux = backup;
		backup = ft_strjoin(aux, buffer);
		free(aux);
		aux = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_exclude_line(char *str)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (0);
	ret = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*ret == '\0')
	{
		free(ret);
		ret = NULL;
	}
	str[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = get_next_line_aux(fd, buffer, backup);
	free (buffer);
	buffer = NULL;
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (0);
	}
	backup = ft_exclude_line(line);
	return (line);
}
