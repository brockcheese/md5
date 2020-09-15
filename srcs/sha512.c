/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 04:50:49 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:35:05 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

size_t		getfull_lensha(char *input)
{
	size_t		ans;

	ans = ft_strlen(input);
	ans++;
	while (ans % (1024 / 8) != (960 / 8))
		ans++;
	ans += (64 / 8);
	return (ans);
}

size_t		sha512padding(char **input)
{
	size_t		og_len;
	size_t		full_len;
	char		*padded;
	char		*place_len;
	u_int64_t	*put_len;

	og_len = ft_strlen(*input);
	full_len = getfull_lensha(*input);
	padded = ft_memalloc(full_len);
	ft_strcpy(padded, *input);
	padded[og_len] = (char)(-128);
	place_len = padded + full_len - 8;
	put_len = (u_int64_t *)place_len;
	*put_len = endianness64((u_int64_t)(og_len * 8));
	*input = padded;
	return (full_len / (1024 / 8));
}

void		sha512_round(u_int64_t *w, u_int64_t *hasheight)
{
	u_int64_t	newhasheight[8];

	newhasheight[0] = hasheight[0];
	newhasheight[1] = hasheight[1];
	newhasheight[2] = hasheight[2];
	newhasheight[3] = hasheight[3];
	newhasheight[4] = hasheight[4];
	newhasheight[5] = hasheight[5];
	newhasheight[6] = hasheight[6];
	newhasheight[7] = hasheight[7];
	compress512(w, newhasheight);
	hasheight[0] += newhasheight[0];
	hasheight[1] += newhasheight[1];
	hasheight[2] += newhasheight[2];
	hasheight[3] += newhasheight[3];
	hasheight[4] += newhasheight[4];
	hasheight[5] += newhasheight[5];
	hasheight[6] += newhasheight[6];
	hasheight[7] += newhasheight[7];
}

void		process_w512(u_int64_t *w, char *singlechunk)
{
	int			i;
	u_int64_t	s0;
	u_int64_t	s1;

	i = 0;
	while (i < 16)
	{
		w[i] = endianness64(((u_int64_t *)(singlechunk))[i]);
		i++;
	}
	while (i < 80)
	{
		s0 = (rr512(w[i - 15], 1)) ^ (rr512(w[i - 15], 8)) ^ (w[i - 15] >> 7);
		s1 = (rr512(w[i - 2], 19)) ^ (rr512(w[i - 2], 61)) ^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void		sha512(char **input)
{
	size_t		chonk;
	u_int64_t	hasheight[8];
	char		singlechunk[128];
	size_t		i;
	u_int64_t	w[80];

	chonk = sha512padding(input);
	hasheight[0] = 0x6a09e667f3bcc908;
	hasheight[1] = 0xbb67ae8584caa73b;
	hasheight[2] = 0x3c6ef372fe94f82b;
	hasheight[3] = 0xa54ff53a5f1d36f1;
	hasheight[4] = 0x510e527fade682d1;
	hasheight[5] = 0x9b05688c2b3e6c1f;
	hasheight[6] = 0x1f83d9abfb41bd6b;
	hasheight[7] = 0x5be0cd19137e2179;
	i = -1;
	while (++i < chonk)
	{
		ft_strncpy_unsafe(singlechunk, (*input) + (i * 128), 128);
		process_w512(w, singlechunk);
		sha512_round(w, hasheight);
	}
	i = -1;
	while (++i < 8)
		ft_printf("%016lx", hasheight[i]);
}
