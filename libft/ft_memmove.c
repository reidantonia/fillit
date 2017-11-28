/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:52:11 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/17 09:34:18 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	if (src > dst)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else if (src < dst)
	{
		i = len - 1;
		while (len--)
		{
			dst2[i] = src2[i];
			i--;
		}
	}
	return ((void *)dst2);
}
