/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:47:43 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/29 11:19:34 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_next_line(int fd)
{
	static char	*storage[FOPEN_MAX];
	char		*line;
	char		*final_line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	line = ft_line_maker(fd, buf, storage[fd]);
	free(buf);
	if (!line)
		return (NULL);
	storage[fd] = ft_line_extract(line);
	final_line = ft_strdup(line);
	free (line);
	return (final_line);
}

char	*ft_line_maker(int fd, char *buf, char *storage)
{
	int		nb_read;
	char	*temp;

	nb_read = read(fd, buf, BUFFER_SIZE);
	if (nb_read == 1)
		return (NULL);
	while (nb_read > 0)
	{
		buf[nb_read] = '\0';
		if (!storage)
			storage = ft_strdup(buf);
		else
		{
			temp = storage;
			storage = ft_strjoin(storage, buf);
			free(temp);
		}
		if (!storage)
			return (NULL);
		if (ft_check(storage) != -1)
			return (storage);
		nb_read = read(fd, buf, BUFFER_SIZE);
	}
	return (storage);
}

int	ft_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line_extract(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
		return (0);
	temp = ft_strdup(line + i + 1);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}
