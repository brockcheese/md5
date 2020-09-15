/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 07:46:39 by bpace             #+#    #+#             */
/*   Updated: 2019/07/28 08:16:13 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;
	t_list	*curr;

	curr = *alst;
	nxt = NULL;
	while (curr)
	{
		if (curr->next)
			nxt = curr->next;
		else
			nxt = NULL;
		ft_lstdelone(&curr, del);
		curr = nxt;
	}
	*alst = NULL;
}
