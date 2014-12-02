/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:24 by ybarbier          #+#    #+#             */
/*   Updated: 2014/11/27 18:07:39 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "./libft/includes/libft.h"

# define TITLE "ft_ls"

typedef unsigned int t_uint;
typedef struct stat	t_stat;

typedef struct 			s_list_ls
{
	char				*name;
	char				*path;
	t_stat				*st;
	t_uint				is_dir;
	// struct s_list_ls	*prev;
	struct s_list_ls	*next;
}						t_list_ls;
/*
typedef struct			s_list_elem
{
	char				*name;
	t_stat				st;
	t_uint				is_dir;
}						t_list_elem;
*/
typedef struct s_flags
{
	t_uint		flag_l;
	t_uint		flag_R;
	t_uint		flag_a;
	t_uint		flag_r;
	t_uint		flag_t;
	t_uint		flag_error;
}				t_flags;

int 			ft_ls_start(int argc, char *argv[]);
void *ft_add_elem(t_list_ls **lst, char *name, char *path, t_stat *st, t_uint dir);
t_list_ls		*ft_lst_create(void);
void 			ft_lst_add_end(t_list_ls **alst, t_list_ls *elem);
void ft_lst_add_sort(t_list_ls **aslt, t_list_ls *elem, int (*f)(t_list_ls *elem1, t_list_ls *elem2));
void ft_lst_put(t_list_ls *elem1, t_list_ls *elem2);
// void			ft_lst_put(t_list_ls *elem1, t_list_ls *elem2);
int ft_sort_name(t_list_ls *elem1, t_list_ls *elem2);

void 			ft_read_arg(char *arg_name_dir);

t_list_ls   	*ft_open_dir(char *name_dir);
void 			ft_lst_read(t_list_ls *lst);



int				ft_arg_parse_flags(t_flags *flags, char **argv);
t_uint 			ft_arg_exist_dir_file(char *name);
t_list_ls 		*ft_arg_parse_dir_file(char *arg_name_dir);

/*Error gestion*/
void 			ft_exit(void);
void 			ft_error(char *str_error);
void 			ft_error_exit(char *str_error);
void 			ft_error_flags(char flag);

/*Linked List*/
// void	ft_lstiter_ls(t_list_ls *lst, void (*f)(t_list_ls *elem));

// void	ft_lst_put_between(t_list_ls *elem1, t_list_ls *elem2, t_list_ls *elem);
// void	ft_lst_put(t_list_ls *elem1, t_list_ls *elem2);
// t_list_elem	*ft_lst_create_elem(char *name, t_stat st);
// t_list	*ft_lst_create(void);
// void		ft_ls(char *name_dir);
// void		set_flags(t_flags *flags);
// t_flags		*arg_parse(int argc, const char **argv, t_flags *flags);
// t_list_ls	*ft_lst_d_new(void);
// t_list_ls	*ft_lst_new(void);
// void	ft_lst_add(t_list_ls **alst, t_list_ls *new);
// void	ft_lst_add_end(t_list_ls **alst, t_list_ls *new);
// void	read_list(t_list_ls **list);

#endif
