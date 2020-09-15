/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:22:52 by bpace             #+#    #+#             */
/*   Updated: 2019/09/09 02:04:46 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "../../libft.h"

typedef struct	s_printf
{
	int			i;
	va_list		vl;
	int			ans;
	int			isp;
	char		fill;
	char		sign;
	int			basen;
	size_t		width;
	int			length;
	int			period;
	int			flag[5];
	char		pound[2];
	char		*formatcp;
	int			precision;
}				t_printf;

void			convert(t_printf *data);
char			*long_itoa(long long n);
void			padding_c(t_printf *data);
void			checkwidth(t_printf *data);
void			checklength(t_printf *data);
void			checkprecision(t_printf *data);
char			*ftoa(t_printf *data, long double n);
void			padding_f(t_printf *data, char *temp);
void			padding_s(t_printf *data, char *temp);
void			convert_diouxx(t_printf *data, char c);
void			padding_diouxx(t_printf *data, char *temp);
int				ft_printf(const char *restrict format, ...);
char			*base_itoa(t_printf *data, unsigned long long n, int base);

#endif
