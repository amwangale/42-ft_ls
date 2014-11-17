/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:15 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/17 20:07:21 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *name_dir)
{
	DIR *dir;
	struct dirent *ent;

	// stat(name_dir, buf);
	
	if ((dir = opendir(name_dir)))
	{
		while ((ent = readdir(dir)))
		{
			ft_putnbr(ent->d_ino);
			ft_putstr("\t");
			ft_putnbr(ent->d_type);
			ft_putstr("\t");
			ft_putstr(ent->d_name);
			ft_putstr("\n");
		}
	}
	closedir(dir);
}

t_list_ls	*ft_lst_d_new(void)
{
	t_list_ls	*list;

	if (!(list = (t_list_ls*)ft_memalloc(sizeof(t_list_ls))))
		return (NULL);
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

t_list_ls	*ft_lst_new(void)
{
	t_list_ls	*list;

	if (!(list = (t_list_ls*)ft_memalloc(sizeof(t_list_ls))))
		return (NULL);
	list->next = NULL;
	return (list);
}

void	ft_lst_add(t_list_ls **alst, t_list_ls *new)
{
	if (alst && *alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
