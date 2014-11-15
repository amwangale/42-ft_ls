/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:20:52 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/15 21:57:08 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char const *argv[])
{
	t_flags *flags;
	if (argc == 1)
		ft_ls(".");

	if(!(flags = (t_flags*)malloc(sizeof(t_flags) * 1)))
		return (-1);
	flags = argv_parse(argc, argv, flags);
	ft_putstr("Flag");
	if (flags->flag_l == 1)
		ft_putstr(" -l");
	if (flags->flag_R == 1)
		ft_putstr(" -R");
	if (flags->flag_a == 1)
		ft_putstr(" -a");
	if (flags->flag_r == 1)
		ft_putstr(" -r");
	if (flags->flag_t == 1)
		ft_putstr(" -t");

	return (0);
}

t_flags	*argv_parse(int argc, const char **argv, t_flags *flags)
{
	int		i;
	int		j;

	i = 1;
	set_flags(flags);
	while ((i < argc) && (argv[i][0] == '-'))
	{
		j = 0;
		while (argv[i][j])
		{
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
	return (flags);
}

void	set_flags(t_flags *flags)
{
	flags->flag_l = 0;
	flags->flag_R = 0;
	flags->flag_a = 0;
	flags->flag_r = 0;
	flags->flag_t = 0;
}
