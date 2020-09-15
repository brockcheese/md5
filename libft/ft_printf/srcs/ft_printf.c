/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:32:08 by bpace             #+#    #+#             */
/*   Updated: 2019/09/05 20:35:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init(t_printf *data, const char *format)
{
	data->ans = 0;
	data->i = 0;
	data->formatcp = (char *)format;
}

static void		init2(t_printf *data)
{
	int i;

	i = -1;
	while (++i < 5)
		data->flag[i] = 0;
	data->width = 0;
	data->precision = 0;
	data->period = 0;
	data->length = 0;
	data->fill = ' ';
	data->sign = ' ';
	data->pound[0] = '0';
	data->pound[1] = 'x';
	data->basen = 10;
	data->isp = 0;
}

static void		checkflags(t_printf *data)
{
	while (data->formatcp[data->i] && !ft_isalpha(data->formatcp[data->i]) &&
			data->formatcp[data->i] != '.' && data->formatcp[data->i] != '*' &&
			(data->formatcp[data->i] < '1' || data->formatcp[data->i] > '9')
			&& data->formatcp[data->i] != '%')
	{
		if (data->formatcp[data->i] == '#')
			data->flag[0] = 1;
		else if (data->formatcp[data->i] == '0')
		{
			data->flag[1] = 1;
			data->fill = '0';
		}
		else if (data->formatcp[data->i] == '-')
			data->flag[2] = 1;
		else if (data->formatcp[data->i] == '+')
		{
			data->flag[3] = 1;
			data->sign = '+';
		}
		else if (data->formatcp[data->i] == ' ')
			data->flag[4] = 1;
		data->i++;
	}
}

static void		getans(t_printf *data)
{
	while (data->formatcp && data->formatcp[data->i])
	{
		if (data->formatcp[data->i] == '%')
		{
			init2(data);
			data->i++;
			while (data->formatcp[data->i] && data->formatcp[data->i] != '%'
					&& (!ft_isalpha(data->formatcp[data->i])
						|| ft_strchr("lhjzL", data->formatcp[data->i])))
			{
				checkflags(data);
				checkwidth(data);
				checkprecision(data);
				checklength(data);
			}
			convert(data);
		}
		else
		{
			ft_putchar(data->formatcp[data->i]);
			data->ans++;
		}
		if (data->formatcp[data->i])
			data->i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf	*data;

	if (!(data = malloc(sizeof(t_printf))))
		return (-1);
	va_start(data->vl, format);
	init(data, format);
	if (format)
		getans(data);
	va_end(data->vl);
	free(data);
	return (data->ans);
}
