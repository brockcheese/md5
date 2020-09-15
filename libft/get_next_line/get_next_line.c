/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:25:10 by bpace             #+#    #+#             */
/*   Updated: 2019/09/26 03:05:30 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		returnline(ssize_t reader, char **ans_fd, char **line, char *temp)
{
	int	i;

	if (reader < 0)
		return (-1);
	if (reader < BUFF_SIZE && !ft_strlen(*ans_fd))
		return (0);
	i = -1;
	while ((*ans_fd)[++i] != '\n' && (*ans_fd)[i])
		;
	if (!(*line = ft_strsub(*ans_fd, 0, i)))
		return (-1);
	if (!(*ans_fd)[i])
		temp = NULL;
	else if (!(temp = ft_strsub(*ans_fd, i + 1, ft_strlen(*ans_fd))))
		return (-1);
	ft_strdel(ans_fd);
	*ans_fd = temp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t		reader;
	static char	*ans[10000];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	if (!ans[fd])
		ans[fd] = ft_strnew(0);
	while ((reader = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[reader] = '\0';
		if (!(temp = ft_strjoin(ans[fd], buffer)))
			return (-1);
		ft_strdel(&ans[fd]);
		ans[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (returnline(reader, &ans[fd], line, temp));
}
