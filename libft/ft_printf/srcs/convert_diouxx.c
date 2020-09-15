/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:43:43 by bpace             #+#    #+#             */
/*   Updated: 2019/09/06 14:08:13 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*convert_di(t_printf *data)
{
	char	*temp;

	if (data->length == 1)
		temp = ft_itoa((int)(short)va_arg(data->vl, int));
	else if (data->length == 2)
		temp = ft_itoa((int)(signed char)va_arg(data->vl, int));
	else if (data->length == 3)
		temp = long_itoa((long long)va_arg(data->vl, long));
	else if (data->length == 4)
		temp = long_itoa(va_arg(data->vl, long long));
	else if (data->length == 5)
		temp = long_itoa((long long)va_arg(data->vl, intmax_t));
	else if (data->length == 6)
		temp = long_itoa((long long)va_arg(data->vl, size_t));
	else
		temp = ft_itoa(va_arg(data->vl, int));
	if (data->period == 1 && data->precision == 0 && temp[0] == '0')
	{
		ft_strdel(&temp);
		temp = ft_strnew(1);
	}
	return (temp);
}

unsigned long long	getconvert(t_printf *data)
{
	unsigned long long	convert;

	if (data->length == 1)
		convert = (unsigned long long)(unsigned short)va_arg(data->vl,
				unsigned int);
	else if (data->length == 2)
		convert = (unsigned long long)(unsigned char)va_arg(data->vl,
				unsigned int);
	else if (data->length == 3)
		convert = (unsigned long long)va_arg(data->vl, unsigned long);
	else if (data->length == 4)
		convert = va_arg(data->vl, unsigned long long);
	else if (data->length == 5)
		convert = (unsigned long long)va_arg(data->vl, intmax_t);
	else if (data->length == 6)
		convert = (unsigned long long)va_arg(data->vl, size_t);
	else
		convert = (unsigned long long)va_arg(data->vl, unsigned int);
	return (convert);
}

static char			*convert_ouxx(t_printf *data, char c)
{
	char				*temp;
	unsigned long long	convert;

	if (c == 'U')
		data->length = 3;
	convert = getconvert(data);
	if (c == 'b')
		temp = base_itoa(data, convert, 2);
	if (c == 'o')
		temp = base_itoa(data, convert, 8);
	if (c == 'u' || c == 'U')
	{
		temp = base_itoa(data, convert, 10);
		data->flag[3] = 0;
		data->flag[4] = 0;
	}
	if (c == 'x' || c == 'X')
		temp = base_itoa(data, convert, 16);
	if (c == 'X')
	{
		temp = ft_strcap(temp);
		data->pound[1] = 'X';
	}
	return (temp);
}

void				convert_diouxx(t_printf *data, char c)
{
	char				*temp;

	if (c == 'd' || c == 'i')
		temp = convert_di(data);
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'U' || c == 'b')
		temp = convert_ouxx(data, c);
	padding_diouxx(data, temp);
	ft_strdel(&temp);
}
