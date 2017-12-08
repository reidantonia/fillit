/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 10:59:14 by mjoubert          #+#    #+#             */
/*   Updated: 2017/12/04 15:48:38 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static t_res	*ft_cut(char **res, char let, t_struct lims, t_res *domino)
{
	domino->res_dom = res;
	domino->letter = let;
	domino->width = (lims.x_max - lims.x_min) + 1;
	domino->height = (lims.y_max - lims.y_min) + 1;
	domino->next = NULL;
	domino->previous = NULL;
	return (domino);
}

t_res			*ft_stock(char **res, t_res **alst, char let, t_struct lims)
{
	t_res	*domino;
	t_res	*ptr;

	ptr = *alst;
	if (!(domino = (t_res*)malloc(sizeof(*domino))))
		ft_error();
	if (*alst == NULL)
	{
		domino = ft_cut(res, let, lims, domino);
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
