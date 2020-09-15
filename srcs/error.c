/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 02:17:03 by bpace             #+#    #+#             */
/*   Updated: 2019/10/15 20:31:18 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

int		printerror(char *alg)
{
	if (ft_strcmp(alg, "md5") && ft_strcmp(alg, "sha256") &&
		ft_strcmp(alg, "sha224") && ft_strcmp(alg, "sha512") &&
		ft_strcmp(alg, "sha384"))
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", alg);
		ft_printf("Standard commands:\n\n");
		ft_printf("Message Digest commands:\nmd5\nsha224\nsha256\nsha384\n");
		ft_printf("sha512\n\n");
		ft_printf("Cipher commands:\n");
		return (0);
	}
	return (1);
}

int		errorcheck(int argc, char **argv, t_data *data)
{
	char	*stdin;

	if (argc == 1)
	{
		ft_printf("FT_SSL> ");
		get_next_line(0, &stdin);
		if (!(printerror(stdin)))
		{
			free(stdin);
			return (0);
		}
		data->alg = stdin;
		data->i = 0;
	}
	if (argc >= 2)
	{
		if (!(printerror(argv[1])))
			return (0);
		data->i = 1;
		data->alg = argv[1];
	}
	return (1);
}
