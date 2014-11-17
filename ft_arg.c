/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 14:50:14 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/17 20:15:55 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flags	*arg_parse(int argc, const char **argv, t_flags *flags)
{
	int			i;
	int			j;
	struct stat *file_stat;
	char		*str_error;
	t_arg		*arg;
	t_list_ls	*list;

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
	file_stat = malloc(sizeof(stat));
	// ft_putnbr(argc - i);
	list = ft_lst_d_new();
	if(!(arg = (t_arg*)malloc(sizeof(t_arg) * 1)))
		return (NULL);
	arg->ls_arg = list;
	while ((i < argc))
	{
		// argv[i]
		// ft_putstr(argv[i]);
		// ft_putstr("\t");

		if(stat(argv[i], file_stat) == -1)
		{
			str_error = ft_strnew(ft_strlen(argv[0]) + ft_strlen(argv[i]) + 3);
			ft_strcat(str_error, argv[0]);
			ft_strcat(str_error, ": ");
			ft_strcat(str_error, argv[i]);
			perror(str_error);
		}
		else if (S_ISDIR(file_stat->st_mode))
		{
			ft_putstr("Directories ");
			list = ft_lst_new();
			list->is_dir = 1;
			list->prev = arg->ls_arg;
			ft_lst_add(&(arg->ls_arg), list);
		}
		else if (S_ISREG(file_stat->st_mode))
			ft_putstr("File ");
			list = ft_lst_new();
			list->is_dir = 0;
			list->prev = arg->ls_arg;
			ft_lst_add(&(arg->ls_arg), list);
		// ft_putnbr(file_stat->st_ino);
		// ft_putstr("\t");
		// ft_putnbr(file_stat->st_mode);
		ft_putstr("\n");
		i++;
	}
	while (arg->ls_arg->prev)
	{
		ft_putnbr(arg->ls_arg->is_dir);
		arg->ls_arg = arg->ls_arg->prev;
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
	flags->flag_error = 0;
}
