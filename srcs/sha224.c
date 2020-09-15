/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 02:30:31 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:07:42 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void		sha224(char **input)
{
	size_t		chonk;
	u_int32_t	hasheight[8];
	char		singlechunk[64];
	size_t		i;
	u_int32_t	w[64];

	chonk = sha256padding(input);
	hasheight[0] = 0xc1059ed8;
	hasheight[1] = 0x367cd507;
	hasheight[2] = 0x3070dd17;
	hasheight[3] = 0xf70e5939;
	hasheight[4] = 0xffc00b31;
	hasheight[5] = 0x68581511;
	hasheight[6] = 0x64f98fa7;
	hasheight[7] = 0xbefa4fa4;
	i = -1;
	while (++i < chonk)
	{
		ft_strncpy_unsafe(singlechunk, (*input) + (i * 64), 64);
		process_w(w, singlechunk);
		sha256_round(w, hasheight);
	}
	i = -1;
	while (++i < 7)
		ft_printf("%08x", hasheight[i]);
}
