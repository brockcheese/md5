/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:10:53 by bpace             #+#    #+#             */
/*   Updated: 2019/10/16 19:37:05 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void		printthatshit(t_data *data, char **argv, char *str, int s)
{
	if (data->q == 0 && data->r == 0)
	{
		ft_printf("%s (", ft_strcap(data->alg));
		if (s == 1)
			ft_printf("\"%s\"", argv[data->i]);
		else
			ft_printf("%s", argv[data->i]);
		ft_printf(") = ");
	}
	execute(str, ft_strlow(data->alg));
	if (data->q == 0 && data->r == 1)
	{
		if (s == 1)
			ft_printf(" \"%s\"", argv[data->i]);
		else
			ft_printf(" %s", argv[data->i]);
	}
	ft_printf("\n");
}

void		checkflags(t_data *data, char **argv)
{
	while (argv[++(data->i)] && argv[data->i][0] == '-')
	{
		if (!ft_strcmp(argv[data->i], "-p"))
		{
			data->p = 1;
			data->stdin = (data->stdin == NULL) ? getstdin(0) : data->stdin;
			ft_printf("%s", data->stdin);
			execute(data->stdin, ft_strlow(data->alg));
			ft_printf("\n");
			free(data->stdin);
			data->stdin = NULL;
		}
		if (!ft_strcmp(argv[data->i], "-q"))
			data->q = 1;
		if (!ft_strcmp(argv[data->i], "-r"))
			data->r = 1;
		if (!ft_strcmp(argv[data->i], "-s"))
		{
			data->s = 1;
			printthatshit(data, argv, argv[++(data->i)], 1);
		}
	}
}

int			initialize(t_data *data)
{
	data->p = 0;
	data->q = 0;
	data->r = 0;
	data->s = 0;
	data->stdin = NULL;
	return (1);
}

void		eachfile(char **argv, t_data *data)
{
	int		fd;
	char	*stdin;

	fd = open(argv[data->i], O_RDWR);
	if (fd > 0)
	{
		stdin = getstdin(fd);
		printthatshit(data, argv, stdin, 0);
		free(stdin);
	}
	else
		ft_printf("ft_ssl: %s: %s: No such file or directory\n",
		ft_strlow(data->alg), argv[data->i]);
	data->i++;
	close(fd);
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (1);
	if (!errorcheck(argc, argv, data))
		return (1);
	initialize(data);
	checkflags(data, argv);
	if (!argv[data->i] && data->p == 0 && data->s == 0)
	{
		data->stdin = (data->stdin == NULL) ? getstdin(0) : data->stdin;
		execute(data->stdin, ft_strlow(data->alg));
		ft_printf("\n");
		free(data->stdin);
		data->stdin = NULL;
	}
	while (argv[data->i])
		eachfile(argv, data);
	if (argc == 1)
		free(data->alg);
	free(data);
	return (0);
}
