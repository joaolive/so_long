/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dimension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:38:32 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/10 16:49:04 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_dimension(char **grid, t_mstat *meta)
{
	size_t	len;
	size_t	len_aux;
	size_t	i;

	if (!grid || !*grid || !meta)
		return (0);
	len = ft_strlen(grid[0]);
	i = 0;
	while (grid[i])
	{
		len_aux = ft_strlen(grid[i]);
		if (len_aux != len)
			return (0);
		i++;
	}
	if (!((len >= 3 && i >= 5) || (len >= 5 && i >= 3) || (len >= 4 && i >= 4)))
		return (0);
	meta->width = len;
	meta->height = i;
	return (1);
}
