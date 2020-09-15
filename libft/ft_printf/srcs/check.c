/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 00:05:27 by bpace             #+#    #+#             */
/*   Updated: 2019/09/06 19:01:21 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		checklength2(t_printf *data)
{
	if (data->formatcp[data->i] == 'j' || data->formatcp[data->i] == 'z')
	{
		data->length = data->formatcp[data->i] == 'j' ? 5 : 6;
		data->i++;
	}
	else if (data->formatcp[data->i] == 'L')
	{
		data->length = 7;
		data->i++;
	}
}

void			checklength(t_printf *data)
{
	if (data->formatcp[data->i] == 'h')
	{
		data->length = data->length > 1 ? data->length : 1;
		if (data->formatcp[++data->i] == 'h')
		{
			data->length++;
			data->i++;
		}
	}
	else if (data->formatcp[data->i] == 'l')
	{
		data->length = data->length > 3 ? data->length : 3;
		if (data->formatcp[++data->i] == 'l')
		{
			data->length++;
			data->i++;
		}
	}
	else
		checklength2(data);
}

static void		checkprecision2(t_printf *data)
{
	while (ft_isdigit(data->formatcp[data->i]))
	{
		data->precision *= 10;
		data->precision += (data->formatcp[data->i]) - '0';
		data->i++;
	}
}

void			checkprecision(t_printf *data)
{
	char	c;

	c = data->fill;
	if (data->formatcp[data->i] == '.')
	{
		data->fill = ' ';
		data->period = 1;
		data->i++;
		data->precision = 0;
		if (data->formatcp[data->i] == '*')
		{
			data->precision = va_arg(data->vl, int);
			if (data->precision < 0)
			{
				data->precision = 0;
				data->period = 0;
				data->fill = c;
			}
			data->i++;
		}
		else
			checkprecision2(data);
	}
}

void			checkwidth(t_printf *data)
{
	int	temp;

	if (data->formatcp[data->i] == '*')
	{
		temp = va_arg(data->vl, int);
		if (temp < 0)
			data->flag[2] = 1;
		temp = temp < 0 ? -(temp) : temp;
		data->width = temp;
		data->i++;
	}
	else
	{
		if (data->formatcp[data->i] >= '1' && data->formatcp[data->i] <= '9')
		{
			data->width = 0;
			while (ft_isdigit(data->formatcp[data->i]))
			{
				data->width *= 10;
				data->width += (data->formatcp[data->i]) - '0';
				data->i++;
			}
		}
	}
}
