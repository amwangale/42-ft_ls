/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:27:51 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/28 18:05:55 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		arg_check(char c, t_flags *flags)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
		flags->flag_error = 0;
	else
	{
		flags->flag_error = 1;
		ft_error_flags(c);
	}
}

int		arg_parse_flags(t_flags *flags, const char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] && (argv[i][0] == '-'))
	{
		j = 1;
		while (argv[i][j])
		{
			arg_check(argv[i][j], flags);
			if (argv[i][j] == 'l')
				flags->flag_l = 1;
			if (argv[i][j] == 'R')
				flags->flag_R = 1;
			if (argv[i][j] == 'a')
				flags->flag_a = 1;
			if (argv[i][j] == 'r')
				flags->flag_r = 1;
			if (argv[i][j] == 't')
				flags->flag_t = 1;
			j++;
		}
		i++;
	}
	return (i);
}
