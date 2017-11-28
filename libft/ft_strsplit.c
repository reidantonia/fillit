/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:58:52 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/21 16:34:48 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countword(char const *s, char c)
{
	int		i;
	int		m;

	i = 0;
	m = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		m++;
	}
	return (m);
}

static int	ft_countletter(char const *s, int i, char c)
{
	int		b;

	b = 0;
	while (s[i] != c && s[i] != '\0')
	{
		b++;
		i++;
	}
	return (b);
}

static char	*ft_place(char const *s, char **str, int m, char c)
{
	int l;
	int b;
	int i;

	i = 0;
	b = 0;
	l = 0;
	while (s[i] != '\0' && b < m)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			l = ft_countletter(s, i, c);
			str[b++] = ft_strsub(s, i, l);
			i = i + l;
		}
	}
	str[b] = 0;
	return (*str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		m;
	char	**str;

	if (!s)
		return (0);
	m = ft_countword(s, c);
	if (!(str = (char**)malloc(sizeof(char *) * (m + 1))))
		return (0);
	*str = ft_place(s, str, m, c);
	return (str);
}
