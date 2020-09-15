/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:55:41 by bpace             #+#    #+#             */
/*   Updated: 2019/07/25 16:12:57 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	size_t	i;
	char	*dstptr;
	char	*srcptr;

	i = 0;
	dstptr = (char *)dst;
	srcptr = (char *)src;
	if (dstptr || srcptr || n == 0)
	{
		while (i < n)
		{
			dstptr[i] = srcptr[i];
			if (srcptr[i] == (char)c)
				return (dst + i + 1);
			i++;
		}
	}
	return (NULL);
}
