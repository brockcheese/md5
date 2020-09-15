/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:47:51 by bpace             #+#    #+#             */
/*   Updated: 2019/10/15 18:45:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

char	*getstdin(const int fd)
{
	ssize_t	reader;
	char	*ans;
	char	*temp;
	char	buffer[2];

	ans = ft_strnew(0);
	while ((reader = read(fd, buffer, 1)))
	{
		buffer[reader] = '\0';
		if (!(temp = ft_strjoin(ans, buffer)))
			return (NULL);
		ft_strdel(&ans);
		ans = temp;
	}
	return (ans);
}
