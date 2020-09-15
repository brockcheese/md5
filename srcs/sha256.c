/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:07:09 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:34:57 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

u_int64_t	endianness64(u_int64_t hashi)
{
	u_int64_t	mask;
	u_int64_t	ret;

	mask = 0 | (hashi >> 56);
	ret = 0 | mask;
	mask = 0 | (hashi << 56);
	ret = ret | mask;
	mask = 0x00FF000000000000 & hashi;
	ret = ret | (mask >> 40);
	mask = 0x0000FF0000000000 & hashi;
	ret = ret | (mask >> 24);
	mask = 0x000000FF00000000 & hashi;
	ret = ret | (mask >> 8);
	mask = 0x00000000FF000000 & hashi;
	ret = ret | (mask << 8);
	mask = 0x0000000000FF0000 & hashi;
	ret = ret | (mask << 24);
	mask = 0x000000000000FF00 & hashi;
	ret = ret | (mask << 40);
	return (ret);
}

size_t		sha256padding(char **input)
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
	*put_len = endianness64((u_int64_t)(og_len * 8));
	*input = padded;
	return (full_len / (512 / 8));
}

void		sha256_round(u_int32_t *w, u_int32_t *hasheight)
{
	u_int32_t	newhasheight[8];

	newhasheight[0] = hasheight[0];
	newhasheight[1] = hasheight[1];
	newhasheight[2] = hasheight[2];
	newhasheight[3] = hasheight[3];
	newhasheight[4] = hasheight[4];
	newhasheight[5] = hasheight[5];
	newhasheight[6] = hasheight[6];
	newhasheight[7] = hasheight[7];
	compress(w, newhasheight);
	hasheight[0] += newhasheight[0];
	hasheight[1] += newhasheight[1];
	hasheight[2] += newhasheight[2];
	hasheight[3] += newhasheight[3];
	hasheight[4] += newhasheight[4];
	hasheight[5] += newhasheight[5];
	hasheight[6] += newhasheight[6];
	hasheight[7] += newhasheight[7];
}

void		process_w(u_int32_t *w, char *singlechunk)
{
	int			i;
	u_int32_t	s0;
	u_int32_t	s1;

	i = 0;
	while (i < 16)
	{
		w[i] = endianness(((u_int32_t *)(singlechunk))[i]);
		i++;
	}
	while (i < 64)
	{
		s0 = (rr(w[i - 15], 7)) ^ (rr(w[i - 15], 18)) ^ (w[i - 15] >> 3);
		s1 = (rr(w[i - 2], 17)) ^ (rr(w[i - 2], 19)) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void		sha256(char **input)
{
	size_t		chonk;
	u_int32_t	hasheight[8];
	char		singlechunk[64];
	size_t		i;
	u_int32_t	w[64];

	chonk = sha256padding(input);
	hasheight[0] = 0x6a09e667;
	hasheight[1] = 0xbb67ae85;
	hasheight[2] = 0x3c6ef372;
	hasheight[3] = 0xa54ff53a;
	hasheight[4] = 0x510e527f;
	hasheight[5] = 0x9b05688c;
	hasheight[6] = 0x1f83d9ab;
	hasheight[7] = 0x5be0cd19;
	i = -1;
	while (++i < chonk)
	{
		ft_strncpy_unsafe(singlechunk, (*input) + (i * 64), 64);
		process_w(w, singlechunk);
		sha256_round(w, hasheight);
	}
	i = -1;
	while (++i < 8)
		ft_printf("%08x", hasheight[i]);
}
