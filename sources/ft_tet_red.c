/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tet_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:37:00 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/29 16:22:18 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static char		*ft_cut(char *red, char **full, int *tab, t_struct lims)
{
	int b;

	b = 0;
	while (tab[0] <= lims.x_max)
	{
		if (full[tab[1]][tab[0]] == '#')
			red[b] = (char)tab[2];
		else
			red[b] = '.';
		b++;
		tab[0]++;
	}
	red[b] = '\0';
	return (red);
}

char			**ft_tet_red(char **full, t_struct lims, char c)
{
	int		a;
	char	**red;
	int		tab[3];
	int		b;

	b = 0;
	tab[0] = lims.x_min;
	tab[1] = lims.y_min;
	tab[2] = (int)c;
	a = 0;
	if (!(red = (char**)malloc(sizeof(char*) * \
					((lims.y_max - lims.y_min) + 2))))
		ft_error();
	while (tab[1] <= lims.y_max)
	{
		if (!(red[a] = (char*)malloc(sizeof(char) \
						* ((lims.x_max - lims.x_min) + 2))))
			ft_error();
		red[a] = ft_cut(red[a], full, tab, lims);
		tab[0] = lims.x_min;
		a++;
		tab[1]++;
	}
	red[a] = NULL;
	return (red);
}
