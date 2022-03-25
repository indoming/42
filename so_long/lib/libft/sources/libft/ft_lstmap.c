/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:25:32 by indoming          #+#    #+#             */
/*   Updated: 2021/08/16 09:13:18 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	aux = new;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		aux->next = temp;
		aux = temp;
		lst = lst->next;
	}
	return (new);
}
