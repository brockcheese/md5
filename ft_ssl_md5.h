/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:11:45 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:27:59 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include <fcntl.h>
# include "libft/libft.h"

# define F(B, C, D) (((B) & (C)) | (~(B) & (D)))
# define G(B, C, D) (((B) & (D)) | ((C) & ~(D)))
# define H(B, C, D) ((B) ^ (C) ^ (D))
# define I(B, C, D) ((C) ^ (B | ~(D)))

typedef struct			s_exec
{
	char				*name;
	void				(*algo)(char **);
}						t_exec;

typedef struct			s_data
{
	int					i;
	int					p;
	int					q;
	int					r;
	int					s;
	char				*stdin;
	char				*alg;
}						t_data;

extern t_exec			g_algos[];
extern u_int32_t		g_k[64];
extern u_int32_t		g_r[64];
extern u_int32_t		g_sha256k[64];
extern u_int64_t		g_sha512k[80];

void					md5(char **input);
void					sha224(char **input);
void					sha256(char **input);
void					sha384(char **input);
void					sha512(char **input);
size_t					padding(char **input);
char					*getstdin(const int fd);
size_t					getfull_len(char *input);
u_int32_t				endianness(u_int32_t hashi);
size_t					sha256padding(char **input);
size_t					sha512padding(char **input);
u_int32_t				rr(u_int32_t x, u_int32_t c);
u_int64_t				endianness64(u_int64_t hashi);
void					execute(char *str, char *alg);
u_int64_t				rr512(u_int64_t x, u_int64_t c);
void					freeargv(char **argv, int argcheck);
void					compress(u_int32_t *w, u_int32_t *hash);
void					compress512(u_int64_t *w, u_int64_t *hash);
void					process_w(u_int32_t *w, char *singlechunk);
void					fghi(u_int32_t *singlechunk, u_int32_t *hash);
void					process_w512(u_int64_t *w, char *singlechunk);
int						errorcheck(int argc, char **argv, t_data *data);
void					sha256_round(u_int32_t *w, u_int32_t *hasheight);
void					sha512_round(u_int64_t *w, u_int64_t *hasheight);
char					*ft_strncpy_unsafe(char *dest, char *src,
							unsigned int n);

#endif
