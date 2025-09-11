/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 09:28:36 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/10 22:02:39 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
int	ft_validate_map(char **grid, t_mstat *meta)
{
	if (!grid || !*grid || !meta)
		return (0);
	if (!ft_check_dimension(grid, meta)
		|| !ft_check_walls(grid, meta)
		|| !ft_check_flags(grid, meta)
		|| !ft_check_roads(grid, meta))
		return (0);
	return (1);
}
