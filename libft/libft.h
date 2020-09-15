/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:00:55 by bpace             #+#    #+#             */
/*   Updated: 2019/10/06 20:30:44 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/srcs/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;

char				*ft_itoa(int n);
void				ft_putnbr(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putchar(char c);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
char				*ft_strcap(char *temp);
char				*ft_strlow(char *temp);
char				*ft_strnew(size_t size);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
char				*ft_strtrim(char const *s);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strdup(const char *src);
void				ft_putchar_fd(char c, int fd);
long long			ft_atolonglong(const char *str);
int					ft_list_size(t_list *begin_list);
char				*ft_strchr(const char *s, int c);
t_list				*ft_list_last(t_list *begin_list);
char				*ft_strcat(char *dest, char *src);
char				*ft_strrchr(const char *s, int c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strstr(char *str, char *to_find);
char				**ft_strsplit(char const *s, char c);
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_strndup(const char *s1, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_foreach(int *tab, int length, void (*f)(int));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				*ft_strncat(char *dest, const char *src, int nb);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
char				*ft_strnstr(char *str, char *to_find, size_t len);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_list_push_back(t_list **begin_list, void *data,
					size_t content_size);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n);
void				*ft_memcpy(void *restrict dst,
					const void *restrict src, size_t n);

#endif
