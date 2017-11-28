/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:54:16 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/22 11:39:08 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *c)
{
	int		i;
	char	*str;

	i = 0;
	while (c[i] != '\0')
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (0);
	i = 0;
	while (c[i] != '\0')
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
