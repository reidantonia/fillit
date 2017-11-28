/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:11:22 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/21 16:10:24 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len_s;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	if (s && f)
	{
		str = ft_strnew(len_s);
		if (!str)
			return (0);
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
		return (str);
	}
	return (0);
}
