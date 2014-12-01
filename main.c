/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:50:35 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/28 17:41:50 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char const *argv[])
{

	ft_ls_start(argc, (char**)argv);
	/*
	int		nb_arg;
	t_flags	*flags;

	if(!(flags = (t_flags*)malloc(sizeof(t_flags) * 1)))
		return (-1);

	// lst = NULL;

	nb_arg = arg_parse_flags(flags, argv);

	while (nb_arg < argc)
	{
		ft_read_arg((char*)argv[nb_arg]);
		nb_arg++;
	}*/
/*
	ft_putnbr(argc);
	ft_putchar('\n');
	ft_putnbr(nb_arg);


	if (flags->flag_error == 1)
		ft_putstr(" error");
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
*/
	return (0);
}
