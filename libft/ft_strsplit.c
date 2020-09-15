/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 03:21:57 by bpace             #+#    #+#             */
/*   Updated: 2019/10/15 18:45:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getmallen(char const *s, char c)
{
	int	i;
	int mallen;

	i = -1;
	mallen = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			mallen++;
			while (s[i + 1] != c && s[i + 1] != '\0')
				i++;
		}
	}
	return (mallen);
}

static int	getmallensmall(char const *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != c)
		;
	return (i);
}

static int	stupidnormline(char const *s, int i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		mallen;
	char	**ans;
	int		i;
	int		ansi;
	int		ansi2;

	i = 0;
	if (!s)
		return (NULL);
	mallen = getmallen(s, c);
	ans = malloc(sizeof(char *) * (mallen + 1));
	if (!ans)
		return (NULL);
	ans[mallen] = NULL;
	ansi = -1;
	while (++ansi < mallen)
	{
		ansi2 = 0;
		i = stupidnormline(s, i, c);
		ans[ansi] = malloc(sizeof(char) * (getmallensmall(s + i, c) + 1));
		while (s[i] && s[i] != c)
			ans[ansi][ansi2++] = s[i++];
		ans[ansi][ansi2] = '\0';
	}
	return (ans);
}
