/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:20:52 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/16 19:16:31 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char const *argv[])
{
	// int i;
	t_flags *flags;
	if (argc == 1)
		ft_ls(".");

	if(!(flags = (t_flags*)malloc(sizeof(t_flags) * 1)))
		return (-1);
	flags = arg_parse(argc, argv, flags);
	// ft_putstr("Flag");

	// i = 1;
	// while (i < argc)
		// ft_ls((char*)argv[i]), i++;

	// if (flags->flag_error == 1)
	// 	ft_putstr(" error");
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
