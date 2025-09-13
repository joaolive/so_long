/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:13:46 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/12 14:07:31 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_terminate(t_game *game)
{
	if (!game)
		return ;
	ft_cleanup_assets(game);
	ft_clean_up(game->map->grid);
	free(game->map);
	mlx_terminate(game->mlx);
}
