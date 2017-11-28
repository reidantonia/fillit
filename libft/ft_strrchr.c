/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:54:32 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/20 19:16:50 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;
	int		len_s;

	b = (char)c;
	i = 0;
	len_s = ft_strlen(s);
	while (len_s >= 0)
	{
		if (s[len_s] == b)
			return ((char *)&s[len_s]);
		len_s--;
	}
	return (0);
}
