/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 04:57:00 by bpace             #+#    #+#             */
/*   Updated: 2019/08/29 19:31:44 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getmallen(int n)
{
	int	ans;

	ans = 0;
	if (n < 0)
		return (getmallen(-n) + 1);
	if ((n / 10) > 0)
		return (getmallen(n / 10) + 1);
	return (1);
}

static char	*assans(char *ans, int mallen, int neg, int n)
{
	while (mallen > neg)
	{
		ans[mallen--] = (n % 10) + '0';
		n = n / 10;
	}
	return (ans);
}

char		*ft_itoa(int n)
{
	int		mallen;
	char	*ans;
	int		neg;

	neg = -1;
	mallen = (n != -2147483648 ? getmallen(n) : 11);
	ans = malloc(sizeof(char) * (mallen + 1));
	if (!ans)
		return (NULL);
	ans[mallen--] = '\0';
	if (n < 0)
	{
		neg = 0;
		if (n == -2147483648)
		{
			neg++;
			n = 147483648;
			ans[1] = '2';
		}
		else
			n = -(n);
		ans[0] = '-';
	}
	return (assans(ans, mallen, neg, n));
}
