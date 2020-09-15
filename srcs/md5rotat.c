/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5rotat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 01:02:19 by bpace             #+#    #+#             */
/*   Updated: 2019/10/07 01:23:31 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

u_int32_t	leftrotate(u_int32_t x, u_int32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

void		ffgghhii(int i, int *f, int *g, u_int32_t *hash)
{
	if (i >= 48)
	{
		*f = I(hash[1], hash[2], hash[3]);
		*g = ((7 * i) % 16);
	}
	else if (i >= 32)
	{
		*f = H(hash[1], hash[2], hash[3]);
		*g = ((3 * i) + 5) % 16;
	}
	else if (i >= 16)
	{
		*f = G(hash[1], hash[2], hash[3]);
		*g = ((5 * i) + 1) % 16;
	}
	else
	{
		*f = F(hash[1], hash[2], hash[3]);
		*g = i;
	}
}

void		fghi(u_int32_t *singlechunk, u_int32_t *hash)
{
	int		i;
	int		f;
	int		g;

	i = -1;
	while (++i < 64)
	{
		ffgghhii(i, &f, &g, hash);
		f += hash[0] + g_k[i] + singlechunk[g];
		hash[0] = hash[3];
		hash[3] = hash[2];
		hash[2] = hash[1];
		hash[1] += leftrotate(f, g_r[i]);
	}
}
