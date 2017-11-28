/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:09:06 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/22 14:55:45 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cont;

	if (!(cont = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		cont->content = NULL;
		cont->content_size = 0;
	}
	else
	{
		if (!(cont->content = malloc(content_size)))
			return (0);
		cont->content = ft_memcpy(cont->content, content, content_size);
		cont->content_size = content_size;
	}
	cont->next = NULL;
	return (cont);
}
