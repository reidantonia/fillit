/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:42:28 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/17 15:32:17 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t b;
	size_t len_src;
	size_t len_dest;

	i = 0;
	b = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (len_dest >= size)
		return (len_src + size);
	i = len_dest;
	while (src[b] != '\0' && (i + b) < size - 1)
	{
		dest[i + b] = src[b];
		b++;
	}
	dest[i + b] = '\0';
	return (len_src + len_dest);
}
