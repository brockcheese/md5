/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:27:49 by bpace             #+#    #+#             */
/*   Updated: 2019/09/02 21:57:33 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	getmallen(t_printf *data, unsigned long long n, int base)
{
	if (n / base > 0)
		return (getmallen(data, n / base, base) + 1);
	if (data->period == 1 && data->precision == 0 && n == 0 &&
			!(data->basen == 8 && data->flag[0] == 1))
		return (0);
	return (1);
}

char		*base_itoa(t_printf *data, unsigned long long n, int base)
{
	int		mallen;
	char	*ans;
	int		digit;
	char	output;

	data->basen = base;
	mallen = getmallen(data, n, base);
	if (!(ans = malloc(sizeof(char) * (mallen + 1))))
		return (NULL);
	ans[mallen--] = '\0';
	while (mallen >= 0)
	{
		output = 96;
		digit = n % base;
		if (digit < 10)
			ans[mallen--] = (digit) + '0';
		else
		{
			while (--digit >= 9)
				output++;
			ans[mallen--] = output;
		}
		n = n / base;
	}
	return (ans);
}
