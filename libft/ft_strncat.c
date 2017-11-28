/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:42:28 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/17 16:00:25 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t b;

	b = 0;
	i = ft_strlen(dest);
	while (src[b] != '\0' && b < n)
	{
		dest[i + b] = src[b];
		b++;
	}
	dest[i + b] = '\0';
	return (dest);
}
