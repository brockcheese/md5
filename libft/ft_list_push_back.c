/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:14:16 by bpace             #+#    #+#             */
/*   Updated: 2019/07/30 15:27:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data, size_t content_size)
{
	t_list	*nex;

	if (!*begin_list)
		*begin_list = ft_lstnew(data, content_size);
	else
	{
		nex = *begin_list;
		while (nex->next)
			nex = nex->next;
		nex->next = ft_lstnew(data, content_size);
	}
}
