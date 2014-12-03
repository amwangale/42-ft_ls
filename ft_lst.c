/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:33:40 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/27 18:10:24 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list_ls	*ft_lst_create(void)
{
	t_list_ls	*list;

	list = NULL;
	if (!(list = (t_list_ls*)malloc(sizeof(t_list_ls))))
		return (NULL);
	list->name = NULL;
	list->path = NULL;
	list->st = NULL;
	list->next = NULL;
	// list->prev = NULL;
	list->is_dir = 0;
	return (list);
}
/*
t_list_elem *ft_lst_create_elem(char *name, t_stat st)
{
	t_list_elem	*elem;

	if (!(elem = (t_list_elem*)malloc(sizeof(elem) * 1)))
		return (NULL);
	elem->name = name;
	elem->st = st;
	return (elem);
}*/
/*
void	ft_lst_add(t_list **alst, t_list *new)
{
	if (alst && *alst && new)
	{
		new->next = (*alst);
		*alst = new;
	}
}*/

int ft_sort_name(t_list_ls *elem1, t_list_ls *elem2)
{
	return (ft_strcmp(elem1->name, elem2->name));
}

void ft_lst_add_end(t_list_ls **alst, t_list_ls *elem)
{
	t_list_ls *tmp;

	tmp = *alst;
	if (!(*alst))
		*alst = elem;
 	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

void ft_lst_add_sort(t_list_ls **alst, t_list_ls *elem, int (*f)(t_list_ls *elem1, t_list_ls *elem2))
{
	t_list_ls *tmp_lst;
	t_list_ls *tmp_prev;

	tmp_lst = *alst;
	if (!(*alst))
		*alst = elem;
 	else
	{
		while ((*f)(elem, tmp_lst) > 0 && tmp_lst->next)
		{
			// ft_putendl(tmp_lst->name);
			tmp_prev = tmp_lst;
			tmp_lst = tmp_lst->next;
		}
		if (tmp_lst->next)
		{
			ft_putendl("IN")
			ft_lst_put(tmp_prev, elem);

		}
		else
		{
			tmp_lst->next = elem;
		}
			// ft_lst_put(tmp_prev, elem);

		// if (!(tmp_lst->next))
			// ft_lst_put(elem, tmp_lst);
		// if(!tmp_lst)
		// {
			// ft_putendl("NULL");
			// tmp_lst = tmp_prev;
		// }

		// ft_putendl(tmp_prev->name);
		//if ((*f)(tmp_lst, elem) > 0)
		//else
			//ft_lst_put(elem, tmp_lst);
		// while (tmp_lst->next)
		// 	tmp_lst = tmp_lst->next;
	}
}

void ft_lst_put(t_list_ls *elem1, t_list_ls *elem2)
{
	elem2->next = elem1->next;
	elem1->next = elem2;
}

/*
void ft_lst_put(t_list_ls *elem1, t_list_ls *elem2)
{
	elem1->next = elem2;
	elem2->prev = elem1;
}
*/
/*
void ft_lst_put_between(t_list_ls *elem1, t_list_ls *elem2, t_list_ls *elem)
{
	elem1->next = elem;
	elem->prev = elem1;
	elem->next = elem2;
	elem2->prev = elem;
}
*/
void	ft_lstiter_ls(t_list_ls *lst, void (*f)(t_list_ls *elem))
{
	if (lst && (f))
	{
		while (lst)
		{
			(*f)(lst);
			lst = lst->next;
		}
	}
}

// void ft_lst_push(t_list **alst, t_list *new)
// {
//
// }
