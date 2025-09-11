/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:25:13 by joaolive          #+#    #+#             */
/*   Updated: 2025/08/31 15:25:27 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n_next;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		n_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = n_next;
	}
}
