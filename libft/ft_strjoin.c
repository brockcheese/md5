/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 23:46:35 by bpace             #+#    #+#             */
/*   Updated: 2019/07/28 06:30:16 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		ansi;

	if (!s1 || !s2)
		return (NULL);
	ans = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ans)
		return (NULL);
	i = 0;
	ansi = 0;
	while (s1[i] != '\0')
		ans[ansi++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		ans[ansi++] = s2[i++];
	ans[ansi] = '\0';
	return (ans);
}
