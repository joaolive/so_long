/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:03:26 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/13 19:28:30 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_print(void)
{
	ft_print_error("Something went very wrong! The PC is dying");
	return (1);
}

static bool	start_engine(t_game *game)
{
	int	w;
	int	h;

	w = game->map->width * 32;
	h = game->map->height * 32;
	game->mlx = mlx_init(w, h, "Mouse Adventure", false);
	if (!game->mlx)
		return (false);
	ft_load_all_images(game);
	if (!ft_render(game))
		return (false);
	mlx_key_hook(game->mlx, ft_hook_handler, game);
	mlx_close_hook(game->mlx, ft_close_window_hook, game);
	mlx_loop(game->mlx);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_map	*map;

	if ((argc != 2) || !ft_validate_suffix(argv[1]))
		exit(ft_print());
	map = ft_parse_map(argv[1]);
	if (!map)
		exit(ft_print());
	game = ft_initializr_game(map);
	if (!game)
	{
		ft_terminate(game);
		exit(ft_print());
	}
	if (!start_engine(game))
	{
		ft_terminate(game);
		exit(ft_print());
	}
	ft_terminate(game);
	exit(0);
}
