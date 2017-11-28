/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:52:28 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/22 13:47:49 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	ft_find(const char *haystack, const char *needle, size_t len, int i)
{
	size_t b;

	b = 0;
	while (haystack[i] == needle[b] && needle[b] != '\0' && (size_t)i < len)
	{
		i++;
		b++;
	}
	return (b);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	b;

	b = 0;
	i = 0;
	if (!needle[b])
		return ((char *)haystack);
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == needle[b])
			b = ft_find(haystack, needle, len, i);
		if (needle[b] == '\0')
			return ((char *)&haystack[i]);
		i++;
		b = 0;
	}
	return (0);
}
