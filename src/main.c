/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:03:26 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/12 19:17:20 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	if (argc != 2 || !ft_validate_suffix(argv[1]))
		return (ft_print_error());
	map = ft_parse_map(argv[1]);
	if (!map)
		return (ft_print_error());
	game = ft_initializr_game(map);
	if (!game)
	{
		//falta dar free no map;
		return (ft_print_error());
	}
	game->mlx = mlx_init(game->map->width * 32, game->map->height * 32, "Mouse Adventure", false);
	if (!game->mlx)
	{
		// falta dar free no map;
		free(game);
		return (ft_print_error());
	}
	ft_load_all_images(game);
	if (!ft_render(game))
	{
		// falta dar free no map;
		free(game);
		return (ft_print_error());
	}
	mlx_loop_hook(game->mlx, ft_hook_handler, game);
	mlx_key_hook(game->mlx, ft_player_hook_handler, game);
	mlx_loop(game->mlx);
	return (0);
}
