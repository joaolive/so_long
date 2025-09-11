/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:08:02 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/01 10:40:17 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*ft_strchr(const char *s, int c)
{
	const char		*str;
	unsigned char	cc;

	if (!s)
		return (NULL);
	str = s;
	cc = (unsigned char) c;
	while (*str)
	{
		if (*str == cc)
			return ((char *) str);
		str++;
	}
	if (*str == cc)
		return ((char *) str);
	return (NULL);
}
