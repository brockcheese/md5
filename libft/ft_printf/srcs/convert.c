/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:20:58 by bpace             #+#    #+#             */
/*   Updated: 2019/09/06 15:32:28 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		convert_p(t_printf *data)
{
	unsigned long long	convert;
	intptr_t			intptr;
	char				*temp;

	data->isp = 1;
	intptr = va_arg(data->vl, intptr_t);
	convert = (unsigned long long)intptr;
	if (convert == 0)
		temp = ft_strdup("0");
	else
		temp = base_itoa(data, convert, 16);
	padding_diouxx(data, temp);
	ft_strdel(&temp);
}

static void		convert_f(t_printf *data)
{
	long double	convert;
	char		*temp;

	if (data->length == 7)
		convert = va_arg(data->vl, long double);
	else
		convert = (long double)va_arg(data->vl, double);
	temp = ftoa(data, convert);
	padding_f(data, temp);
	ft_strdel(&temp);
}

static void		convert_csp(t_printf *data, char c)
{
	char	*temp;

	if (c == 's')
	{
		temp = va_arg(data->vl, char *);
		if (temp == NULL)
			temp = "(null)";
		padding_s(data, temp);
	}
	if (c == 'c')
	{
		if (data->flag[2] == 0)
			padding_c(data);
		ft_putchar((char)va_arg(data->vl, int));
		if (data->flag[2] == 1)
			padding_c(data);
		data->ans++;
	}
	if (c == 'p')
		convert_p(data);
}

static void		convert_percent(t_printf *data)
{
	if (data->flag[2] == 0)
	{
		padding_c(data);
	}
	ft_putchar('%');
	if (data->flag[2] == 1)
	{
		padding_c(data);
	}
	data->ans++;
}

void			convert(t_printf *data)
{
	if (data->formatcp[data->i] == 'c' || data->formatcp[data->i] == 's'
			|| data->formatcp[data->i] == 'p')
		convert_csp(data, data->formatcp[data->i]);
	else if (data->formatcp[data->i] == '%')
		convert_percent(data);
	else if (data->formatcp[data->i] == 'd' || data->formatcp[data->i] == 'i'
			|| data->formatcp[data->i] == 'o' || data->formatcp[data->i] == 'u'
			|| data->formatcp[data->i] == 'x' || data->formatcp[data->i] == 'X'
			|| data->formatcp[data->i] == 'U' || data->formatcp[data->i] == 'b')
		convert_diouxx(data, data->formatcp[data->i]);
	else if (data->formatcp[data->i] == 'f')
		convert_f(data);
	else if (data->formatcp[data->i])
	{
		data->ans++;
		ft_putchar(data->formatcp[data->i]);
	}
}
