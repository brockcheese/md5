/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:51:51 by bpace             #+#    #+#             */
/*   Updated: 2019/07/30 15:53:19 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*ans;
	unsigned int	i;

	ans = begin_list;
	i = 0;
	while (i < nbr)
	{
		if (!ans)
			return (ans);
		ans = ans->next;
		i++;
	}
	return (ans);
}
