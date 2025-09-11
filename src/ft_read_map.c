/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:03:05 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 10:32:17 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static ssize_t	ft_open_fd(char *path)
{
	ssize_t	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	return (fd);
}

static ssize_t	ft_reset_fd(int fd, char *path)
{
	if (!path)
		return (-1);
	close(fd);
	fd = open(path, O_RDONLY);
	return (fd);
}

char	**ft_read_map(char *path)
{
	char	**grid;
	ssize_t	fd;
	size_t	len;

	if (!path)
		return (NULL);
	fd = ft_open_fd(path);
	if (fd < 0)
		return (NULL);
	len = ft_count_rows(fd);
	if (!len)
		return (NULL);
	fd = ft_reset_fd(fd, path);
	if (fd < 0)
		return (NULL);
	grid = ft_fill_grid(fd, len);
	close(fd);
	return (grid);
}
