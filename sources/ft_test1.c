/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:01:52 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/26 11:12:21 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

size_t		ft_test1(char *str)
{
	int i;
	int p;
	int diese;

	diese = 0;
	p = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\0' ||
				str[i] == '.' || str[i] == '#'))
	{
		if (str[i] == '.')
			p++;
		if (str[i] == '#')
			diese++;
		i++;
	}
	if (p == 12 && diese == 4)
		return (1);
	else
		return (0);
}
