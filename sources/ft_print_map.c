/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:16:50 by areid             #+#    #+#             */
/*   Updated: 2017/11/29 16:20:01 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void	ft_print_map(char **board)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (board[y])
	{
		ft_putstr(board[y]);
		ft_putstr("\n");
		y++;
	}
}
