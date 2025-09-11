/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:03:26 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/10 19:27:59 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2 || !ft_validate_suffix(argv[1]))
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	map = ft_parse_map(argv[1]);
	if (!map)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Aedes Adventure");
	mlx_loop(mlx);
	return (0);
}
