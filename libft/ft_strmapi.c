/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:27:42 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/17 11:49:46 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	int		len_s;

	i = 0;
	str = (char *)s;
	if (s && f)
	{
		len_s = ft_strlen(s);
		str = ft_strnew(len_s);
		if (!str)
			return (0);
		while (i < len_s)
		{
			str[i] = (*f)(i, s[i]);
			i++;
		}
		return (str);
	}
	return (0);
}
