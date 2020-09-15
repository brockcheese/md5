/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:12:48 by bpace             #+#    #+#             */
/*   Updated: 2019/09/05 19:27:59 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		i;
	char	*ans;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if ((size_t)i > n)
		i = n;
	ans = ft_memalloc(i + 1);
	if (ans == NULL)
		return (NULL);
	ans[i] = '\0';
	while (--i >= 0)
		ans[i] = s1[i];
	return (ans);
}
