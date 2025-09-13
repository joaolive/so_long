/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:48:52 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/11 19:51:06 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_load_image(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (image);
}
