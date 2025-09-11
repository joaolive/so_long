/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:32:03 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 10:32:22 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count_rows(int fd)
{
	char	*row;
	size_t	total_row;

	total_row = 0;
	while (1)
	{
		row = ft_get_next_line(fd);
		if (!row)
			break ;
		total_row++;
		free(row);
	}
	return (total_row);
}
