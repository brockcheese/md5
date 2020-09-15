/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:53:56 by bpace             #+#    #+#             */
/*   Updated: 2019/09/06 15:55:53 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		padding_leftadjust(t_printf *data, char *new)
{
	if (data->sign == '-' || data->flag[3] == 1 || data->flag[4] == 1 ||
			(data->flag[0] == 1 && new[0] && new[0] != '0') || data->isp == 1)
	{
		if (data->flag[1] == 1 && data->flag[0] == 1 && data->basen == 8)
			ft_putchar(data->pound[0]);
		else if ((data->flag[0] == 1 && data->basen == 16) || data->isp == 1)
		{
			if (data->flag[1] == 1)
				ft_putstr(data->pound);
			data->ans++;
			data->width -= data->width == 0 ? 0 : 1;
		}
		else if (data->flag[1] == 1 && data->period == 0)
			ft_putchar(data->sign);
		data->ans++;
		data->width -= data->width == 0 ? 0 : 1;
	}
}

static void		padding_leftfill(t_printf *data, char *new)
{
	if (data->flag[2] == 0)
	{
		while (data->width > (size_t)data->precision &&
				data->width > ft_strlen(new))
		{
			data->fill = data->period ? ' ' : data->fill;
			ft_putchar(data->fill);
			data->ans++;
			data->width--;
		}
	}
	if ((data->flag[1] == 0 || data->period == 1) &&
			(data->flag[3] == 1 || data->flag[4] == 1 || data->sign == '-'))
		ft_putchar(data->sign);
	else if (data->flag[1] == 0 && data->flag[0] == 1 && data->basen == 8
			&& new[0] && new[0] != '0')
		ft_putchar(data->pound[0]);
	else if ((data->flag[1] == 0 && data->flag[0] == 1 && data->basen == 16
			&& new[0] && new[0] != '0') || data->isp == 1)
		ft_putstr(data->pound);
}

static void		padding_rightfill(t_printf *data, char *new)
{
	int i;

	i = 0;
	while ((size_t)(data->precision - i++) > ft_strlen(new))
	{
		ft_putchar('0');
		data->ans++;
	}
	ft_putstr(new);
	data->ans += ft_strlen(new);
	if (data->flag[2] == 1)
	{
		while (data->width > (size_t)data->precision &&
				data->width > ft_strlen(new))
		{
			ft_putchar(' ');
			data->ans++;
			data->width--;
		}
	}
}

void			padding_diouxx(t_printf *data, char *temp)
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
	padding_leftadjust(data, new);
	padding_leftfill(data, new);
	padding_rightfill(data, new);
	ft_strdel(&new);
}
