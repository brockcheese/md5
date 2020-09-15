/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 09:00:17 by bpace             #+#    #+#             */
/*   Updated: 2019/07/30 15:06:46 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *ans;
	t_list *curr;

	if (!lst)
		return (NULL);
	curr = lst;
	tmp = f(curr);
	if (!tmp)
		return (NULL);
	ans = tmp;
	while (curr->next)
	{
		curr = curr->next;
		tmp->next = f(curr);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (ans);
}
