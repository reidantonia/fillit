/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:16:14 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/21 16:50:24 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*str2;

	dst2 = (char *)dst;
	str2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = str2[i];
		if (str2[i] == (const char)c)
		{
			return ((void *)&dst2[i + 1]);
		}
		i++;
	}
	return (NULL);
}
