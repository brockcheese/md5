/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 07:07:32 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:28:20 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void		sha384(char **input)
{
	size_t		chonk;
	u_int64_t	hasheight[8];
	char		singlechunk[128];
	size_t		i;
	u_int64_t	w[80];

	chonk = sha512padding(input);
	hasheight[0] = 0xcbbb9d5dc1059ed8;
	hasheight[1] = 0x629a292a367cd507;
	hasheight[2] = 0x9159015a3070dd17;
	hasheight[3] = 0x152fecd8f70e5939;
	hasheight[4] = 0x67332667ffc00b31;
	hasheight[5] = 0x8eb44a8768581511;
	hasheight[6] = 0xdb0c2e0d64f98fa7;
	hasheight[7] = 0x47b5481dbefa4fa4;
	i = -1;
	while (++i < chonk)
	{
		ft_strncpy_unsafe(singlechunk, (*input) + (i * 128), 128);
		process_w512(w, singlechunk);
		sha512_round(w, hasheight);
	}
	i = -1;
	while (++i < 6)
		ft_printf("%016lx", hasheight[i]);
}
