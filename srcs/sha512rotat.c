/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512rotat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 05:27:54 by bpace             #+#    #+#             */
/*   Updated: 2019/10/07 07:19:12 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

u_int64_t	rr512(u_int64_t x, u_int64_t c)
{
	return ((x >> c) | (x << (64 - c)));
}

void		compress512(u_int64_t *w, u_int64_t *hash)
{
	int			i;
	u_int64_t	temp1;
	u_int64_t	temp2;

	i = -1;
	while (++i < 80)
	{
		temp1 = hash[7] +
		((rr512(hash[4], 14)) ^ (rr512(hash[4], 18)) ^ (rr512(hash[4], 41))) +
		((hash[4] & hash[5]) ^ ((~(hash[4])) & hash[6])) + g_sha512k[i] + w[i];
		temp2 = ((rr512(hash[0], 28)) ^ (rr512(hash[0], 34)) ^
		(rr512(hash[0], 39))) +
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
