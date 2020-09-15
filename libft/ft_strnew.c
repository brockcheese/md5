/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 08:58:36 by bpace             #+#    #+#             */
/*   Updated: 2019/07/28 06:28:56 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = malloc(size + 1);
	if (ans == NULL)
		return (NULL);
	while (i < size + 1)
		ans[i++] = '\0';
	return (ans);
}
