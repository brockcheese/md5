/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:35:20 by bpace             #+#    #+#             */
/*   Updated: 2019/07/25 14:06:47 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*ptr;
	unsigned char	temp;

	i = 0;
	ptr = (char *)b;
	temp = (unsigned char)c;
	while (i < len)
		ptr[i++] = temp;
	return (b);
}
