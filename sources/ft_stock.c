/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 10:59:14 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/27 22:42:02 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

l_res	*ft_stock(char **res, l_res **alst, char let, t_struct lims)
{
	l_res	*domino;
	l_res	*ptr;

	ptr = *alst;
	if (!(domino = (l_res*)malloc(sizeof(*domino))))
		ft_error();
	if (*alst == NULL)
	{
		domino->res_dom = res;
		domino->letter = let;
		domino->width = (lims.x_max - lims.x_min) + 1;
		domino->height = (lims.y_max - lims.y_min) + 1;
		domino->next = NULL;
		domino->previous = NULL;
		*alst = domino;
		return (*alst);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = domino;
	domino->res_dom = res;
	domino->letter = let;
	domino->width = lims.x_max - lims.x_min + 1;
	domino->height = lims.y_max - lims.y_min + 1;
	domino->previous = ptr;
	domino->next = NULL;
	return (*alst);
}
