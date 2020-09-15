/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:28:08 by bpace             #+#    #+#             */
/*   Updated: 2019/07/25 18:37:40 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstptr;
	char	*srcptr;

	i = 0;
	dstptr = (char *)dst;
	srcptr = (char *)src;
	if (!dstptr && !srcptr && len > 0)
		return (NULL);
	if (dstptr > srcptr)
	{
		while (len-- > i)
			dstptr[len] = srcptr[len];
	}
	else
	{
		while (i < len)
		{
			dstptr[i] = srcptr[i];
			i++;
		}
	}
	return (dst);
}
