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
	list->prev = NULL;
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
}
*/
void ft_lst_put(t_list_ls *elem1, t_list_ls *elem2)
{
	elem1->next = elem2;
	elem2->prev = elem1;
}

void ft_lst_put_between(t_list_ls *elem1, t_list_ls *elem2, t_list_ls *elem)
{
	elem1->next = elem;
	elem->prev = elem1;
	elem->next = elem2;
	elem2->prev = elem;
}
/*
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
*/

// void ft_lst_push(t_list **alst, t_list *new)
// {
//
// }
