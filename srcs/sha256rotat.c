/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256rotat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 00:16:52 by bpace             #+#    #+#             */
/*   Updated: 2019/10/07 01:48:04 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

u_int32_t	rr(u_int32_t x, u_int32_t c)
{
	return ((x >> c) | (x << (32 - c)));
}

void		compress(u_int32_t *w, u_int32_t *hash)
{
	int			i;
	u_int32_t	temp1;
	u_int32_t	temp2;

	i = -1;
	while (++i < 64)
	{
		temp1 = hash[7] +
		((rr(hash[4], 6)) ^ (rr(hash[4], 11)) ^ (rr(hash[4], 25))) +
		((hash[4] & hash[5]) ^ ((~(hash[4])) & hash[6])) + g_sha256k[i] + w[i];
		temp2 = ((rr(hash[0], 2)) ^ (rr(hash[0], 13)) ^ (rr(hash[0], 22))) +
		((hash[0] & hash[1]) ^ (hash[0] & hash[2]) ^ (hash[1] & hash[2]));
		hash[7] = hash[6];
		hash[6] = hash[5];
		hash[5] = hash[4];
		hash[4] = hash[3] + temp1;
		hash[3] = hash[2];
		hash[2] = hash[1];
		hash[1] = hash[0];
		hash[0] = temp1 + temp2;
	}
}
