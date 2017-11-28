/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:21:52 by mjoubert          #+#    #+#             */
/*   Updated: 2017/11/21 09:08:09 by mjoubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		ft_countnb(int n, int neg)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (neg == 1)
		return (i + 1);
	return (i);
}

static char		*ft_word(char *s, int n, int neg, int i)
{
	while (n >= 10)
	{
		s[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (n < 10)
		s[i] = n + 48;
	if (neg == 1)
		s[0] = '-';
	return (s);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		neg;

	neg = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		i++;
		neg++;
		n = n * -1;
	}
	i = ft_countnb(n, neg);
	if (!(str = ft_strnew(i)))
		return (0);
	str = ft_word(str, n, neg, (i - 1));
	return (str);
}
