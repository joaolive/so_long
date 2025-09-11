/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:25:08 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/01 10:40:17 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (len == 0)
		return (0);
	while (len - 1 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		len--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
