/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:45:31 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/12 18:49:01 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
void	ft_hook_handler(void *param)
{
	t_game	*game;
	double	current_time;

	game = (t_game *) param;
	current_time = mlx_get_time();
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_Q) && current_time - game->time > SPEED)
		return ;
}
