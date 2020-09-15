/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:18:49 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:34:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

size_t		getfull_len(char *input)
{
	size_t		ans;

	ans = ft_strlen(input);
	ans++;
	while (ans % (512 / 8) != (448 / 8))
		ans++;
	ans += (64 / 8);
	return (ans);
}

size_t		padding(char **input)
{
	size_t		og_len;
	size_t		full_len;
	char		*padded;
	char		*place_len;
	u_int64_t	*put_len;

	og_len = ft_strlen(*input);
	full_len = getfull_len(*input);
	padded = ft_memalloc(full_len);
	ft_strcpy(padded, *input);
	padded[og_len] = (char)(-128);
	place_len = padded + full_len - 8;
	put_len = (u_int64_t *)place_len;
	*put_len = (u_int64_t)(og_len * 8);
	*input = padded;
	return (full_len / (512 / 8));
}

void		md5_round(char *singlechunk, u_int32_t *hashfour)
{
	u_int32_t	newhashfour[4];

	newhashfour[0] = hashfour[0];
	newhashfour[1] = hashfour[1];
	newhashfour[2] = hashfour[2];
	newhashfour[3] = hashfour[3];
	fghi((u_int32_t *)singlechunk, newhashfour);
	hashfour[0] += newhashfour[0];
	hashfour[1] += newhashfour[1];
	hashfour[2] += newhashfour[2];
	hashfour[3] += newhashfour[3];
}

u_int32_t	endianness(u_int32_t hashi)
{
	u_int32_t	mask;
	u_int32_t	ret;

	mask = 0 | (hashi >> 24);
	ret = 0 | mask;
	mask = 0 | (hashi << 24);
	ret = ret | mask;
	mask = 0b00000000111111110000000000000000 & hashi;
	ret = ret | (mask >> 8);
	mask = 0b00000000000000001111111100000000 & hashi;
	ret = ret | (mask << 8);
	return (ret);
}

void		md5(char **input)
{
	u_int32_t	hashfour[4];
	size_t		chonk;
	char		singlechunk[64];
	size_t		i;

	chonk = padding(input);
	hashfour[0] = 0x67452301;
	hashfour[1] = 0xefcdab89;
	hashfour[2] = 0x98badcfe;
	hashfour[3] = 0x10325476;
	i = -1;
	while (++i < chonk)
	{
		ft_strncpy_unsafe(singlechunk, (*input) + (i * 64), 64);
		md5_round(singlechunk, hashfour);
	}
	i = -1;
	while (++i < 4)
		ft_printf("%08x", endianness(hashfour[i]));
}
