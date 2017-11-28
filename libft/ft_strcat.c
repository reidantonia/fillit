/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:42:28 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/17 09:40:21 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[b] != '\0')
	{
		dest[i + b] = src[b];
		b++;
	}
	dest[i + b] = '\0';
	return (dest);
}
