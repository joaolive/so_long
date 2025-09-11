/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:38:37 by joaolive          #+#    #+#             */
/*   Updated: 2025/08/31 15:26:34 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstdelone(t_dnode *node, void (*del)(void*))
{
	if (!node)
		return ;
	if (del)
		del(node->content);
	free(node);
}
