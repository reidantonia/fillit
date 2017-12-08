/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:38:34 by areid             #+#    #+#             */
/*   Updated: 2017/11/29 16:20:53 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void	ft_remove(char **board, t_res *alst)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (board[y] && alst)
	{
		while (board[y][x] && alst)
		{
			if (board[y][x] == alst->letter)
				board[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

int		ft_notfit(int x, int y, char **board, t_res *alst)
{
	int b;
	int i;
	int j;
	int add;

	b = x - 1;
	i = 0;
	j = 0;
	add = 0;
	while (board[y] && alst->res_dom[i])
	{
		while (board[y][++b] && alst->res_dom[i][j])
		{
			if (alst->res_dom[i][j++] == alst->letter && board[y][b] != '.')
				return (1);
			add++;
		}
		b = x - 1;
		j = 0;
		y++;
		i++;
	}
	if ((i != alst->height) || (add != (alst->width * alst->height)))
		return (1);
	return (0);
}

int		ft_place(int x, int y, char **board, t_res *alst)
{
	int b;
	int i;
	int j;

	b = x;
	i = 0;
	j = 0;
	if (ft_notfit(x, y, board, alst))
		return (0);
	while (board[y] != '\0' && alst->res_dom[i])
	{
		while (board[y][b] != '\0' && alst->res_dom[i][j] != '\n')
		{
			if (alst->res_dom[i][j] == alst->letter)
				board[y][b] = alst->res_dom[i][j];
			b++;
			j++;
		}
		b = x;
		j = 0;
		y++;
		i++;
	}
	return (1);
}

int		ft_solver(char **board, t_res *alst)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!alst)
		return (1);
	while (board[y])
	{
		while (board[y][x])
		{
			if (ft_place(x, y, board, alst))
			{
				if ((ft_solver(board, alst->next)) == 1)
					return (1);
				ft_remove(board, alst);
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	return (0);
}
