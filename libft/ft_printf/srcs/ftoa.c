/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:38:15 by bpace             #+#    #+#             */
/*   Updated: 2019/09/06 16:51:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getmallenf(t_printf *data, long long n)
{
	if (n == 0)
		return (7);
	if (n < 0)
		return (getmallenf(data, -(n)));
	if (n / 10 > 0)
		return (getmallenf(data, n / 10) + 1);
	return (1);
}

static char	*ftoacont(int i, int mallen, char *ans, long long nconv)
{
	int		neg;

	neg = -1;
	ans[mallen + 1] = '\0';
	if (nconv < 0)
	{
		neg = 0;
		nconv = -(nconv);
		ans[0] = '-';
	}
	while (--i > -1)
	{
		ans[mallen--] = (nconv % 10) + '0';
		nconv = nconv / 10;
	}
	ans[mallen--] = '.';
	while (mallen > neg)
	{
		ans[mallen--] = (nconv % 10) + '0';
		nconv = nconv / 10;
	}
	return (ans);
}

char		*ftoa(t_printf *data, long double n)
{
	char		*ans;
	int			i;
	int			mallen;
	long long	nconv;

	data->precision = data->period ? data->precision : 6;
	i = -1;
	while (++i <= data->precision)
		n = n * 10;
	i--;
	nconv = (long long)n;
	nconv += nconv % 10 >= 5 ? 10 : 0;
	nconv /= 10;
	mallen = getmallenf(data, nconv);
	mallen = data->precision > mallen ? data->precision + 1 : mallen;
	mallen += nconv < 0 ? 1 : 0;
	if (!(ans = malloc(sizeof(char) * (mallen + 2))))
		return (NULL);
	return (ftoacont(i, mallen, ans, nconv));
}
