/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:32:24 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 09:51:18 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_remove_newline(char *row)
{
	size_t	row_len;

	row_len = ft_strlen(row);
	if (row_len && row[row_len - 1] == '\n')
		row[row_len - 1] = '\0';
}

char	**ft_fill_grid(int fd, size_t len)
{
	char	**grid;
	char	*row;
	size_t	i;

	grid = (char **)malloc(sizeof(char *) * (len + 1));
	if (!grid || !len)
		return (NULL);
	i = 0;
	while (i < len)
	{
		row = ft_get_next_line(fd);
		if (!row)
		{
			ft_clean_up(grid);
			return (NULL);
		}
		ft_remove_newline(row);
		grid[i] = row;
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
