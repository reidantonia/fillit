/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:12:47 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/29 16:19:46 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

char	**ft_min_sq(int i, t_res *alst)
{
	int		x;
	char	**board;
	int		min_sq_req;

	x = 0;
	if ((i % 21) != 20)
		ft_error();
	min_sq_req = ((i + 1) / 21) * 4;
	while (x * x < min_sq_req)
		x++;
	board = ft_board_calc(x);
	while (!(ft_solver(board, alst)))
	{
		free(board);
		x++;
		board = ft_board_calc(x);
	}
	return (board);
}
