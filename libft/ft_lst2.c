/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 08:37:49 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/05 20:38:34 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst->next && lst)
		(ft_lstiter(lst->next, f));
	f(lst->content);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*i;
// 	t_list	*d;

// 	(void)del;
// 	if (!lst)
// 		return (0);
// 	i = 0;
// 	while (lst)
// 	{
// 		d = ft_lstnew(f(lst->content));
// 		if (!d)
// 		{
// 			ft_lstclear(&d);
// 			return (0);
// 		}
// 		ft_lstadd_back(&i, d);
// 		lst = lst->next;
// 	}
// 	return (i);
// }

t_list	*ft_lstnew(void *content, t_world *world)
{
	t_list	*new;

	new = (t_list *)ft_malloc(sizeof(t_list), world);
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_clear(t_list **lst, void *cont)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->next)
		{
			if (cont == tmp->next->content)
			{
				tmp2 = tmp->next->next;
				ft_lstdelone(tmp->next, free);
				tmp->next = tmp2;
			}
		}
		tmp = tmp->next;
	}
}
