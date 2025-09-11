/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:58:06 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/09 13:58:24 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_suffix(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i < 4)
		return (0);
	if ((!ft_strcmp((file + i - 4), ".ber")) == 0)
		return (0);
	return (1);
}
