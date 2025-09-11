/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:05:53 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/01 10:40:17 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = (const char *) s;
	while (*p)
		p++;
	return (p - s);
}
