/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:27 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/29 16:22:05 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"
#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_read(argv[1]);
	}
	else
	{
		ft_putstr("usage : ./fillit source_file\n");
	}
	return (0);
}
