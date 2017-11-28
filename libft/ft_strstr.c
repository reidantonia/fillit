/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:03:02 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/17 09:41:40 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int b;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		b = 0;
		while (haystack[i + b] == needle[b] && needle[b] != '\0')
			b++;
		if (needle[b] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
