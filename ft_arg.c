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

static void		ft_arg_check(char c, t_flags *flags)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
		flags->flag_error = 0;
	else
	{
		flags->flag_error = 1;
		ft_error_flags(c);
	}
}

int		ft_arg_parse_flags(t_flags *flags, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] && (argv[i][0] == '-'))
	{
		j = 1;
		while (argv[i][j])
		{
			ft_arg_check(argv[i][j], flags);
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

t_uint ft_arg_exist_dir_file(char *name)
{
    t_stat *file_stat;

    if (!(file_stat = (t_stat*)malloc(sizeof(t_stat))))
        ft_exit();
    if (stat(name, file_stat) == -1)
        return (0);
    else if (S_ISDIR(file_stat->st_mode))
        return (1);
    else if (S_ISREG(file_stat->st_mode))
        return (2);
    return (0);
}
/*
t_list_ls *ft_arg_parse_dir_file(char *arg_name_dir)
{
	// DIR *dir;
    // struct dirent   *ent;
    t_list_ls       *lst;
    t_stat          *buf_stat;

    if (!(lst = ft_lst_create()))
        return (NULL);
    lst = NULL;

    if (!(buf_stat = (t_stat*)malloc(sizeof(t_stat))))
        ft_exit();
    if (ft_arg_exist_dir_file(arg_name_dir) == 0)
        ft_error(arg_name_dir);
    else if (ft_arg_exist_dir_file(arg_name_dir) == 1)
    {
		stat(arg_name_dir, buf_stat);
        lst = ft_add_elem(lst, arg_name_dir, NULL, buf_stat, 1);
		lst->is_dir = 1;
        return (lst);
    }
    else if (ft_arg_exist_dir_file(arg_name_dir) == 2)
	{
		stat(arg_name_dir, buf_stat);
		lst = ft_add_elem(lst, arg_name_dir, NULL, buf_stat, 0);
		return (lst);
	}
		return (NULL);
}*/
