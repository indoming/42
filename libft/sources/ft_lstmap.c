/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:25:32 by indoming          #+#    #+#             */
/*   Updated: 2021/08/10 13:14:05 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	t_list	*auxnew;

	aux = lst;
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	auxnew = new;
	while (aux)
	{
		auxnew->content = f(aux->content);
		auxnew->next = malloc(sizeof(t_list));
		if (!(auxnew->next))
			ft_lstclear(&aux, del);
		aux = aux->next;
		auxnew = auxnew->next;
	}
	return (new);
}
