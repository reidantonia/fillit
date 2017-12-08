/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:16:30 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/30 11:02:11 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

static t_struct		ft_lims(char *str)
{
	int			i;
	t_struct	lims;

	i = 0;
	while (str[i] != '#')
		i++;
	lims.x_min = i % 5;
	lims.x_max = lims.x_min;
	lims.y_min = i / 5;
	lims.y_max = lims.y_min;
	while (str[i++])
	{
		if (str[i] == '#')
		{
			if (lims.x_min > (i % 5))
				lims.x_min = i % 5;
			if (lims.x_max < (i % 5))
				lims.x_max = i % 5;
			if (lims.y_min > (i / 5))
				lims.y_min = (i / 5);
			if (lims.y_max < (i / 5))
				lims.y_max = (i / 5);
		}
	}
	return (lims);
}

static char			**ft_tet_full(char *str)
{
	int		i;
	int		a;
	int		b;
	char	**tab;

	i = 0;
	a = 0;
	b = 0;
	tab = (char**)malloc(sizeof(char*) * 5);
	while (str[i] != '\0' && a < 4)
	{
		tab[a] = ft_strnew(4);
		while (str[i] != '\0' && b < 4)
		{
			tab[a][b] = str[i];
			b++;
			i++;
		}
		tab[a][b] = '\0';
		b = 0;
		i++;
		a++;
	}
	tab[a] = NULL;
	return (tab);
}

static t_res		*ft_tetris(char *str, t_res *alst)
{
	static char		let = 'A';
	char			**res;
	char			**tetris;
	t_struct		hi;

	str[BUF_SIZE] = '\0';
	if (ft_test1(str) == 0 || ft_test2(str) < 6)
		ft_error();
	tetris = ft_tet_full(str);
	hi = ft_lims(str);
	res = ft_tet_red(tetris, hi, let);
	alst = ft_stock(res, &alst, let, hi);
	let++;
	return (alst);
}

void				ft_read(char *av)
{
	int			fd;
	int			ret;
	size_t		i;
	char		str[BUF_SIZE + 1];
	t_res		*alst;

	alst = NULL;
	i = 0;
	ret = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error();
	while ((ret = read(fd, str, BUF_SIZE)))
	{
		if (str[0] == '\n')
			ft_error();
		alst = ft_tetris(str, alst);
		i = i + ret;
	}
	ft_print_map(ft_min_sq(i, alst));
	free(alst);
	alst = NULL;
}
