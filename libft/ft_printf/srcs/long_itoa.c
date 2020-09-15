/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:53:37 by bpace             #+#    #+#             */
/*   Updated: 2019/09/04 19:01:19 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	llgetmallen(long long n)
{
	int	ans;

	ans = 0;
	if (n < 0)
		return (llgetmallen(-n) + 1);
	if ((n / 10) > 0)
		return (llgetmallen(n / 10) + 1);
	return (1);
}

static char	*llassans(char *ans, int mallen, int neg, long long n)
{
	while (mallen > neg)
	{
		ans[mallen--] = (n % 10) + '0';
		n = n / 10;
	}
	return (ans);
}

char		*long_itoa(long long n)
{
	int		mallen;
	char	*ans;
	int		neg;

	neg = -1;
	mallen = (n != LLONG_MIN ? llgetmallen(n) : 20);
	ans = malloc(sizeof(char) * (mallen + 1));
	if (!ans)
		return (NULL);
	ans[mallen--] = '\0';
	if (n < 0)
	{
		neg = 0;
		if (n == LLONG_MIN)
		{
			neg++;
			n = 223372036854775808;
			ans[1] = '9';
		}
		else
			n = -(n);
		ans[0] = '-';
	}
	return (llassans(ans, mallen, neg, n));
}
