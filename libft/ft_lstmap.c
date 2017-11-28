/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:06:26 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/22 11:35:36 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *previous;
	t_list *new;
	t_list *header;

	header = NULL;
	if (!lst || !f)
		return (0);
	new = (*f)(lst);
	header = new;
	lst = lst->next;
	previous = new;
	while (lst)
	{
		new = (*f)(lst);
		previous->next = new;
		previous = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (header);
}
