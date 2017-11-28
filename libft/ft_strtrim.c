/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:20:55 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/22 14:52:27 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_cmpav(char const *s)
{
	size_t		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_cmpar(char const *s, size_t len, size_t i)
{
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len > i)
	{
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len_s;
	char	*str;
	size_t	b;
	size_t	c;

	c = 0;
	b = 0;
	i = 0;
	if (!s)
		return (0);
	len_s = ft_strlen(s) - 1;
	i = ft_cmpav(s);
	b = ft_cmpar(s, len_s, i);
	str = ft_strsub(s, i, (b - i + 1));
	return (str);
}
