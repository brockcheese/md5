/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:18:52 by bpace             #+#    #+#             */
/*   Updated: 2019/07/28 06:29:21 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ans;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ans = malloc(sizeof(char) * len + 1);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ans[i] = f(s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
