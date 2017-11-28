/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:55:52 by areid             #+#    #+#             */
/*   Updated: 2017/11/27 20:47:06 by areid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

char	**ft_board_calc(int board_size)
{
	int		a;
	char	**board;

	a = 0;
	board = (char**)malloc(sizeof(char*) * (board_size + 1));
	while (a < board_size)
	{
		board[a] = ft_strnew(board_size);
		board[a] = ft_memset(board[a], '.', board_size);
		a++;
	}
	board[a] = NULL;
	return (board);
}
