/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 16:21:18 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/29 16:21:20 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_ls *ft_add_elem(t_list_ls *lst, char *name, char *path, t_stat *st)
{
    t_list_ls *elem;

    if (!(elem = ft_lst_create()))
        return (NULL);
    elem->name = ft_strdup(name);
    elem->path = ft_strdup(path);
    elem->is_dir = 0;
    elem->st = st;
    if (lst)
        ft_lst_put(lst, elem);
    lst = elem;
    return (lst);
}

void ft_ls_start(int argc, const char *argv[])
{
    int		nb_arg;
    t_flags	*flags;
    t_list_ls *lst_arg;

    lst_arg = NULL;
    if(!(flags = (t_flags*)malloc(sizeof(t_flags) * 1)))
        return (-1);

    nb_arg = ft_arg_parse_flags(flags, argv);

    if (!(lst_arg = ft_lst_create()))
        return ;
    while (nb_arg < argc)
    {
        lst_arg = ft_add_elem(ft_read_arg((char*)argv[nb_arg]))
        nb_arg++;
    }
}

void ft_read_arg(char *arg_name_dir)
{
    DIR *dir;
    struct dirent   *ent;
    t_list_ls       *lst;
    t_stat          *buf_stat;

    if (!(lst = ft_lst_create()))
        return ;
    lst = NULL;

    if (ft_arg_exist_dir_file(arg_name_dir) == 0)
        ft_error(arg_name_dir);
    else if (ft_arg_exist_dir_file(arg_name_dir) == 1)
    {
        if (!(dir = opendir(arg_name_dir)))
            return ;
        while ((ent = readdir(dir)))
        {
            // ft_putnbr(ent->d_type);
            // ft_putstr("\n");
            if (!(buf_stat = (t_stat*)malloc(sizeof(struct stat))))
                ft_exit();
            stat(ent->d_name, buf_stat);
            lst = ft_add_elem(lst, ent->d_name, arg_name_dir, buf_stat);
            // ft_putstr(ent->d_name);
            // ft_putstr("\n");
        }
    }
    else if (ft_arg_exist_dir_file(arg_name_dir) == 2)
        ft_putendl("File");
        // puts(lst->name);

    while (lst->prev)
    {
        // puts(lst->name);
        lst = lst->prev;
    }
    while (lst->next)
    {
        puts(lst->path);
        puts(lst->name);
        lst = lst->next;
    }
}
