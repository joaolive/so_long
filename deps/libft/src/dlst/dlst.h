/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaolive <joaolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:09:26 by joaolive          #+#    #+#             */
/*   Updated: 2025/08/31 15:12:32 by joaolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include "../../include/libft.h"

typedef struct s_dnode
{
	void			*content;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}	t_dnode;

typedef struct s_dlist
{
	t_dnode	*head;
	t_dnode	*tail;
	size_t	size;
}	t_dlist;

void	ft_dlstdestroy(t_dlist **lst, void (*del)(void *));
t_dnode	*ft_dlstdetach_node(t_dlist *lst, t_dnode *node);
void	ft_dlstclear(t_dlist *lst, void (*del)(void*));
t_dlist	*ft_dlstconcat(t_dlist *lst1, t_dlist *lst2);
void	ft_dlstdelone(t_dnode *node, void (*del)(void*));
t_dnode	*ft_dlstfind(t_dlist *lst, void *ref, int (*cmp)(void *, void *));
t_dnode	*ft_dlstget_node_at(t_dlist *lst, size_t index);
ssize_t	ft_dlstget_node_index(t_dlist *lst, t_dnode *node);
t_dlist	*ft_dlstinit(void);
int		ft_dlstinsert_at(t_dlist *lst, void *content, size_t index);
int		ft_dlstinsert_node_at(t_dlist *lst, t_dnode *node, size_t index);
void	ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *));
t_dnode	*ft_dlstnew(void *content);
void	*ft_dlstpeek_at(t_dlist *lst, size_t index);
void	*ft_dlstpeek_back(t_dlist *lst);
void	*ft_dlstpeek_front(t_dlist *lst);
void	*ft_dlstpop_back(t_dlist *lst);
void	*ft_dlstpop_front(t_dlist *lst);
int		ft_dlstpush_back(t_dlist *lst, void *content);
int		ft_dlstpush_front(t_dlist *lst, void *content);
int		ft_dlstpush_node_back(t_dlist *lst, t_dnode *node);
int		ft_dlstpush_node_front(t_dlist *lst, t_dnode *node);
int		ft_dlstremove_at(t_dlist *lst, size_t index, void (*del)(void*));
int		ft_dlstremove_if(t_dlist *lst, int (*cond)(void *),
			void (*del)(void *));
int		ft_dlstremove_node(t_dlist *lst, t_dnode *node, void (*del)(void*));
void	ft_dlstreverse(t_dlist *lst);

#endif
