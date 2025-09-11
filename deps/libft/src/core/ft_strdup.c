/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:11:36 by joaolive          #+#    #+#             */
/*   Updated: 2025/09/01 10:40:17 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, i);
	return (str);
}
