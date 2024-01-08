/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 08:36:23 by mbekouch          #+#    #+#             */
/*   Updated: 2023/11/06 21:40:27 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	i = *lst;
	while (i->next)
	{
		i = i->next;
	}
	i->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	while (ft_lstsize(*lst))
	{
		if ((*lst)->next)
			ft_lstclear(&(*lst)->next);
		else
		{
			if ((*lst)->content)
			{
				free((*lst)->content);
				(*lst)->content = NULL;
			}
			free(*lst);
			*lst = NULL;
		}
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	if (lst)
	{
		free(lst);
		lst = NULL;
	}
}
