/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:02:50 by bpace             #+#    #+#             */
/*   Updated: 2019/07/28 06:30:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*assignans(char const *s, char *ans, int mallen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < mallen)
		ans[j++] = s[i++];
	ans[j] = '\0';
	return (ans);
}

char		*ft_strtrim(char const *s)
{
	char	*ans;
	int		mallen;
	int		i;

	i = 0;
	mallen = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		mallen++;
		i++;
	}
	while (s[--i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			&& mallen != 0)
		mallen--;
	ans = malloc(sizeof(char) * mallen + 1);
	if (!ans)
		return (NULL);
	return (assignans(s, ans, mallen));
}
