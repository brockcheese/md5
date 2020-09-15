/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:09:29 by bpace             #+#    #+#             */
/*   Updated: 2019/07/25 18:36:08 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*sptr;

	i = 0;
	sptr = (char *)s;
	while (i < n)
	{
		if (sptr[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
