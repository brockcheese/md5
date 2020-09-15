/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:47:13 by bpace             #+#    #+#             */
/*   Updated: 2019/09/04 18:54:06 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_s(t_printf *data, char *temp)
{
	size_t	i;

	i = -1;
	data->fill = data->flag[2] ? ' ' : data->fill;
	while (data->flag[2] == 0 && (((data->period) == 1 && (int)data->width
					> data->precision) || data->width > ft_strlen(temp)))
	{
		ft_putchar(data->fill);
		data->ans++;
		data->width--;
	}
	while (temp[++i] && ((int)i < data->precision || data->period == 0))
	{
		ft_putchar(temp[i]);
		data->ans++;
	}
	while (data->flag[2] == 1 && (((data->period) == 1 && (int)data->width
					> data->precision) || data->width > ft_strlen(temp)))
	{
		ft_putchar(data->fill);
		data->ans++;
		data->width--;
	}
}

void	padding_c(t_printf *data)
{
	data->fill = data->flag[2] ? ' ' : data->fill;
	while (data->width-- > 1)
	{
		ft_putchar(data->fill);
		data->ans++;
	}
}
