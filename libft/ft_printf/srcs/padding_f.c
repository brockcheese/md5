/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:01:54 by bpace             #+#    #+#             */
/*   Updated: 2019/09/05 20:06:56 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		padding_leftadjust(t_printf *data)
{
	if (data->sign == '-' || data->flag[3] == 1 || data->flag[4] == 1)
	{
		data->ans++;
		data->width -= data->width == 0 ? 0 : 1;
	}
}

static void		padding_leftfill(t_printf *data, char *new)
{
	if (data->flag[2] == 0)
	{
		while (data->width > ft_strlen(new))
		{
			ft_putchar(' ');
			data->ans++;
			data->width--;
		}
	}
	if (data->flag[1] == 0 && (data->flag[3] == 1 || data->flag[4] == 1
				|| data->sign == '-'))
		ft_putchar(data->sign);
}

static void		padding_rightfill(t_printf *data, char *new)
{
	ft_putstr(new);
	data->ans += ft_strlen(new);
	if (data->flag[2] == 1)
	{
		while (data->width > ft_strlen(new))
		{
			ft_putchar(' ');
			data->ans++;
			data->width--;
		}
	}
}

void			padding_f(t_printf *data, char *temp)
{
	char	*new;

	if (temp[0] == '-')
	{
		data->sign = '-';
		new = ft_strsub(temp, 1, ft_strlen(temp));
	}
	else
	{
		if (!(new = malloc(sizeof(char) * (ft_strlen(temp) + 1))))
			return ;
		new = ft_strcpy(new, temp);
	}
	padding_leftadjust(data);
	padding_leftfill(data, new);
	padding_rightfill(data, new);
	ft_strdel(&new);
}
